#ifndef MYLIB_VECTOR_H
#define MYLIB_VECTOR_H

namespace mylib
{
    // Generic Vector class for dynamic array implementation.
    // Param: T - The type of elements stored in the vector.
    template <typename T>
    class Vector {
    public:
        // Default constructor initializes an empty vector with no allocated memory.
        Vector() : m_data(nullptr), m_size(0), m_capacity(0) {}

        // Constructor with initial capacity.
        // Param: initialCapacity - The initial capacity for the vector.
        explicit Vector(unsigned int initialCapacity) : m_size(0), m_capacity(initialCapacity)
        {
            m_data = (m_capacity > 0) ? new T[m_capacity] : nullptr;
        }

        // Copy constructor.
        // Param: other - The vector to copy from.
        Vector(const Vector& other) : m_size(other.m_size), m_capacity(other.m_capacity)
        {
            m_data = new T[m_capacity];
            for (unsigned int i = 0; i < m_size; ++i)
                m_data[i] = other.m_data[i];
        }

        // Assignment operator.
        // Param: other - The vector to copy from.
        // Returns: A reference to this vector after copying.
        Vector& operator=(const Vector& other)
        {
            if (this != &other)
            {
                delete[] m_data;
                m_size = other.m_size;
                m_capacity = other.m_capacity;
                m_data = new T[m_capacity];
                for (unsigned int i = 0; i < m_size; ++i)
                    m_data[i] = other.m_data[i];
            }
            return *this;
        }

        // Destructor to deallocate memory used by the vector.
        ~Vector()
        {
            delete[] m_data;
        }

        // Adds a new element to the end of the vector, resizing if necessary.
        // Param: value - The value to add to the vector.
        void push_back(const T& value)
        {
            if (m_size == m_capacity)
                InternalResize(m_capacity == 0 ? 1 : m_capacity * 2);
            m_data[m_size++] = value;
        }

        // Removes the last element from the vector.
        void pop_back()
        {
            if (m_size > 0)
                --m_size;
        }

        // Clears the vector by resetting its size to 0.
        void clear()
        {
            m_size = 0;
        }

        // Swaps the content of this vector with another vector.
        // Param: other - The vector to swap with.
        void swap(Vector& other) {
            T* tmpData = m_data;
            unsigned int tmpSize = m_size;
            unsigned int tmpCapacity = m_capacity;
            m_data = other.m_data;
            m_size = other.m_size;
            m_capacity = other.m_capacity;
            other.m_data = tmpData;
            other.m_size = tmpSize;
            other.m_capacity = tmpCapacity;
        }

        // Inserts a value at a specified index.
        // Param: index - The index to insert at.
        // Param: value - The value to insert.
        void insert(unsigned int index, const T& value) {
            if (index > m_size)
                return;
            if (m_size == m_capacity)
                InternalResize(m_capacity == 0 ? 1 : m_capacity * 2);
            for (unsigned int i = m_size; i > index; --i)
                m_data[i] = m_data[i - 1];
            m_data[index] = value;
            ++m_size;
        }

        // Erases the element at a specific index.
        // Param: index - The index to erase.
        void erase(unsigned int index)
        {
            if (index >= m_size)
                return;
            for (unsigned int i = index; i < m_size - 1; ++i)
                m_data[i] = m_data[i + 1];
            --m_size;
        }

        // Resizes the vector to a new size, optionally expanding or shrinking.
        // Param: newSize - The new size of the vector.
        void resize(size_t newSize)
        {
            if (newSize > m_capacity)
                InternalResize(newSize);
            if (newSize < m_size)
                m_size = newSize;
            else if (newSize > m_size)
                for (size_t i = m_size; i < newSize; ++i)
                    m_data[i] = T();
            m_size = newSize;
        }

        // Reserves space for at least newCapacity elements.
        // Param: newCapacity - The capacity to reserve.
        void reserve(unsigned int newCapacity)
        {
            if (newCapacity > m_capacity)
                InternalResize(newCapacity);
        }

        // Returns the current number of elements in the vector.
        // Returns: The size of the vector.
        unsigned int size() const
        {
            return m_size;
        }

        // Returns the current capacity of the vector.
        // Returns: The capacity of the vector.
        unsigned int capacity() const
        {
            return m_capacity;
        }

        // Checks if the vector is empty.
        // Returns: true if the vector is empty, false otherwise.
        bool empty() const
        {
            return m_size == 0;
        }

        // Returns a pointer to the underlying data array.
        // Returns: A pointer to the vector's data.
        T* data()
        {
            return m_data;
        }

        // Accesses an element at a specified index with bounds checking.
        // Param: index - The index of the element.
        // Returns: The element at the specified index.
        T& at(unsigned int index)
        {
            if (index >= m_size)
                throw "Index out of range";
            return m_data[index];
        }

