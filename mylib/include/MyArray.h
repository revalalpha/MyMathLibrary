#ifndef MYLIB_ARRAY_H
#define MYLIB_ARRAY_H

namespace mylib
{
    /**
     * Generic Array class representing a dynamic array.
     * @tparam T The type of elements stored in the array.
     */
    template <typename T>
    class Array {
    private:
        T* m_data;   ///< Pointer to the array data.
        size_t m_size;   ///< Size of the array.

    public:
        /**
         * Default constructor.
         * Initializes an empty array with no allocated memory.
         */
        Array() : m_data(nullptr), m_size(0) {}

        /**
         * Constructor with specified size.
         * Allocates memory for an array of the given size and initializes all elements to zero.
         * @param size The size of the array.
         */
        explicit Array(size_t size) : m_size(size)
        {
            m_data = new T[size]();  ///< Dynamically allocate memory for the array and initialize to zero.
        }

        /**
         * Copy constructor.
         * Creates a new Array instance by copying elements from another array.
         * @param other The other array to copy from.
         */
        Array(const Array& other) : m_data(new T[other.m_size]), m_size(other.m_size)
        {
            for (size_t i = 0; i < m_size; ++i)
                m_data[i] = other.m_data[i];  ///< Copy elements one by one.
        }

        /**
         * Copy assignment operator.
         * Allows copying the contents of one array to another.
         * Frees the previously allocated memory before assigning the new array.
         * @param other The other array to copy from.
         * @return A reference to the current object after the assignment.
         */
        Array& operator=(const Array& other)
        {
            if (this != &other)
            {
                T* newData = new T[other.m_size];  ///< Allocate memory for a new array.
                for (size_t i = 0; i < other.m_size; ++i)
                    newData[i] = other.m_data[i];  ///< Copy elements.

                delete[] m_data;  ///< Free the memory of the old array.
                m_data = newData;  ///< Point to the new array.
                m_size = other.m_size;  ///< Update the size.
            }
            return *this;  ///< Return the current object to allow chained assignments.
        }

        /**
         * Destructor.
         * Frees the memory allocated for the array.
         */
        ~Array()
        {
            delete[] m_data;
        }

        /**
         * Accessor for an element in the array (read/write access).
         * Throws an exception if the index is out of bounds.
         * @param index The index of the element.
         * @return A reference to the element at the specified index.
         * @throws "Index out of range" if the index is invalid.
         */
        T& operator[](size_t index)
        {
            if (index >= m_size)
                throw "Index out of range";  ///< Checks if the index is valid.
            return m_data[index];
        }

        /**
         * Accessor for an element in the array (read-only access).
         * Throws an exception if the index is out of bounds.
         * @param index The index of the element.
         * @return A constant reference to the element at the specified index.
         * @throws "Index out of range" if the index is invalid.
         */
        const T& operator[](size_t index) const
        {
            if (index >= m_size)
                throw "Index out of range";  ///< Checks if the index is valid.
            return m_data[index];
        }

        /**
         * Gets the size of the array.
         * @return The size of the array.
         */
        size_t getSize() const
        {
            return m_size;
        }

        /**
         * Resizes the array.
         * Allocates a new array with the new size and copies the old elements.
         * @param newSize The new size of the array.
         */
        void resize(size_t newSize)
        {
            if (newSize == m_size) return;  ///< If the size doesn't change, do nothing.

            T* newData = new T[newSize];  ///< Allocate memory for a new array.
            size_t minSize = (m_size < newSize) ? m_size : newSize;  ///< Determine the smaller size for copying.

            for (size_t i = 0; i < minSize; ++i)
                newData[i] = m_data[i];  ///< Copy existing elements.

            delete[] m_data;  ///< Free the old memory.
            m_data = newData;  ///< Point to the new array.
            m_size = newSize;  ///< Update the size.
        }

        /**
         * Clears the array.
         * Frees the memory and resets the array's members.
         */
        void clear()
        {
            delete[] m_data;
            m_data = nullptr;
            m_size = 0;
        }

        /**
         * Fills the array with a specific value.
         * @param value The value to assign to all elements in the array.
         */
        void fill(const T& value)
        {
            for (size_t i = 0; i < m_size; ++i)
                m_data[i] = value;  ///< Set each element to the specified value.
        }

        /**
         * Assigns a specific count of elements with a given value.
         * Resizes the array to the given count and fills it with the specified value.
         * @param count The number of elements.
         * @param value The value to assign to each element.
         */
        void assign(size_t count, const T& value)
        {
            resize(count);
            for (size_t i = 0; i < count; ++i)
                m_data[i] = value;  ///< Assign the value to each element.
        }

