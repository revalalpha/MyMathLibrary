#ifndef MYLIB_MATRIX_H
#define MYLIB_MATRIX_H

#include "MyArray.h"

namespace mylib {

    template <typename T>
    class Matrix {
    private:
        size_t m_size;
        Array<T> m_data;

    public:
        Matrix(size_t size) : m_size(size), m_data(size* size) {}

        T& operator()(size_t row, size_t col) {
            if (row >= m_size || col >= m_size)
                throw "Index out of range";
            return m_data[row * m_size + col];
        }

        const T& operator()(size_t row, size_t col) const {
            if (row >= m_size || col >= m_size)
                throw "Index out of range";
            return m_data[row * m_size + col];
        }

        size_t size() const {
            return m_size;
        }

        void fill(const T& value) {
            m_data.fill(value);
        }

        Matrix operator+(const Matrix& other) const {
            if (m_size != other.m_size)
                throw "Matrix sizes do not match";
            Matrix result(m_size);
            for (size_t i = 0; i < m_size * m_size; ++i)
                result.m_data[i] = m_data[i] + other.m_data[i];
            return result;
        }

        Matrix operator*(const Matrix& other) const {
            if (m_size != other.m_size)
                throw "Matrix sizes do not match";
            Matrix result(m_size);
            for (size_t i = 0; i < m_size; ++i) {
                for (size_t j = 0; j < m_size; ++j) {
                    result(i, j) = 0;
                    for (size_t k = 0; k < m_size; ++k)
                        result(i, j) += (*this)(i, k) * other(k, j);
                }
            }
            return result;
        }

        Matrix transpose() const {
            Matrix result(m_size);
            for (size_t i = 0; i < m_size; ++i) {
                for (size_t j = 0; j < m_size; ++j) {
                    result(j, i) = (*this)(i, j);
                }
            }
            return result;
        }
    };

} // namespace mylib

#endif // MYLIB_MATRIX_H