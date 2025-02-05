#ifndef MYLIB_LIST_H
#define MYLIB_LIST_H

namespace mylib
{
    template <typename T>
    class List {
    private:
        struct Node {
            T m_data;
            Node* m_next;
            Node* m_prev;

            Node(const T& value) : m_data(value), m_next(nullptr), m_prev(nullptr) {}
        };

        Node* m_head;
        Node* m_tail;
        size_t m_size;

    public:
        List() : m_head(nullptr), m_tail(nullptr), m_size(0) {}

        ~List() 
        {
            clear();
        }

        void push_back(const T& value) 
        {
            Node* newNode = new Node(value);
            if (m_tail) 
            {
                m_tail->m_next = newNode;
                newNode->m_prev = m_tail;
                m_tail = newNode;
            }
            else
                m_head = m_tail = newNode;
            ++m_size;
        }

        void push_front(const T& value) 
        {
            Node* newNode = new Node(value);
            if (m_head) 
            {
                m_head->m_prev = newNode;
                newNode->m_next = m_head;
                m_head = newNode;
            }
            else
                m_head = m_tail = newNode;
            ++m_size;
        }

        void pop_front() 
        {
            if (m_head) 
            {
                Node* temp = m_head;
                m_head = m_head->m_next;
                if (m_head)
                    m_head->m_prev = nullptr;
                else
                    m_tail = nullptr;
                delete temp;
                --m_size;
            }
            else
                throw std::out_of_range("List is empty");
        }

        void pop_back()
        {
            if (m_tail)
            {
                Node* temp = m_tail;
                m_tail = m_tail->m_prev;
                if (m_tail)
                    m_tail->m_next = nullptr;
                else
                    m_head = nullptr;
                delete temp;
                --m_size;
            }
            else
                throw std::out_of_range("List is empty");
        }
    e
        T& front()
    {
            if (head) 
                return head->data;
            throw std::out_of_range("List is empty");
        }

        const T& front() const 
        {
            if (head)
                return head->data;
            throw std::out_of_range("List is empty");
        }

        T& back()
        {
            if (tail) 
                return tail->data;
            throw std::out_of_range("List is empty");
        }

        const T& back() const
        {
            if (tail) 
                return tail->data;
            throw std::out_of_range("List is empty");
        }

        bool empty() const 
        {
            return m_size == 0;
        }

        size_t size() const
        {
            return m_size;
        }

        void clear() 
        {
            while (head) 
            {
                pop_front();
            }
        }

        void print() const
        {
            Node* current = head;
            while (current)
            {
                std::cout << current->data << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }

        void print_reverse() const
        {
            Node* current = tail;
            while (current)
            {
                std::cout << current->data << " ";
                current = current->prev;
            }
            std::cout << std::endl;
        }

        class Iterator {
        private:
            Node* current;
        public:
            Iterator(Node* node) : current(node) {}

            T& operator*() 
            {
                return current->data;
            }

            const T& operator*() const 
            {
                return current->data;
            }

            Iterator& operator++() 
            {
                current = current->next;
                return *this;
            }

            Iterator operator++(int)
            {
                Iterator temp = *this;
                current = current->next;
                return temp;
            }

            Iterator& operator--() 
            {
                current = current->prev;
                return *this;
            }

            Iterator operator--(int)
            {
                Iterator temp = *this;
                current = current->prev;
                return temp;
            }

            bool operator==(const Iterator& other) const
            {
                return current == other.current;
            }

            bool operator!=(const Iterator& other) const
            {
                return current != other.current;
            }
        };

        Iterator begin()
        {
            return Iterator(head);
        }

        Iterator end()
        {
            return Iterator(nullptr);
        }

        Iterator cbegin() const
        {
            return Iterator(head);
        }

        Iterator cend() const
        {
            return Iterator(nullptr);
        }

        List& operator=(const List& other) 
        {
            if (this == &other)
                return *this;
            clear();
            for (Node* node = other.head; node != nullptr; node = node->next) 
                push_back(node->data);
            return *this;
        }
    };
} // namespace mylib

#endif // MYLIB_LIST_H