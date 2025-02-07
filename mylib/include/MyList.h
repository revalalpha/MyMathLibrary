//#ifndef MYLIB_LIST_H
//#define MYLIB_LIST_H
//
//namespace mylib 
//{
//    template <typename T>
//    class List {
//    public:
//        List() : m_head(nullptr), m_tail(nullptr), m_size(0) {}
//
//        /*List(const List& other) : m_head(nullptr), m_tail(nullptr), m_size(0)
//        {
//            for (Node* node = other.m_head; node != nullptr; node = node->m_next)
//                push_back(node->m_data);
//        }*/
//
//        ~List()
//        {
//            clear();
//        }
//
//        void push_back(const T& value)
//        {
//            Node* newNode = new Node(value);
//            if (m_tail)
//            {
//                m_tail->m_next = newNode;
//                newNode->m_prev = m_tail;
//                m_tail = newNode;
//            }
//            else
//                m_head = m_tail = newNode;
//            ++m_size;
//        }
//
//        void push_front(const T& value)
//        {
//            Node* newNode = new Node(value);
//            if (m_head)
//            {
//                m_head->m_prev = newNode;
//                newNode->m_next = m_head;
//                m_head = newNode;
//            }
//            else
//                m_head = m_tail = newNode;
//            ++m_size;
//        }
//
//        void pop_front() {
//            if (!m_head)
//                throw std::out_of_range("List is empty");
//            Node* temp = m_head;
//            m_head = m_head->m_next;
//            if (m_head)
//                m_head->m_prev = nullptr;
//            else
//                m_tail = nullptr;
//            delete temp;
//            --m_size;
//        }
//
//        void pop_back() {
//            if (!m_tail)
//                throw std::out_of_range("List is empty");
//            Node* temp = m_tail;
//            m_tail = m_tail->m_prev;
//            if (m_tail)
//                m_tail->m_next = nullptr;
//            else
//                m_head = nullptr;
//            delete temp;
//            --m_size;
//        }
//
//        T& front()
//        {
//            if (m_head)
//                return m_head->m_data;
//            throw std::out_of_range("List is empty");
//        }
//
//        const T& front() const
//        {
//            if (m_head)
//                return m_head->m_data;
//            throw std::out_of_range("List is empty");
//        }
//
//        T& back()
//        {
//            if (m_tail)
//                return m_tail->m_data;
//            throw std::out_of_range("List is empty");
//        }
//
//        const T& back() const
//        {
//            if (m_tail)
//                return m_tail->m_data;
//            throw std::out_of_range("List is empty");
//        }
//
//        bool empty() const
//        {
//            return m_size == 0;
//        }
//
//        size_t size() const
//        {
//            return m_size;
//        }
//
//        void clear() {
//            while (m_head)
//                pop_front();
//        }
//
//        /*void erase(Iterator pos)
//        {
//            if (!pos.getCurrent())
//                return;
//
//            Node* node = pos.getCurrent();
//
//            if (node == m_head)
//                pop_front();
//            else if (node == m_tail)
//                pop_back();
//            else
//            {
//                node->m_prev->m_next = node->m_next;
//                node->m_next->m_prev = node->m_prev;
//                delete node;
//                --m_size;
//            }
//
//            pos.getCurrent() = nullptr;
//        }*/
//
//
//        std::string print() const {
//            std::ostringstream oss;
//            Node* current = m_head;
//            while (current) {
//                oss << current->m_data << " ";
//                current = current->m_next;
//            }
//            return oss.str();
//        }
//
//        std::string reversePrint() const {
//            std::ostringstream oss;
//            Node* current = m_tail;
//            while (current) {
//                oss << current->m_data << " ";
//                current = current->m_prev;
//            }
//            return oss.str();
//        }
//
//        class Iterator : public List {
//        public:
//            Iterator(Node* node) : m_current(node) {}
//
//            T& operator*()
//            {
//                return m_current->m_data;
//            }
//
//            const T& operator*() const
//            {
//                return m_current->m_data;
//            }
//
//            Iterator& operator++()
//            {
//                m_current = m_current->m_next;
//                return *this;
//            }
//
//            Iterator& operator--()
//            {
//                m_current = m_current->m_prev;
//                return *this;
//            }
//
//            bool operator==(const Iterator& other) const
//            {
//                return m_current == other.m_current;
//            }
//
//            bool operator!=(const Iterator& other) const
//            {
//                return m_current != other.m_current;
//            }
//        private:
//            Node* m_current;
//        };
//
//        Iterator begin()
//        {
//            return Iterator(m_head);
//        }
//
//        Iterator end()
//        {
//            return Iterator(nullptr);
//        }
//
//        Iterator cbegin() const
//        {
//            return Iterator(m_head);
//        }
//
//        Iterator cend() const
//        {
//            return Iterator(nullptr);
//        }
//
//        class ConstIterator {
//        public:
//            ConstIterator(const Node* node) : m_current(node) {}
//
//            const T& operator*() const
//            {
//                return m_current->m_data;
//            }
//
//            ConstIterator& operator++()
//            {
//                m_current = m_current->m_next;
//                return *this;
//            }
//
//            ConstIterator& operator--()
//            {
//                m_current = m_current->m_prev;
//                return *this;
//            }
//
//            bool operator==(const ConstIterator& other) const
//            {
//                return m_current == other.m_current;
//            }
//
//            bool operator!=(const ConstIterator& other) const
//            {
//                return m_current != other.m_current;
//            }
//        private:
//            const Node* m_current;
//        };
//
//        ConstIterator cbegin() const
//        {
//            return ConstIterator(m_head);
//        }
//
//        ConstIterator cend() const
//        {
//            return ConstIterator(nullptr);
//        }
//
//        class ReverseIterator
//        {
//        public:
//            ReverseIterator(Node* node) : m_current(node) {}
//
//            Node* getCurrent() const {
//                return m_current;
//            }
//
//            T& operator*() 
//            {
//                return m_current->m_data; 
//            }
//
//            ReverseIterator& operator++()
//            {
//                m_current = m_current->m_prev;
//                return *this;
//            }
//
//            bool operator==(const ReverseIterator& other) const
//            { 
//                return m_current == other.m_current;
//            }
//
//            bool operator!=(const ReverseIterator& other) const 
//            {
//                return m_current != other.m_current; 
//            }
//        private:
//            Node* m_current;
//        };
//
//        ReverseIterator rbegin() 
//        { 
//            return ReverseIterator(m_tail); 
//        }
//        ReverseIterator rend() 
//        {
//            return ReverseIterator(nullptr); 
//        }
//
//        class ConstReverseIterator
//        {
//        public:
//            ConstReverseIterator(const Node* node) : m_current(node) {}
//
//            const T& operator*() const 
//            {
//                return m_current->m_data;
//            }
//
//            ConstReverseIterator& operator++()
//            {
//                m_current = m_current->m_prev;
//                return *this;
//            }
//
//            bool operator==(const ConstReverseIterator& other) const
//            {
//                return m_current == other.m_current;
//            }
//
//            bool operator!=(const ConstReverseIterator& other) const
//            {
//                return m_current != other.m_current;
//            }
//        private:
//            const Node* m_current;
//        };
//
//        ConstReverseIterator rbegin()
//        {
//            return ConstReverseIterator(m_tail);
//        }
//        ConstReverseIterator rend()
//        {
//            return ConstReverseIterator(nullptr);
//        }
//
//        List& operator=(const List& other)
//        {
//            if (this == &other)
//                return *this;
//            clear();
//            for (Node* node = other.m_head; node != nullptr; node = node->m_next)
//                push_back(node->m_data);
//            return *this;
//        }
//
//         private:
//             struct Node {
//                 T m_data;
//                 Node* m_next;
//                 Node* m_prev;
//
//                 Node(const T& value) : m_data(value), m_next(nullptr), m_prev(nullptr) {}
//             };
//
//             Node* m_head;
//             Node* m_tail;
//             size_t m_size;
//
//    };
//} // namespace mylib
//
//#endif // MYLIB_LIST_H