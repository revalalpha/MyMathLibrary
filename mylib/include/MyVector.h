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

        T* data() 
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

        void assign(unsigned int count, const T& value)
        {
            clear();
            for (unsigned int i = 0; i < count; ++i)
                push_back(value);
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

        class Iterator 
        {
        public:
            Iterator(T* ptr) : m_ptr(ptr) {}

            T& operator*() 
            {
                return *m_ptr;
            }

            T* operator->() 
            {
                return m_ptr;
            }

            Iterator& operator++() 
            {
                ++m_ptr;
                return *this;
            }

            Iterator operator++(int)
            {
                Iterator temp = *this;
                ++(*this);
                return temp;
            }

            bool operator==(const Iterator& other) const 
            {
                return m_ptr == other.m_ptr;
            }

            bool operator!=(const Iterator& other) const 
            {
                return m_ptr != other.m_ptr;
            }

        private:
            T* m_ptr;
        };

        class ConstIterator 
        {
        public:
            ConstIterator(const T* ptr) : m_ptr(ptr) {}

            const T& operator*() const
            {
                return *m_ptr;
            }

            const T* operator->() const
            {
                return m_ptr;
            }

            ConstIterator& operator++() 
            {
                ++m_ptr;
                return *this;
            }

            ConstIterator operator++(int) 
            {
                ConstIterator temp = *this;
                ++(*this);
                return temp;
            }

            bool operator==(const ConstIterator& other) const 
            {
                return m_ptr == other.m_ptr;
            }

            bool operator!=(const ConstIterator& other) const 
            {
                return m_ptr != other.m_ptr;
            }

        private:
            const T* m_ptr;
        };

        class ReverseIterator 
        {
        public:
            ReverseIterator(T* ptr) : m_ptr(ptr) {}

            T& operator*() 
            {
                return *m_ptr;
            }

            T* operator->() {
                return m_ptr;
            }

            ReverseIterator& operator--() 
            {
                --m_ptr;
                return *this;
            }

            ReverseIterator operator--(int)
            {
                ReverseIterator temp = *this;
                --(*this);
                return temp;
            }

            bool operator==(const ReverseIterator& other) const 
            {
                return m_ptr == other.m_ptr;
            }

            bool operator!=(const ReverseIterator& other) const
            {
                return m_ptr != other.m_ptr;
            }

        private:
            T* m_ptr;
        };

        class ConstReverseIterator 
        {
        public:
            ConstReverseIterator(const T* ptr) : m_ptr(ptr) {}

            const T& operator*() const
            {
                return *m_ptr;
            }

            const T* operator->() const 
            {
                return m_ptr;
            }

            ConstReverseIterator& operator--() 
            {
                --m_ptr;
                return *this;
            }

            ConstReverseIterator operator--(int) 
            {
                ConstReverseIterator temp = *this;
                --(*this);
                return temp;
            }

            bool operator==(const ConstReverseIterator& other) const 
            {
                return m_ptr == other.m_ptr;
            }

            bool operator!=(const ConstReverseIterator& other) const
            {
                return m_ptr != other.m_ptr;
            }

        private:
            const T* m_ptr;
        };

    public:

        Iterator begin() 
        {
            return Iterator(m_data);
        }

        Iterator end() 
        {
            return Iterator(m_data + m_size);
        }

        ConstIterator begin() const 
        {
            return ConstIterator(m_data);
        }

        ConstIterator end() const
        {
            return ConstIterator(m_data + m_size);
        }

        ReverseIterator rbegin()
        {
            return ReverseIterator(m_data + m_size - 1);
        }

        ReverseIterator rend() 
        {
            return ReverseIterator(m_data - 1);
        }

        ConstReverseIterator rbegin() const 
        {
            return ConstReverseIterator(m_data + m_size - 1);
        }

        ConstReverseIterator rend() const 
        {
            return ConstReverseIterator(m_data - 1);
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