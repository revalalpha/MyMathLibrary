#ifndef MYLIB_MATRIX_H
#define MYLIB_MATRIX_H

#include "MyArray.h"
#include "sstream"

namespace mylib {
    /**
     * Represents a square matrix of type T.
     * @tparam T Type of elements in the matrix.
     */
    template <typename T>
    class Matrix {
    public:
        /**
         * Constructor that initializes a matrix of the given size.
         * @param size The size of the matrix (number of rows and columns).
         */
        Matrix(size_t size) : m_size(size), m_data(size* size) {}

        /**
         * Overloads the output stream operator to print the matrix.
         * @param os Output stream.
         * @param mat Matrix to be printed.
         * @return The output stream.
         */
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

        /**
         * Accessor for the matrix element at the given row and column.
         * @param row Row index.
         * @param col Column index.
         * @return Reference to the element at the specified position.
         * @throws "Index out of range" if indices are out of bounds.
         */
        T& operator()(size_t row, size_t col)
        {
            if (row >= m_size || col >= m_size)
                throw "Index out of range";
            return m_data[row * m_size + col];
        }

        /**
         * Const accessor for the matrix element at the given row and column.
         * @param row Row index.
         * @param col Column index.
         * @return Constant reference to the element at the specified position.
         * @throws "Index out of range" if indices are out of bounds.
         */
        const T& operator()(size_t row, size_t col) const
        {
            if (row >= m_size || col >= m_size)
                throw "Index out of range";
            return m_data[row * m_size + col];
        }

        /**
         * Gets the size of the matrix.
         * @return The size (number of rows or columns).
         */
        size_t size() const
        {
            return m_size;
        }

        /**
         * Fills the matrix with the given value.
         * @param value The value to fill the matrix with.
         */
        void fill(const T& value)
        {
            m_data.fill(value);
        }

        /**
         * Retrieves a row of the matrix as an array.
         * @param row The row index.
         * @return Array containing the elements of the row.
         * @throws "Index out of range" if the row index is out of bounds.
         */
        Array<T> getRow(size_t row) const
        {
            if (row >= m_size) throw "Index out of range";
            Array<T> result(m_size);
            for (size_t i = 0; i < m_size; ++i)
                result[i] = (*this)(row, i);
            return result;
        }

        /**
         * Retrieves a column of the matrix as an array.
         * @param col The column index.
         * @return Array containing the elements of the column.
         * @throws "Index out of range" if the column index is out of bounds.
         */
        Array<T> getCol(size_t col) const
        {
            if (col >= m_size) throw "Index out of range";
            Array<T> result(m_size);
            for (size_t i = 0; i < m_size; ++i)
                result[i] = (*this)(i, col);
            return result;
        }

        // Iterators for traversing the matrix.

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

        // Column iterator for iterating over columns.

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

        /**
         * Returns an iterator for the start of a column.
         * @param col The column index.
         * @return Iterator pointing to the first element of the column.
         */
        ColumnIterator colBegin(size_t col)
        {
            return ColumnIterator(&m_data[col], m_size);
        }

        /**
         * Returns an iterator for the end of a column.
         * @param col The column index.
         * @return Iterator pointing past the last element of the column.
         */
        ColumnIterator colEnd(size_t col)
        {
            return ColumnIterator(&m_data[col + m_size * (m_size - 1) + 1], m_size);
        }

        /**
         * Returns a constant iterator for the start of a column.
         * @param col The column index.
         * @return Constant iterator pointing to the first element of the column.
         */
        const ColumnIterator colBegin(size_t col) const
        {
            return ColumnIterator(&m_data[col], m_size);
        }

        /**
         * Returns a constant iterator for the end of a column.
         * @param col The column index.
         * @return Constant iterator pointing past the last element of the column.
         */
        const ColumnIterator colEnd(size_t col) const
        {
            return ColumnIterator(&m_data[col + m_size * (m_size - 1) + 1], m_size);
        }

        // Operator overloads for matrix operations.

        /**
         * Adds two matrices together.
         * @param other The matrix to add.
         * @return A new matrix containing the result.
         * @throws "Matrix sizes do not match" if the matrices have different sizes.
         */
        Matrix operator+(const Matrix& other) const
        {
            if (m_size != other.m_size)
                throw "Matrix sizes do not match";
            Matrix result(m_size);
            for (size_t i = 0; i < m_size * m_size; ++i)
                result.m_data[i] = m_data[i] + other.m_data[i];
            return result;
        }