        // Accesses an element at a specified index with bounds checking (const version).
        // Param: index - The index of the element.
        // Returns: The element at the specified index (const version).
        const T& at(unsigned int index) const
        {
            if (index >= m_size)
                throw "Index out of range";
            return m_data[index];
        }

        // Assigns a specific number of elements with the same value.
        // Param: count - The number of elements to assign.
        // Param: value - The value to assign to each element.
        void assign(unsigned int count, const T& value)
        {
            clear();
            for (unsigned int i = 0; i < count; ++i)
                push_back(value);
        }

        // Returns the first element of the vector.
        // Returns: The first element of the vector.
        T& front() {
            return m_data[0];
        }

        // Returns the first element of the vector (const version).
        // Returns: The first element of the vector (const version).
        const T& front() const
        {
            return m_data[0];
        }

        // Returns the last element of the vector.
        // Returns: The last element of the vector.
        T& back()
        {
            return m_data[m_size - 1];
        }

        // Returns the last element of the vector (const version).
        // Returns: The last element of the vector (const version).
        const T& back() const
        {
            return m_data[m_size - 1];
        }

        // Accesses an element at a specified index.
        // Param: index - The index of the element.
        // Returns: The element at the specified index.
        T& operator[](unsigned int index)
        {
            return m_data[index];
        }

        // Accesses an element at a specified index (const version).
        // Param: index - The index of the element.
        // Returns: The element at the specified index (const version).
        const T& operator[](unsigned int index) const
        {
            return m_data[index];
        }

        // Compares this vector with another vector for equality.
        // Param: other - The vector to compare with.
        // Returns: true if both vectors are equal, false otherwise.
        bool operator==(const Vector& other) const
        {
            if (m_size != other.m_size)
                return false;
            for (unsigned int i = 0; i < m_size; ++i)
                if (m_data[i] != other.m_data[i]) return false;
            return true;
        }

        // Compares this vector with another vector for inequality.
        // Param: other - The vector to compare with.
        // Returns: true if both vectors are not equal, false otherwise.
        bool operator!=(const Vector& other) const
        {
            return !(*this == other);
        }

        // Compares this vector with another vector to check if it is less than.
        // Param: other - The vector to compare with.
        // Returns: true if this vector is less than the other, false otherwise.
        bool operator<(const Vector& other) const
        {
            for (unsigned int i = 0; i < m_size && i < other.m_size; ++i)
            {
                if (m_data[i] < other.m_data[i]) return true;
                if (m_data[i] > other.m_data[i]) return false;
            }
            return m_size < other.m_size;
        }

        // Less-than-or-equal-to operator for vector comparison.
// Compares the current vector to another vector by checking if the other vector is less than the current one.
// Param: other - The vector to compare to.
// Returns: true if the current vector is less than or equal to the other vector, false otherwise.
        bool operator<=(const Vector& other) const
        {
            return !(other < *this);
        }

        // Greater-than operator for vector comparison.
        // Compares the current vector to another vector by checking if the other vector is less than the current one.
        // Param: other - The vector to compare to.
        // Returns: true if the current vector is greater than the other vector, false otherwise.
        bool operator>(const Vector& other) const
        {
            return other < *this;
        }

        // Greater-than-or-equal-to operator for vector comparison.
        // Compares the current vector to another vector by checking if the current vector is not less than the other vector.
        // Param: other - The vector to compare to.
        // Returns: true if the current vector is greater than or equal to the other vector, false otherwise.
        bool operator>=(const Vector& other) const
        {
            return !(*this < other);
    }

        // Addition assignment operator for vector addition.
        // Adds the elements of another vector to the current vector.
        // Param: other - The vector to add to the current vector.
        // Returns: A reference to the updated vector after addition.
        Vector& operator+=(const Vector& other)
        {
            for (unsigned int i = 0; i < m_size && i < other.m_size; ++i)
                m_data[i] += other.m_data[i];
            return *this;
        }

        // Subtraction assignment operator for vector subtraction.
        // Subtracts the elements of another vector from the current vector.
        // Param: other - The vector to subtract from the current vector.
        // Returns: A reference to the updated vector after subtraction.
        Vector& operator-=(const Vector& other)
        {
            for (unsigned int i = 0; i < m_size && i < other.m_size; ++i)
                m_data[i] -= other.m_data[i];
            return *this;
        }

        // Multiplication assignment operator for scalar multiplication.
        // Multiplies each element of the current vector by a scalar value.
        // Param: scalar - The scalar value to multiply each element of the vector by.
        // Returns: A reference to the updated vector after multiplication.
        Vector& operator*=(const T& scalar)
        {
            for (unsigned int i = 0; i < m_size; ++i)
                m_data[i] *= scalar;
            return *this;
        }

