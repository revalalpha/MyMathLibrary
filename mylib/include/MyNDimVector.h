#ifndef MYLIB_VECTOR_ND_H
#define MYLIB_VECTOR_ND_H

#include "MyArray.h"

namespace mylib {
    template <typename T>
    class VectorND {
    public:
        VectorND(size_t dimensions) : m_data(dimensions) {}

        VectorND(const std::initializer_list<T>& values) : m_data(values.size())
        {
            size_t i = 0;
            for (const T& val : values)
                m_data[i++] = val;
        }

        size_t size() const 
        { 
            return m_data.getSize();
        }

        T& operator[](size_t index)
        { 
            return m_data[index]; 
        }

        const T& operator[](size_t index) const
        { 
            return m_data[index];
        }

        T dot(const VectorND& other) const
        {
            if (size() != other.size()) 
                throw "Dimension mismatch";
            T result = 0;
            for (size_t i = 0; i < size(); ++i)
                result += m_data[i] * other[i];
            return result;
        }

        VectorND cross(const VectorND& other) const
        {
            if (size() != 3 || other.size() != 3)
                throw "Cross product only for 3D vectors";
            return VectorND({
                m_data[1] * other[2] - m_data[2] * other[1],
                m_data[2] * other[0] - m_data[0] * other[2],
                m_data[0] * other[1] - m_data[1] * other[0]
                });
        }

        T norm() const
        {
            return std::sqrt(dot(*this));
        }

        void normalize()
        {
            T n = norm();
            if (n == 0)
                throw "Cannot normalize zero vector";
            for (size_t i = 0; i < size(); ++i)
                m_data[i] /= n;
        }

    private:
        Array<T> m_data;
    };

} // namespace mylib

#endif