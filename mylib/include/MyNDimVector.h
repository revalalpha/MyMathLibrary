#ifndef MYLIB_VECTOR_ND_H
#define MYLIB_VECTOR_ND_H

#include "MyArray.h"

namespace mylib
{
    /**
     * A class representing an N-dimensional vector.
     * @tparam T The data type of the vector elements.
     */
    template <typename T>
    class VectorND
	{
    public:
        /**
         * Constructor to initialize a vector with a given number of dimensions.
         * @param dimensions The number of dimensions of the vector.
         */
        VectorND(size_t dimensions) : m_data(dimensions) {}

        /**
         * Constructor to initialize a vector with a list of values.
         * @param values The initializer list of values for the vector.
         */
        VectorND(const std::initializer_list<T>& values) : m_data(values.size())
    	{
            size_t i = 0;
            for (const T& val : values)
                m_data[i++] = val;
        }

        /**
         * Gets the size (number of dimensions) of the vector.
         * @return The size of the vector.
         */
        size_t size() const
    	{
            return m_data.getSize();
        }

        /**
         * Access operator to get or set the value at a specific index.
         * @param index The index of the element to access.
         * @return A reference to the element at the specified index.
         */
        T& operator[](size_t index)
    	{
            return m_data[index];
        }

        /**
         * Access operator to get the value at a specific index (constant version).
         * @param index The index of the element to access.
         * @return A constant reference to the element at the specified index.
         */
        const T& operator[](size_t index) const
    	{
            return m_data[index];
        }

        /**
         * Computes the dot product of this vector and another vector.
         * @param other The other vector to compute the dot product with.
         * @return The dot product of the two vectors.
         * @throws "Dimension mismatch" If the vectors have different sizes.
         */
        T dot(const VectorND& other) const
    	{
            if (size() != other.size())
                throw "Dimension mismatch";
            T result = 0;
            for (size_t i = 0; i < size(); ++i)
                result += m_data[i] * other[i];
            return result;
        }

        /**
         * Computes the cross product of this vector and another vector (only for 3D vectors).
         * @param other The other vector to compute the cross product with.
         * @return The cross product of the two vectors.
         * @throws "Cross product only for 3D vectors" If either vector is not 3D.
         */
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

        /**
         * Computes the norm (magnitude) of the vector.
         * @return The norm of the vector.
         */
        T norm() const
    	{
            return std::sqrt(dot(*this));
        }

        /**
         * Normalizes the vector (scales it to have a unit norm).
         * @throws "Cannot normalize zero vector" If the vector's norm is zero.
         */
        void normalize()
    	{
            T n = norm();
            if (n == 0)
                throw "Cannot normalize zero vector";
            for (size_t i = 0; i < size(); ++i)
                m_data[i] /= n;
        }

        /**
         * Adds this vector with another vector.
         * @param other The other vector to add.
         * @return A new vector representing the sum of the two vectors.
         * @throws "Dimension mismatch" If the vectors have different sizes.
         */
        VectorND operator+(const VectorND& other) const
    	{
            if (size() != other.size())
                throw "Dimension mismatch";
            VectorND result(size());
            for (size_t i = 0; i < size(); ++i)
                result[i] = m_data[i] + other[i];
            return result;
        }

        /**
         * Subtracts another vector from this vector.
         * @param other The other vector to subtract.
         * @return A new vector representing the difference of the two vectors.
         * @throws "Dimension mismatch" If the vectors have different sizes.
         */
        VectorND operator-(const VectorND& other) const
    	{
            if (size() != other.size())
                throw "Dimension mismatch";
            VectorND result(size());
            for (size_t i = 0; i < size(); ++i)
                result[i] = m_data[i] - other[i];
            return result;
        }

        /**
         * Scales the vector by a scalar value.
         * @param scalar The scalar value to multiply the vector by.
         * @return A new vector representing the scaled vector.
         */
        VectorND operator*(T scalar) const
    	{
            VectorND result(size());
            for (size_t i = 0; i < size(); ++i)
                result[i] = m_data[i] * scalar;
            return result;
        }

        /**
         * Divides the vector by a scalar value.
         * @param scalar The scalar value to divide the vector by.
         * @return A new vector representing the result of the division.
         * @throws "Cannot divide by zero" If the scalar value is zero.
         */
        VectorND operator/(T scalar) const
    	{
            if (scalar == 0)
                throw "Cannot divide by zero";
            VectorND result(size());
            for (size_t i = 0; i < size(); ++i)
                result[i] = m_data[i] / scalar;
            return result;
        }

        /**
         * Iterator class for the VectorND to allow range-based for loops.
         */
        class Iterator
    	{
        public:
            /**
             * Constructor to initialize the iterator with a pointer.
             * @param ptr Pointer to the element in the vector.
             */
            Iterator(T* ptr) : m_ptr(ptr) {}

            /**
             * Pre-increment operator to move the iterator to the next element.
             * @return A reference to the updated iterator.
             */
            Iterator& operator++()
        	{
                ++m_ptr;
                return *this;
            }

            /**
             * Dereference operator to access the element pointed to by the iterator.
             * @return A reference to the element the iterator points to.
             */
            T& operator*()
        	{
                return *m_ptr;
            }

            /**
             * Not-equal operator to compare two iterators.
             * @param other The other iterator to compare with.
             * @return True if the iterators are not equal, false otherwise.
             */
            bool operator!=(const Iterator& other) const
        	{
                return m_ptr != other.m_ptr;
            }
        private:
            T* m_ptr;
        };

        /**
         * Gets the beginning iterator for the vector.
         * @return The iterator pointing to the first element of the vector.
         */
        Iterator begin()
    	{
            return Iterator(&m_data[0]);
        }

        /**
         * Gets the ending iterator for the vector.
         * @return The iterator pointing one past the last element of the vector.
         */
        Iterator end()
    	{
            return Iterator(&m_data[size()]);
        }

        /**
         * Reverses the vector and returns a new reversed vector.
         * @return A new vector representing the reversed vector.
         */
        VectorND reverse() const
    	{
            VectorND result(size());
            for (size_t i = 0; i < size(); ++i)
                result[i] = m_data[size() - 1 - i];
            return result;
        }

        /**
         * Projects this vector onto another vector.
         * @param other The vector to project onto.
         * @return A new vector representing the projection.
         * @throws "Cannot project onto a zero vector" If the other vector is zero.
         */
        VectorND<T> projection(const VectorND<T>& other) const
    	{
            T dotProduct = this->dot(other);
            T otherNormSquared = other.dot(other);
            if (otherNormSquared == 0)
                throw "Cannot project onto a zero vector";
            return other * (dotProduct / otherNormSquared);
        }

    private:
        Array<T> m_data;  ///< The internal array storing the vector data.
    };

} // namespace mylib

#endif