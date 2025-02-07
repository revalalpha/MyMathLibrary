#ifndef MYLIB_VECTOR_ND_H
#define MYLIB_VECTOR_ND_H

#include "MyArray.h"

namespace mylib {

    template <typename T>
    class VectorND {
    public:
        VectorND(size_t dimensions) : m_data(dimensions) {}

        VectorND(const std::initializer_list<T>& values) : m_data(values.size()) {
            size_t i = 0;
            for (const T& val : values)
                m_data[i++] = val;
        }

        size_t size() const {
            return m_data.getSize();
        }

        T& operator[](size_t index) {
            return m_data[index];
        }

        const T& operator[](size_t index) const {
            return m_data[index];
        }

        T dot(const VectorND& other) const {
            if (size() != other.size())
                throw "Dimension mismatch";
            T result = 0;
            for (size_t i = 0; i < size(); ++i)
                result += m_data[i] * other[i];
            return result;
        }

        VectorND cross(const VectorND& other) const {
            if (size() != 3 || other.size() != 3)
                throw "Cross product only for 3D vectors";
            return VectorND({
                m_data[1] * other[2] - m_data[2] * other[1],
                m_data[2] * other[0] - m_data[0] * other[2],
                m_data[0] * other[1] - m_data[1] * other[0]
                });
        }

        T norm() const {
            return std::sqrt(dot(*this));
        }

        void normalize() {
            T n = norm();
            if (n == 0)
                throw "Cannot normalize zero vector";
            for (size_t i = 0; i < size(); ++i)
                m_data[i] /= n;
        }

        VectorND operator+(const VectorND& other) const {
            if (size() != other.size())
                throw "Dimension mismatch";
            VectorND result(size());
            for (size_t i = 0; i < size(); ++i)
                result[i] = m_data[i] + other[i];
            return result;
        }

        VectorND operator-(const VectorND& other) const {
            if (size() != other.size())
                throw "Dimension mismatch";
            VectorND result(size());
            for (size_t i = 0; i < size(); ++i)
                result[i] = m_data[i] - other[i];
            return result;
        }

        VectorND operator*(T scalar) const {
            VectorND result(size());
            for (size_t i = 0; i < size(); ++i)
                result[i] = m_data[i] * scalar;
            return result;
        }

        VectorND operator/(T scalar) const {
            if (scalar == 0)
                throw "Cannot divide by zero";
            VectorND result(size());
            for (size_t i = 0; i < size(); ++i)
                result[i] = m_data[i] / scalar;
            return result;
        }

        class Iterator {
        public:
            Iterator(T* ptr) : m_ptr(ptr) {}
            Iterator& operator++() {
                ++m_ptr;
                return *this;
            }
            T& operator*() {
                return *m_ptr;
            }
            bool operator!=(const Iterator& other) const {
                return m_ptr != other.m_ptr;
            }
        private:
            T* m_ptr;
        };

        Iterator begin() {
            return Iterator(&m_data[0]);
        }

        Iterator end() {
            return Iterator(&m_data[size()]);
        }

        VectorND reverse() const {
            VectorND result(size());
            for (size_t i = 0; i < size(); ++i)
                result[i] = m_data[size() - 1 - i];
            return result;
        }

        VectorND<T> projection(const VectorND<T>& other) const {
            T dotProduct = this->dot(other);
            T otherNormSquared = other.dot(other);
            return other * (dotProduct / otherNormSquared);
        }

    private:
        Array<T> m_data;
    };

} // namespace mylib

#endif