        // Division assignment operator for scalar division.
        // Divides each element of the current vector by a scalar value.
        // Param: scalar - The scalar value to divide each element of the vector by.
        // Returns: A reference to the updated vector after division.
        Vector& operator/=(const T& scalar)
        {
            for (unsigned int i = 0; i < m_size; ++i)
                m_data[i] /= scalar;
            return *this;
        }

        // Iterator for accessing elements of the vector.
    // Allows iteration through the vector from the beginning to the end.
        class Iterator
        {
        public:
            // Constructor: Initializes the iterator with a pointer to the element.
            // @param ptr: The pointer to the element to start from.
            Iterator(T* ptr) : m_ptr(ptr) {}

            // Dereference operator: Accesses the element pointed to by the iterator.
            // @return: A reference to the element at the iterator's current position.
            T& operator*()
            {
                return *m_ptr;
            }

            // Arrow operator: Allows access to the members of the element pointed to by the iterator.
            // @return: A pointer to the element at the iterator's current position.
            T* operator->()
            {
                return m_ptr;
            }

            // Pre-increment operator: Moves the iterator to the next element in the vector.
            // @return: A reference to the updated iterator.
            Iterator& operator++()
            {
                ++m_ptr;
                return *this;
            }

            // Post-increment operator: Returns the iterator before moving to the next element.
            // @return: A copy of the iterator before incrementing.
            Iterator operator++(int)
            {
                Iterator temp = *this;
                ++(*this);
                return temp;
            }

            // Equality comparison operator: Checks if two iterators point to the same element.
            // @param other: The iterator to compare with.
            // @return: True if the iterators point to the same element, otherwise false.
            bool operator==(const Iterator& other) const
            {
                return m_ptr == other.m_ptr;
            }

            // Inequality comparison operator: Checks if two iterators point to different elements.
            // @param other: The iterator to compare with.
            // @return: True if the iterators point to different elements, otherwise false.
            bool operator!=(const Iterator& other) const
            {
                return m_ptr != other.m_ptr;
            }

        private:
            T* m_ptr;
        };

        // ConstIterator for read-only access to the vector's elements.
		// Provides access to elements without modifying them.
        class ConstIterator
        {
        public:
            // Constructor to initialize with a pointer to an element.
            // Param: ptr - The pointer to the element in the container.
            ConstIterator(const T* ptr) : m_ptr(ptr) {}

            // Dereference operator to access the element the iterator points to.
            // Returns: The constant reference to the element.
            const T& operator*() const
            {
                return *m_ptr;
            }

            // Arrow operator to access members of the element the iterator points to.
            // Returns: A pointer to the element.
            const T* operator->() const
            {
                return m_ptr;
            }

            // Prefix increment operator to move the iterator to the next element.
            // Returns: A reference to the updated iterator.
            ConstIterator& operator++()
            {
                ++m_ptr;
                return *this;
            }

            // Postfix increment operator to move the iterator to the next element.
            // Returns: A copy of the iterator before incrementing.
            ConstIterator operator++(int)
            {
                ConstIterator temp = *this;
                ++(*this);
                return temp;
            }

            // Equality comparison operator to compare iterators.
            // Param: other - The iterator to compare to.
            // Returns: true if the iterators are equal, false otherwise.
            bool operator==(const ConstIterator& other) const
            {
                return m_ptr == other.m_ptr;
            }

            // Inequality comparison operator to compare iterators.
            // Param: other - The iterator to compare to.
            // Returns: true if the iterators are not equal, false otherwise.
            bool operator!=(const ConstIterator& other) const
            {
                return m_ptr != other.m_ptr;
            }

        private:
            const T* m_ptr;  // Pointer to the element in the container.
    };

        // ReverseIterator to iterate over elements in reverse order.
        // Provides access to elements in reverse.
        class ReverseIterator
        {
        public:
            // Constructor to initialize with a pointer to an element.
            // Param: ptr - The pointer to the element in the container.
            ReverseIterator(T* ptr) : m_ptr(ptr) {}

            // Dereference operator to access the element the iterator points to.
            // Returns: The reference to the element.
            T& operator*()
            {
                return *m_ptr;
            }

            // Arrow operator to access members of the element the iterator points to.
            // Returns: A pointer to the element.
            T* operator->()
            {
                return m_ptr;
            }

            // Prefix decrement operator to move the iterator to the previous element.
            // Returns: A reference to the updated iterator.
            ReverseIterator& operator--()
            {
                --m_ptr;
                return *this;
            }

            // Postfix decrement operator to move the iterator to the previous element.
            // Returns: A copy of the iterator before decrementing.
            ReverseIterator operator--(int)
            {
                ReverseIterator temp = *this;
                --(*this);
                return temp;
            }

