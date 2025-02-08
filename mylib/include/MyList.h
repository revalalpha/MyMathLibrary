#ifndef MYLIB_LIST_H
#define MYLIB_LIST_H

namespace mylib
{
    /**
     * A doubly linked list implementation.
     * @tparam T Type of elements stored in the list.
     */
    template <typename T>
    class List
    {
    private:
        /**
         * Node structure representing an element in the list.
         */
        struct Node
        {
            T m_data;    // Data stored in the node
            Node* m_next; // Pointer to the next node
            Node* m_prev; // Pointer to the previous node

            /**
             * Constructor to initialize a node with a given value.
             * @param value The value to store in the node.
             */
            Node(const T& value) : m_data(value), m_next(nullptr), m_prev(nullptr) {}
        };

        Node* m_head;  // Pointer to the first node in the list
        Node* m_tail;  // Pointer to the last node in the list
        size_t m_size; // Current size of the list

    public:
        /**
         * Default constructor, initializes an empty list.
         */
        List() : m_head(nullptr), m_tail(nullptr), m_size(0) {}

        /**
         * Destructor, deletes all elements in the list.
         */
        ~List()
        {
            clear();
        }

        /**
         * Adds an element to the end of the list.
         * @param value The value to be added.
         */
        void push_back(const T& value)
        {
            Node* newNode = new Node(value);
            if (!m_tail)
                m_head = m_tail = newNode;
            else
            {
                m_tail->m_next = newNode;
                newNode->m_prev = m_tail;
                m_tail = newNode;
            }
            m_size++;
        }

        /**
         * Adds an element to the beginning of the list.
         * @param value The value to be added.
         */
        void push_front(const T& value)
        {
            Node* newNode = new Node(value);
            if (!m_head)
                m_head = m_tail = newNode;
            else
            {
                newNode->m_next = m_head;
                m_head->m_prev = newNode;
                m_head = newNode;
            }
            m_size++;
        }

