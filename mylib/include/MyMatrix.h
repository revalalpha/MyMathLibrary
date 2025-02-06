#ifndef MYLIB_MATRIX_H
#define MYLIB_MATRIX_H

#include "MyArray.h"
#include "sstream"

namespace mylib {
    template <typename T>
    class Matrix {
    public:
        Matrix(size_t size) : m_size(size), m_data(size* size) {}

        friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& mat)
        {
            for (size_t i = 0; i < mat.m_size; ++i)
            {
                for (size_t j = 0; j < mat.m_size; ++j)
                    os << mat.m_data[i * mat.m_size + j] << " ";
                os << "\n";
            }
            return os;
        }



        T& operator()(size_t row, size_t col)
        {
            if (row >= m_size || col >= m_size)
                throw "Index out of range";
            return m_data[row * m_size + col];
        }

        const T& operator()(size_t row, size_t col) const
        {
            if (row >= m_size || col >= m_size)
                throw "Index out of range";
            return m_data[row * m_size + col];
        }

        size_t size() const
        {
            return m_size;
        }

        void fill(const T& value)
        {
            m_data.fill(value);
        }

        Array<T> getRow(size_t row) const
        {
            if (row >= m_size) throw "Index out of range";
            Array<T> result(m_size);
            for (size_t i = 0; i < m_size; ++i)
                result[i] = (*this)(row, i);
            return result;
        }

        Array<T> getCol(size_t col) const
        {
            if (col >= m_size) throw "Index out of range";
            Array<T> result(m_size);
            for (size_t i = 0; i < m_size; ++i)
                result[i] = (*this)(i, col);
            return result;
        }

        T* begin()
        { 
            return m_data.data();
        }

        T* end()
        {
            return m_data.data() + (m_size * m_size);
        }

        const T* getBegin() const
        {
            return m_data.data();
        }

        const T* getEnd() const
        {
            return m_data.data() + (m_size * m_size);
        }

        T* rowBegin(size_t row)
        {
            return &m_data[row * m_size];
        }

        T* rowEnd(size_t row)
        {
            return &m_data[row * m_size + m_size];
        }

        const T* rowBegin(size_t row) const
        {
            return &m_data[row * m_size];
        }

        const T* rowEnd(size_t row) const
        { 
            return &m_data[row * m_size + m_size];
        }

        class ColumnIterator {
        public:
            ColumnIterator(T* ptr, size_t stride) : m_ptr(ptr), m_stride(stride) {}

            T& operator*() 
            {
                return *m_ptr; 
            }

            ColumnIterator& operator++()
            { 
                m_ptr += m_stride; return *this; 
            }

            ColumnIterator operator++(int) 
            {
                ColumnIterator tmp = *this; ++(*this);
                return tmp; 
            }

            bool operator!=(const ColumnIterator& other) const 
            { 
                return m_ptr != other.m_ptr; 
            }

        private:
            T* m_ptr;
            size_t m_stride;
        };

        ColumnIterator colBegin(size_t col)
        { 
            return ColumnIterator(&m_data[col], m_size); 
        }

        ColumnIterator colEnd(size_t col) 
        {
            return ColumnIterator(&m_data[col + m_size * (m_size - 1) + 1], m_size); 
        }
        const ColumnIterator colBegin(size_t col) const 
        {
            return ColumnIterator(&m_data[col], m_size);
        }

        const ColumnIterator colEnd(size_t col) const 
        { 
            return ColumnIterator(&m_data[col + m_size * (m_size - 1) + 1], m_size); 
        }

        Matrix operator+(const Matrix& other) const
        {
            if (m_size != other.m_size)
                throw "Matrix sizes do not match";
            Matrix result(m_size);
            for (size_t i = 0; i < m_size * m_size; ++i)
                result.m_data[i] = m_data[i] + other.m_data[i];
            return result;
        }

        Matrix operator-(const Matrix& other) const
        {
            if (m_size != other.m_size)
                throw "Matrix sizes do not match";
            Matrix result(m_size);
            for (size_t i = 0; i < m_size * m_size; ++i)
                result.m_data[i] = m_data[i] - other.m_data[i];
            return result;
        }

        Matrix operator*(const Matrix& other) const
        {
            if (m_size != other.m_size)
                throw "Matrix sizes do not match";
            Matrix result(m_size);
            for (size_t i = 0; i < m_size; ++i)
            {
                for (size_t j = 0; j < m_size; ++j)
                {
                    result(i, j) = 0;
                    for (size_t k = 0; k < m_size; ++k)
                        result(i, j) += (*this)(i, k) * other(k, j);
                }
            }
            return result;
        }

        Matrix operator*(const T& scalar) const
        {
            Matrix result(m_size);
            for (size_t i = 0; i < m_size * m_size; ++i)
                result.m_data[i] = m_data[i] * scalar;
            return result;
        }

        bool operator==(const Matrix& other) const
        {
            if (m_size != other.m_size)
                return false;
            for (size_t i = 0; i < m_size * m_size; ++i)
            {
                if (m_data[i] != other.m_data[i])
                    return false;
            }
            return true;
        }

        Matrix transpose() const
        {
            Matrix result(m_size);
            for (size_t i = 0; i < m_size; ++i)
                for (size_t j = 0; j < m_size; ++j)
                    result(j, i) = (*this)(i, j);
            return result;
        }

        T determinant() const
        {
            if (m_size == 1)
                return (*this)(0, 0);
            if (m_size == 2)
                return (*this)(0, 0) * (*this)(1, 1) - (*this)(0, 1) * (*this)(1, 0);

            T det = 0;
            for (size_t i = 0; i < m_size; ++i)
                det += (*this)(0, i) * cofactor(0, i);
            return det;
        }

        Matrix inverse() const
        {
            T det = determinant();
            if (det == 0)
                throw "Matrix is singular and cannot be inverted";

            Matrix adjugate = adjugateMatrix();
            return adjugate * (static_cast<T>(1) / det);
        }

        void print() const {
            for (size_t i = 0; i < m_size; ++i) {
                for (size_t j = 0; j < m_size; ++j)
                    std::cout << m_data[i * m_size + j] << " ";
                std::cout << "\n";
            }
        }

    private:
        size_t m_size;
        Array<T> m_data;

        Matrix cofactorMatrix() const
        {
            Matrix result(m_size);
            for (size_t i = 0; i < m_size; ++i)
                for (size_t j = 0; j < m_size; ++j)
                    result(i, j) = cofactor(i, j);
            return result;
        }

        T cofactor(size_t row, size_t col) const
        {
            Matrix minorMatrix = getMinor(row, col);
            return (row + col) % 2 == 0 ? minorMatrix.determinant() : -minorMatrix.determinant();
        }

        Matrix getMinor(size_t row, size_t col) const
        {
            Matrix minor(m_size - 1);
            size_t minorRow = 0;
            for (size_t i = 0; i < m_size; ++i)
            {
                if (i == row)
                    continue;
                size_t minorCol = 0;
                for (size_t j = 0; j < m_size; ++j)
                {
                    if (j == col)
                        continue;
                    minor(minorRow, minorCol++) = (*this)(i, j);
                }
                ++minorRow;
            }
            return minor;
        }

        Matrix adjugateMatrix() const
        {
            Matrix result(m_size);
            for (size_t i = 0; i < m_size; ++i)
                for (size_t j = 0; j < m_size; ++j)
                    result(i, j) = cofactor(i, j);
            return result.transpose();
        }
    };

} // namespace mylib

#endif // MYLIB_MATRIX_H