            // Equality comparison operator to compare iterators.
            // Param: other - The iterator to compare to.
            // Returns: true if the iterators are equal, false otherwise.
            bool operator==(const ReverseIterator& other) const
            {
                return m_ptr == other.m_ptr;
            }

            // Inequality comparison operator to compare iterators.
            // Param: other - The iterator to compare to.
            // Returns: true if the iterators are not equal, false otherwise.
            bool operator!=(const ReverseIterator& other) const
            {
                return m_ptr != other.m_ptr;
            }

        private:
            T* m_ptr;  // Pointer to the element in the container.
        };

        // ConstReverseIterator to iterate over elements in reverse order with read-only access.
        class ConstReverseIterator
        {
        public:
            // Constructor to initialize with a pointer to an element.
            // Param: ptr - The pointer to the element in the container.
            ConstReverseIterator(const T* ptr) : m_ptr(ptr) {}

            // Dereference operator to access the element the iterator points to.
            // Returns: The constant reference to the element.
            const T& operator*() const
            {
                return *m_ptr;
            }

            // Arrow operator to access members of the element the iterator points to.
            // Returns: A pointer to the element.
            const T* operator->() const
            {
                return m_ptr;
            }

            // Prefix decrement operator to move the iterator to the previous element.
            // Returns: A reference to the updated iterator.
            ConstReverseIterator& operator--()
            {
                --m_ptr;
                return *this;
            }

            // Postfix decrement operator to move the iterator to the previous element.
            // Returns: A copy of the iterator before decrementing.
            ConstReverseIterator operator--(int)
            {
                ConstReverseIterator temp = *this;
                --(*this);
                return temp;
            }

            // Equality comparison operator to compare iterators.
            // Param: other - The iterator to compare to.
            // Returns: true if the iterators are equal, false otherwise.
            bool operator==(const ConstReverseIterator& other) const
            {
                return m_ptr == other.m_ptr;
            }

            // Inequality comparison operator to compare iterators.
            // Param: other - The iterator to compare to.
            // Returns: true if the iterators are not equal, false otherwise.
            bool operator!=(const ConstReverseIterator& other) const
            {
                return m_ptr != other.m_ptr;
            }

        private:
            const T* m_ptr;  // Pointer to the element in the container.
        };

    public:
    // Returns an iterator pointing to the first element of the container.
    // Returns: Iterator pointing to the first element.
    Iterator begin()
    {
        return Iterator(m_data);
    }

    // Returns an iterator pointing to the element after the last element.
    // Returns: Iterator pointing past the last element.
    Iterator end()
    {
        return Iterator(m_data + m_size);
    }

    // Returns a const iterator pointing to the first element of the container.
    // Returns: ConstIterator pointing to the first element.
    ConstIterator begin() const
    {
        return ConstIterator(m_data);
    }

    // Returns a const iterator pointing to the element after the last element.
    // Returns: ConstIterator pointing past the last element.
    ConstIterator end() const
    {
        return ConstIterator(m_data + m_size);
    }

    // Returns a reverse iterator pointing to the last element of the container.
    // Returns: ReverseIterator pointing to the last element.
    ReverseIterator rbegin()
    {
        return ReverseIterator(m_data + m_size - 1);
    }

    // Returns a reverse iterator pointing to the element before the first element.
    // Returns: ReverseIterator pointing before the first element.
    ReverseIterator rend()
    {
        return ReverseIterator(m_data - 1);
    }

    // Returns a const reverse iterator pointing to the last element of the container.
    // Returns: ConstReverseIterator pointing to the last element.
    ConstReverseIterator rbegin() const
    {
        return ConstReverseIterator(m_data + m_size - 1);
    }

    // Returns a const reverse iterator pointing to the element before the first element.
    // Returns: ConstReverseIterator pointing before the first element.
    ConstReverseIterator rend() const
    {
        return ConstReverseIterator(m_data - 1);
    }


    private:
        T* m_data;           // Pointer to the array holding vector elements.
        unsigned int m_size; // Current size of the vector (number of elements).
        unsigned int m_capacity; // Current capacity of the vector (allocated size).

        // Internal function to resize the vector.
        // Param: newCapacity - The new capacity to resize to.
        void InternalResize(unsigned int newCapacity)
        {
            if (newCapacity <= m_capacity)
                return;
            T* new_data = new T[newCapacity];
            for (unsigned int i = 0; i < m_size; ++i)
                new_data[i] = m_data[i];
            delete[] m_data;
            m_data = new_data;
            m_capacity = newCapacity;
        }

    };

} // namespace mylib

#endif // MYLIB_VECTOR_H
