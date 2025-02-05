#ifndef MYLIB_VECTOR_H
#define MYLIB_VECTOR_H

namespace mylib 
{
    template <typename T>
    class Vector {
    public:
        Vector() : m_data(nullptr), m_size(0), m_capacity(0) {}

        explicit Vector(unsigned int initialCapacity) : m_size(0), m_capacity(initialCapacity) 
        {
            m_data = (m_capacity > 0) ? new T[m_capacity] : nullptr;
        }

        Vector(const Vector& other) : m_size(other.m_size), m_capacity(other.m_capacity) 
        {
            m_data = new T[m_capacity];
            for (unsigned int i = 0; i < m_size; ++i)
                m_data[i] = other.m_data[i];
        }

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

        ~Vector()
        {
            delete[] m_data; 
        }

        void push_back(const T& value) 
        {
            if (m_size == m_capacity)
                InternalResize(m_capacity == 0 ? 1 : m_capacity * 2);
            m_data[m_size++] = value;
        }

        void pop_back() 
        {
            if (m_size > 0)
                --m_size;
        }

        void clear() 
        {
            m_size = 0;
        }

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

        void erase(unsigned int index) 
        {
            if (index >= m_size)
                return;
            for (unsigned int i = index; i < m_size - 1; ++i)
                m_data[i] = m_data[i + 1];
            --m_size;
        }

        void resize(unsigned int newSize) 
        {
            if (newSize > m_capacity) 
                InternalResize(newSize);
            m_size = newSize;
        }

        void reserve(unsigned int newCapacity) 
        {
            if (newCapacity > m_capacity)
                InternalResize(newCapacity);
        }

        unsigned int size() const 
        { 
            return m_size; 
        }

        unsigned int capacity() const 
        { 
            return m_capacity; 
        }

        bool empty() const 
        { 
            return m_size == 0; 
        }

        T* data_ptr() 
        { 
            return m_data; 
        }

        T& at(unsigned int index)
        {
            if (index >= m_size) 
                throw "Index out of range";
            return m_data[index];
        }

        const T& at(unsigned int index) const
        {
            if (index >= m_size) 
                throw "Index out of range";
            return m_data[index];
        }

        T& front() { 
            return m_data[0]; 
        }

        const T& front() const
        { 
            return m_data[0]; 
        }

        T& back() 
        {
            return m_data[m_size - 1];
        }

        const T& back() const
        { 
            return m_data[m_size - 1]; 
        }

        T& operator[](unsigned int index)
        {
            return m_data[index];
        }

        const T& operator[](unsigned int index) const
        {
            return m_data[index];
        }

        bool operator==(const Vector& other) const
        {
            if (m_size != other.m_size)
                return false;
            for (unsigned int i = 0; i < m_size; ++i)
                if (m_data[i] != other.m_data[i]) return false;
            return true;
        }

        bool operator!=(const Vector& other) const
        { 
            return !(*this == other); 
        }

        bool operator<(const Vector& other) const 
        {
            for (unsigned int i = 0; i < m_size && i < other.m_size; ++i) 
            {
                if (m_data[i] < other.m_data[i]) return true;
                if (m_data[i] > other.m_data[i]) return false;
            }
            return m_size < other.m_size;
        }
        bool operator<=(const Vector& other) const
        { 
            return !(other < *this); 
        }

        bool operator>(const Vector& other) const 
        { 
            return other < *this; 
        }

        bool operator>=(const Vector& other) const 
        { 
            return !(*this < other); 
        }

        Vector& operator+=(const Vector& other)
        {
            for (unsigned int i = 0; i < m_size && i < other.m_size; ++i)
                m_data[i] += other.m_data[i];
            return *this;
        }

        Vector& operator-=(const Vector& other)
        {
            for (unsigned int i = 0; i < m_size && i < other.m_size; ++i)
                m_data[i] -= other.m_data[i];
            return *this;
        }

        Vector& operator*=(const T& scalar) 
        {
            for (unsigned int i = 0; i < m_size; ++i) 
                m_data[i] *= scalar;
            return *this;
        }

        Vector& operator/=(const T& scalar)
        {
            for (unsigned int i = 0; i < m_size; ++i)
                m_data[i] /= scalar;
            return *this;
        }

        iterator begin() 
        { 
            return m_data; 
        }

        iterator end() 
        { 
            return m_data + m_size; 
        }

        const_iterator begin() const 
        { 
            return m_data; 
        }

        const_iterator end() const 
        { 
            return m_data + m_size; 
        }

        reverse_iterator rbegin() 
        { 
            return m_data + m_size - 1; 
        }

        reverse_iterator rend() 
        { 
            return m_data - 1; 
        }

        const_reverse_iterator rbegin() const 
        {
            return m_data + m_size - 1;
        }

        const_reverse_iterator rend() const 
        { 
            return m_data - 1;
        }

        private:
            T* m_data;
            unsigned int m_size;
            unsigned int m_capacity;

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