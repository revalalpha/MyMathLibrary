#ifndef MYLIB_INTRUSIVE_LIST_H
#define MYLIB_INTRUSIVE_LIST_H

namespace mylib {

    template <typename T>
    class IntrusiveList;

    template <typename T>
    class IntrusiveListNode {
        friend class IntrusiveList<T>;

    private:
        T* m_next = nullptr;
        T* m_prev = nullptr;

    public:
        IntrusiveListNode() = default;
        ~IntrusiveListNode() = default;

        T* getNext()
        { 
            return m_next;
        }

        T* getPrevious() 
        {
            return m_prev; 
        }
    };

    template <typename T>
    class IntrusiveList {
    private:
        T* m_head;
        T* m_tail;
        size_t m_size;

    public:
        IntrusiveList() : m_head(nullptr), m_tail(nullptr), m_size(0) {}

        ~IntrusiveList() 
        { 
            clear();
        }

        void push_back(T& obj) 
        {
            obj.m_next = nullptr;
            obj.m_prev = m_tail;

            if (m_tail)
                m_tail->m_next = &obj;
            else
                m_head = &obj;

            m_tail = &obj;
            ++m_size;
        }

        void push_front(T& obj)
        {
            obj.m_next = m_head;
            obj.m_prev = nullptr;

            if (m_head)
                m_head->m_prev = &obj;
            else
                m_tail = &obj;

            m_head = &obj;
            ++m_size;
        }

        void remove(T& obj) 
        {
            if (obj.m_prev)
                obj.m_prev->m_next = obj.m_next;
            else
                m_head = obj.m_next;

            if (obj.m_next)
                obj.m_next->m_prev = obj.m_prev;
            else
                m_tail = obj.m_prev;

            obj.m_next = nullptr;
            obj.m_prev = nullptr;
            --m_size;
        }

        void clear()
        {
            while (m_head)
                remove(*m_head);
        }

        bool empty() const 
        { 
            return m_size == 0; 
        }

        size_t size() const 
        { 
            return m_size; 
        }

        class Iterator 
        {
        private:
            T* m_current;
        public:
            Iterator(T* node) : m_current(node) {}

            T& operator*() 
            { 
                return *m_current;
            }

            Iterator& operator++() 
            {
                m_current = m_current->m_next;
                return *this;
            }

            Iterator operator++(int) 
            {
                Iterator temp = *this;
                m_current = m_current->m_next;
                return temp;
            }

            Iterator& operator--()
            {
                m_current = m_current->m_prev;
                return *this;
            }

            Iterator operator--(int) 
            {
                Iterator temp = *this;
                m_current = m_current->m_prev;
                return temp;
            }

            bool operator==(const Iterator& other) const 
            { 
                return m_current == other.m_current;
            }

            bool operator!=(const Iterator& other) const 
            {
                return m_current != other.m_current;
            }
        };

        Iterator begin() 
        {
            return Iterator(m_head); 
        }

        Iterator end()
        { 
            return Iterator(nullptr);
        }
    };
} // namespace mylib

#endif // MYLIB_INTRUSIVE_LIST_H