        /**
         * Removes the last element from the list.
         */
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
                m_size--;
            }
        }

        /**
         * Removes the first element from the list.
         */
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
                m_size--;
            }
        }

        /**
         * Accesses the first element of the list.
         * @return A reference to the first element.
         * @throws Exception if the list is empty.
         */
        T& front()
        {
            if (m_head)
                return m_head->m_data;
            throw "List is empty";
        }

        /**
         * Accesses the last element of the list.
         * @return A reference to the last element.
         * @throws Exception if the list is empty.
         */
        T& back()
        {
            if (m_tail)
                return m_tail->m_data;
            throw "List is empty";
        }

        /**
         * Returns the current size of the list.
         * @return The number of elements in the list.
         */
        size_t getSize() const
        {
            return m_size;
        }

        /**
         * Checks if the list is empty.
         * @return true if the list is empty, false otherwise.
         */
        bool empty() const
        {
            return m_size == 0;
        }

        /**
         * Removes all elements from the list.
         */
        void clear()
        {
            while (m_head)
                pop_front();
        }

        /**
         * Removes all occurrences of a given value from the list.
         * @param value The value to be removed.
         */
        void remove(const T& value)
        {
            Node* current = m_head;
            while (current)
            {
                if (current->m_data == value)
                {
                    Node* toDelete = current;
                    if (current->m_prev)
                        current->m_prev->m_next = current->m_next;
                    else
                        m_head = current->m_next;
                    if (current->m_next)
                        current->m_next->m_prev = current->m_prev;
                    else
                        m_tail = current->m_prev;
                    current = current->m_next;
                    delete toDelete;
                    m_size--;
                }
                else
                {
                    current = current->m_next;
                }
            }
        }

        class Iterator
        {
        public:
            Node* m_current;

            Iterator(Node* node) : m_current(node) {}

            T& operator*()
            {
                return m_current->m_data;
            }

            T* operator->()
            {
                return &(m_current->m_data);
            }

            Iterator& operator++()
            {
                if (m_current)
                    m_current = m_current->m_next;
                return *this;
            }

            Iterator operator++(int)
            {
                Iterator temp = *this;
                if (m_current)
                    m_current = m_current->m_next;
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

        class constIterator
        {
        public:
            Node* m_current;

            constIterator(Node* node) : m_current(node) {}

            const T& operator*() const
            {
                return m_current->m_data;
            }

            const T* operator->() const
            {
                return &(m_current->m_data);
            }

            constIterator& operator++()
            {
                if (m_current)
                    m_current = m_current->m_next;
                return *this;
            }

            constIterator operator++(int)
            {
                constIterator temp = *this;
                if (m_current)
                    m_current = m_current->m_next;
                return temp;
            }

            bool operator==(const constIterator& other) const
            {
                return m_current == other.m_current;
            }

            bool operator!=(const constIterator& other) const
            {
                return m_current != other.m_current;
            }
        };

        class ReverseIterator
        {
        public:
            Node* m_current;

            ReverseIterator(Node* node) : m_current(node) {}

            T& operator*()
            {
                return m_current->m_data;
            }

            T* operator->()
            {
                return &(m_current->m_data);
            }

            ReverseIterator& operator--()
            {
                if (m_current)
                    m_current = m_current->m_prev;
                return *this;
            }

            ReverseIterator operator--(int)
            {
                ReverseIterator temp = *this;
                if (m_current)
                    m_current = m_current->m_prev;
                return temp;
            }

            bool operator==(const ReverseIterator& other) const
            {
                return m_current == other.m_current;
            }

            bool operator!=(const ReverseIterator& other) const
            {
                return m_current != other.m_current;
            }
        };

        class constReverseIterator
        {
        public:
            Node* m_current;

            constReverseIterator(Node* node) : m_current(node) {}

            const T& operator*() const
            {
                return m_current->m_data;
            }

            const T* operator->() const
            {
                return &(m_current->m_data);
            }

            constReverseIterator& operator--()
            {
                if (m_current)
                    m_current = m_current->m_prev;
                return *this;
            }

            constReverseIterator operator--(int)
            {
                constReverseIterator temp = *this;
                if (m_current)
                    m_current = m_current->m_prev;
                return temp;
            }

            bool operator==(const constReverseIterator& other) const
            {
                return m_current == other.m_current;
            }

            bool operator!=(const constReverseIterator& other) const
            {
                return m_current != other.m_current;
            }
        };

        /**
         * Finds an element in the list.
         * @param value The value to search for.
         * @return An iterator pointing to the found element or the end of the list.
         */
        Iterator find(const T& value)
        {
            Node* current = m_head;
            while (current)
            {
                if (current->m_data == value)
                    return Iterator(current);
                current = current->m_next;
            }
            return end();
        }

        /**
         * Reverses the order of the elements in the list.
         */
        void reverse()
        {
            Node* current = m_head;
            Node* temp = nullptr;
            while (current)
            {
                temp = current->m_prev;
                current->m_prev = current->m_next;
                current->m_next = temp;
                current = current->m_prev;
            }
            if (temp)
                m_head = temp->m_prev;
        }

        /**
         * Inserts an element at the specified iterator position.
         * @param pos The iterator indicating where to insert the element.
         * @param value The value to insert.
         */
        void insert(Iterator pos, const T& value)
        {
            Node* newNode = new Node(value);
            if (pos == begin())
                push_front(value);
            else if (pos == end())
                push_back(value);
            else
            {
                Node* current = pos.m_current;
                newNode->m_next = current;
                newNode->m_prev = current->m_prev;
                current->m_prev->m_next = newNode;
                current->m_prev = newNode;
                m_size++;
            }
        }

        /**
         * Removes an element at the specified iterator position.
         * @param it The iterator pointing to the element to remove.
         */
        void erase(Iterator it)
        {
            Node* current = it.m_current;
            if (current)
            {
                if (current->m_prev)
                    current->m_prev->m_next = current->m_next;
                else
                    m_head = current->m_next;
                if (current->m_next)
                    current->m_next->m_prev = current->m_prev;
                else
                    m_tail = current->m_prev;
                delete current;
                m_size--;
            }
        }

        /**
		* Returns an iterator pointing to the beginning of the list.
		* @return An iterator to the first element.
		*/
        Iterator begin()
        {
            return Iterator(m_head);
        }

        /**
		* Returns an iterator pointing to the end of the list (after the last element).
		* @return An iterator to the position after the last element.
		*/
        Iterator end()
        {
            return Iterator(nullptr);
        }

        /**
		* Returns a constIterator pointing to the beginning of the list.
		* @return A constIterator to the first element.
		*/
        constIterator begin() const
        {
            return constIterator(m_head);
        }

        /**
		* Returns a constIterator pointing to the end of the list (after the last item).
		* @return A constIterator to the position after the last element.
		*/
        constIterator end() const
        {
            return constIterator(nullptr);
        }

        /**
		* Returns a ReverseIterator pointing to the end of the list (last item).
		* @return A ReverseIterator to the last element.
		*/
        ReverseIterator rbegin()
        {
            return ReverseIterator(m_tail);
        }

        /**
		* Returns a ReverseIterator pointing to the end of the list (before the first item).
		* @return A ReverseIterator to the position before the first element.
		*/
        ReverseIterator rend()
        {
            return ReverseIterator(nullptr);
        }

        /**
		* Returns a constReverseIterator pointing to the end of the list (last item).
		* @return A constReverseIterator to the last element.
		*/
        constReverseIterator rbegin() const
        {
            return constReverseIterator(m_tail);
        }

        /**
		* Returns a constReverseIterator pointing to the end of the list (before the first item).
		* @return A constReverseIterator to the position before the first element.
		*/
        constReverseIterator rend() const
        {
            return constReverseIterator(nullptr);
        }

        /**
         * Accesses an element at a specified index.
         * @param index The index of the element.
         * @return A reference to the element at the given index.
         * @throws Exception if the index is out of bounds.
         */
        T& at(size_t index)
        {
            if (index >= m_size)
                throw "Index out of bounds";
            Node* temp = m_head;
            for (size_t i = 0; i < index; ++i)
                temp = temp->m_next;
            return temp->m_data;
        }

        /**
         * Show every element in the list.
         */
        void print() const
        {
            Node* current = m_head;
            while (current)
            {
                std::cout << current->m_data << " ";
                current = current->m_next;
            }
            std::cout << std::endl;
        }
    };
} // namespace mylib

#endif
