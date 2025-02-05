#ifndef MYLIB_ARRAY_H
#define MYLIB_ARRAY_H

namespace mylib 
{
    template <typename T>
    class Array {
    private:
        T* m_data;  
        size_t m_size;

    public:
        Array() : m_data(nullptr), m_size(0) {}

        Array(size_t size) : m_size(size) 
        {
            m_data = new T[size];
        }

        Array(const Array& other) : m_size(other.m_size) {
            m_data = new T[m_size];
            for (size_t i = 0; i < m_size; ++i)
                m_data[i] = other.m_data[i];
        }

        Array(const Array& other) : m_data(new T[other.m_size]), m_size(other.m_size) {
            for (size_t i = 0; i < m_size; ++i) {
                m_data[i] = other.m_data[i];
            }
        }

        Array& operator=(const Array& other) 
        {
            if (this != &other) 
            {
                delete[] m_data;

                m_size = other.m_size;
                m_data = new T[m_size];
                for (size_t i = 0; i < m_size; ++i)
                    m_data[i] = other.m_data[i];
            }
            return *this;
        }

        ~Array() 
        {
            delete[] m_data;
        }

        T& operator[](size_t index) 
        {
            if (index >= m_size)
                throw "Index out of range";
            return m_data[index];
        }

        const T& operator[](size_t index) const
        {
            if (index >= m_size)
                throw "Index out of range";
            return m_data[index];
        }

        size_t getSize() const 
        {
            return m_size;
        }

        void resize(size_t newSize) 
        {
            T* newData = new T[newSize];
            size_t minSize = (newSize < m_size) ? newSize : m_size;

            for (size_t i = 0; i < minSize; ++i)
                newData[i] = m_data[i];

            delete[] m_data;
            m_data = newData;
            m_size = newSize;
        }

        void clear() 
        {
            delete[] m_data;
            m_data = nullptr;
            m_size = 0;
        }

        void fill(const T& value) 
        {
            for (size_t i = 0; i < m_size; ++i)
                m_data[i] = value;
        }

        T& front()
        {
            if (m_size == 0) 
                throw "Array is empty";
            return m_data[0];
        }

        T& back()
        {
            if (m_size == 0) 
                throw "Array is empty";
            return m_data[m_size - 1];
        }

        T* dataPointer()
        {
            return m_data;
        }

        bool empty() const 
        {
            return m_size == 0;
        }

        size_t max_size() const 
        {
            return (size_t)-1;
        }

        void swap(Array& other)
        {
            T* tempData = m_data;
            size_t tempSize = m_size;
            m_data = other.m_data;
            m_size = other.m_size;
            other.m_data = tempData;
            other.m_size = tempSize;
        }

        T* begin() 
        {
            return m_data;
        }

        T* end()
        {
            return m_data + m_size;
        }

        T* rbegin()
        {
            return m_data + m_size - 1;
        }

        T* rend() 
        {
            return m_data - 1;
        }
    };

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

    template <typename T>
    bool operator!=(const Array<T>& lhs, const Array<T>& rhs) 
    {
        return !(lhs == rhs);
    }

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

    template <typename T>
    bool operator<=(const Array<T>& lhs, const Array<T>& rhs) 
    {
        return !(rhs < lhs);
    }

    template <typename T>
    bool operator>(const Array<T>& lhs, const Array<T>& rhs)
    {
        return rhs < lhs;
    }

    template <typename T>
    bool operator>=(const Array<T>& lhs, const Array<T>& rhs) 
    {
        return !(lhs < rhs);
    }

} // namespace mylib

#endif