        /**
         * Gets the first element of the array.
         * Throws an exception if the array is empty.
         * @return A reference to the first element.
         * @throws "Array is empty" if the array is empty.
         */
        T& front()
        {
            if (m_size == 0)
                throw "Array is empty";
            return m_data[0];
        }

        /**
         * Gets the last element of the array.
         * Throws an exception if the array is empty.
         * @return A reference to the last element.
         * @throws "Array is empty" if the array is empty.
         */
        T& back()
        {
            if (m_size == 0)
                throw "Array is empty";
            return m_data[m_size - 1];
        }

        /**
         * Gets a pointer to the underlying data of the array.
         * @return A pointer to the data array.
         */
        T* dataPointer()
        {
            return m_data;
        }

        /**
         * Checks if the array is empty.
         * @return True if the array is empty, otherwise false.
         */
        bool empty() const
        {
            return m_size == 0;
        }

        /**
         * Swaps the contents of this array with another.
         * @param other The array to swap with.
         */
        void swap(Array& other)
        {
            T* tempData = m_data;
            size_t tempSize = m_size;
            m_data = other.m_data;
            m_size = other.m_size;
            other.m_data = tempData;
            other.m_size = tempSize;
        }

        /**
         * Gets a pointer to the first element of the array.
         * @return A pointer to the first element.
         */
        T* begin()
        {
            return m_data;
        }

        /**
         * Gets a pointer to one past the last element of the array.
         * @return A pointer to the end position (one past the last element).
         */
        T* end()
        {
            return m_data + m_size;
        }

        /**
         * Gets a pointer to the last element of the array.
         * @return A pointer to the last element.
         */
        T* rbegin()
        {
            return m_data + m_size - 1;
        }

        /**
         * Gets a pointer to one before the first element of the array.
         * @return A pointer to the reverse end position (one before the first element).
         */
        T* rend()
        {
            return m_data - 1;
        }
    };

    /**
     * Compares two arrays for equality.
     * @param lhs The first array.
     * @param rhs The second array.
     * @return True if the arrays are equal, otherwise false.
     */
    template <typename T>
    bool operator==(const Array<T>& lhs, const Array<T>& rhs)
    {
        if (lhs.getSize() != rhs.getSize())
            return false;
        for (size_t i = 0; i < lhs.getSize(); ++i)
        {
            if (lhs[i] != rhs[i])
                return false;
        }
        return true;
    }

    /**
     * Compares two arrays for inequality.
     * @param lhs The first array.
     * @param rhs The second array.
     * @return True if the arrays are not equal, otherwise false.
     */
    template <typename T>
    bool operator!=(const Array<T>& lhs, const Array<T>& rhs)
    {
        return !(lhs == rhs);
    }

    /**
     * Compares two arrays to determine if the first is less than the second.
     * @param lhs The first array.
     * @param rhs The second array.
     * @return True if the first array is less than the second, otherwise false.
     */
    template <typename T>
    bool operator<(const Array<T>& lhs, const Array<T>& rhs)
    {
        size_t minSize = (lhs.getSize() < rhs.getSize()) ? lhs.getSize() : rhs.getSize();
        for (size_t i = 0; i < minSize; ++i)
        {
            if (lhs[i] < rhs[i])
                return true;
            if (lhs[i] > rhs[i])
                return false;
        }
        return lhs.getSize() < rhs.getSize();
    }

    /**
     * Compares two arrays to determine if the first is less than or equal to the second.
     * @param lhs The first array.
     * @param rhs The second array.
     * @return True if the first array is less than or equal to the second, otherwise false.
     */
    template <typename T>
    bool operator<=(const Array<T>& lhs, const Array<T>& rhs)
    {
        return !(rhs < lhs);
    }

    /**
     * Compares two arrays to determine if the first is greater than the second.
     * @param lhs The first array.
     * @param rhs The second array.
     * @return True if the first array is greater than the second, otherwise false.
     */
    template <typename T>
    bool operator>(const Array<T>& lhs, const Array<T>& rhs)
    {
        return rhs < lhs;
    }

    /**
     * Compares two arrays to determine if the first is greater than or equal to the second.
     * @param lhs The first array.
     * @param rhs The second array.
     * @return True if the first array is greater than or equal to the second, otherwise false.
     */
    template <typename T>
    bool operator>=(const Array<T>& lhs, const Array<T>& rhs)
    {
        return !(lhs < rhs);
    }

} // namespace mylib

#endif // MYLIB_ARRAY_H