        /**
         * Subtracts another matrix from this matrix.
         * @param other The matrix to subtract.
         * @return A new matrix containing the result.
         * @throws "Matrix sizes do not match" if the matrices have different sizes.
         */
        Matrix operator-(const Matrix& other) const
        {
            if (m_size != other.m_size)
                throw "Matrix sizes do not match";
            Matrix result(m_size);
            for (size_t i = 0; i < m_size * m_size; ++i)
                result.m_data[i] = m_data[i] - other.m_data[i];
            return result;
        }

        /**
         * Multiplies this matrix by another matrix.
         * @param other The matrix to multiply by.
         * @return A new matrix containing the result.
         * @throws "Matrix sizes do not match" if the matrices have different sizes.
         */
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

        /**
         * Multiplies this matrix by a scalar.
         * @param scalar The scalar to multiply by.
         * @return A new matrix containing the result.
         */
        Matrix operator*(const T& scalar) const
        {
            Matrix result(m_size);
            for (size_t i = 0; i < m_size * m_size; ++i)
                result.m_data[i] = m_data[i] * scalar;
            return result;
        }

        /**
         * Compares two matrices for equality.
         * @param other The matrix to compare to.
         * @return True if the matrices are equal, otherwise false.
         */
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

        /**
         * Transposes the matrix.
         * @return A new matrix containing the transpose.
         */
        Matrix transpose() const
        {
            Matrix result(m_size);
            for (size_t i = 0; i < m_size; ++i)
            {
                for (size_t j = 0; j < m_size; ++j)
                {
                    result(j, i) = (*this)(i, j);
                }
            }
            return result;
        }

        /**
         * Computes the determinant of the matrix.
         * @return The determinant.
         * @throws "Matrix is singular" if the matrix is singular and cannot be inverted.
         */
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

        /**
         * Computes the inverse of the matrix.
         * @return The inverse matrix.
         * @throws "Matrix is singular" if the matrix cannot be inverted.
         */
        Matrix inverse() const
        {
            T det = determinant();
            if (det == 0)
                throw "Matrix is singular and cannot be inverted";

            Matrix adjugate = adjugateMatrix();
            return adjugate * (static_cast<T>(1) / det);
        }

        /**
         * Prints the matrix to the standard output.
         */
        void print() const
        {
            for (size_t i = 0; i < m_size; ++i)
            {
                for (size_t j = 0; j < m_size; ++j)
                    std::cout << m_data[i * m_size + j] << " ";
                std::cout << "\n";
            }
        }

    private:
        size_t m_size;          // Size of the matrix (number of rows/columns).
        Array<T> m_data;        // Data array for storing the elements of the matrix.

        /**
         * Calculates the cofactor matrix.
         * @return A new matrix containing the cofactors.
         */
        Matrix cofactorMatrix() const
        {
            Matrix result(m_size);
            for (size_t i = 0; i < m_size; ++i)
                for (size_t j = 0; j < m_size; ++j)
                    result(i, j) = cofactor(i, j);
            return result;
        }

        /**
         * Computes the cofactor of the element at the given position.
         * @param row The row index.
         * @param col The column index.
         * @return The cofactor value.
         */
        T cofactor(size_t row, size_t col) const
        {
            Matrix minorMatrix = getMinor(row, col);
            return (row + col) % 2 == 0 ? minorMatrix.determinant() : -minorMatrix.determinant();
        }

        /**
         * Gets the minor matrix by removing the specified row and column.
         * @param row The row to exclude.
         * @param col The column to exclude.
         * @return The minor matrix.
         */
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

        /**
         * Computes the adjugate matrix (transpose of cofactor matrix).
         * @return The adjugate matrix.
         */
        Matrix adjugateMatrix() const
        {
            Matrix result(m_size);
            for (size_t i = 0; i < m_size; ++i)
                for (size_t j = 0; j < m_size; ++j)
                    result(i, j) = cofactor(i, j);
            return result.transpose();
        }
    };
}

#endif // MYLIB_MATRIX_H