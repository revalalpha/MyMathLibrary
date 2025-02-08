#ifndef MYLIB_INTRUSIVE_LIST_H
#define MYLIB_INTRUSIVE_LIST_H

#include <iostream>

namespace mylib {
    /**
     * Node structure represents an element of type T in the intrusive list.
     * It contains a data element and pointers to the next and previous nodes.
     * @tparam T Type of the data in the node.
     */
    template <typename T>
    struct Node
	{
        T m_data;   ///< The data of type T stored in the node.
        Node* m_next; ///< Pointer to the next node.
        Node* m_prev; ///< Pointer to the previous node.

        /**
         * Constructor to create a Node with a given value.
         * @param value The value to store in the node.
         */
        Node(const T& value) : m_data(value), m_next(nullptr), m_prev(nullptr) {}

        /**
         * Constructor to create a Node with a given value using move semantics.
         * @param value The value to store in the node.
         */
        Node(T&& value) : m_data(std::move(value)), m_next(nullptr), m_prev(nullptr) {}
    };

    /**
     * IntrusiveList class represents a doubly linked list where each node
     * contains the data and links to the next and previous nodes.
     * @tparam T Type of the elements in the list.
     */
    template <typename T>
    class IntrusiveList
	{
        Node<T>* m_head;  ///< Pointer to the first node in the list.
        Node<T>* m_tail;  ///< Pointer to the last node in the list.
        size_t m_size;    ///< Size of the list.

    public:
        /**
         * Constructor to initialize an empty list.
         * The head and tail pointers are set to nullptr, and size is set to 0.
         */
        IntrusiveList() : m_head(nullptr), m_tail(nullptr), m_size(0) {}

        /**
         * Adds an element to the end of the list.
         * @param value The value to be added to the list.
         */
        void push_back(const T& value)
    	{
            Node<T>* newNode = new Node<T>(value);
            if (!m_head)
                m_head = m_tail = newNode;
            else 
            {
                m_tail->m_next = newNode;
                newNode->m_prev = m_tail;
                m_tail = newNode;
            }
            ++m_size;
        }

        /**
         * Adds an element to the front of the list.
         * @param value The value to be added to the list.
         */
        void push_front(const T& value)
    	{
            Node<T>* newNode = new Node<T>(value);
            if (!m_head)
                m_head = m_tail = newNode;
            else 
            {
                newNode->m_next = m_head;
                m_head->m_prev = newNode;
                m_head = newNode;
            }
            ++m_size;
        }

        /**
         * Removes the first element from the list.
         * @throws std::out_of_range if the list is empty.
         */
        void pop_front()
    	{
            if (!m_head)
                throw std::out_of_range("Cannot pop from an empty list");
            Node<T>* temp = m_head;
            m_head = m_head->m_next;
            if (m_head)
                m_head->m_prev = nullptr;
            else
                m_tail = nullptr;
            delete temp;
            --m_size;
        }

        /**
         * Removes the last element from the list.
         * @throws std::out_of_range if the list is empty.
         */
        void pop_back()
    	{
            if (!m_tail)
                throw "Cannot pop from an empty list";
            Node<T>* temp = m_tail;
            m_tail = m_tail->m_prev;
            if (m_tail)
                m_tail->m_next = nullptr;
            else
                m_head = nullptr;
            delete temp;
            --m_size;
        }

        /**
         * Finds a node containing the given value.
         * @param value The value to search for.
         * @return A pointer to the node containing the value, or nullptr if not found.
         */
        Node<T>* find(const T& value)
    	{
            Node<T>* current = m_head;
            while (current) {
                if (current->m_data == value)
                    return current;
                current = current->m_next;
            }
            return nullptr;
        }

        /**
         * Removes a specific node from the list.
         * @param value The value of the node to remove.
         */
        void remove(const T& value)
    	{
            Node<T>* nodeToRemove = find(value);
            if (nodeToRemove) 
            {
                if (nodeToRemove->m_prev)
                    nodeToRemove->m_prev->m_next = nodeToRemove->m_next;
                else
                    m_head = nodeToRemove->m_next;
                if (nodeToRemove->m_next)
                    nodeToRemove->m_next->m_prev = nodeToRemove->m_prev;
                else
                    m_tail = nodeToRemove->m_prev;
                delete nodeToRemove;
                --m_size;
            }
        }

        /**
         * Gets the size of the list.
         * @return The size of the list.
         */
        size_t getSize() const
    	{
            return m_size;
        }

        /**
         * Checks if the list is empty.
         * @return True if the list is empty, false otherwise.
         */
        bool empty() const
    	{
            return m_size == 0;
        }

        /**
         * Gets the first element of the list.
         * @return A reference to the first element in the list.
         * @throws std::out_of_range if the list is empty.
         */
        T& front()
    	{
            if (!m_head)
                throw "List is empty";
            return m_head->data;
        }

        /**
         * Gets the last element of the list.
         * @return A reference to the last element in the list.
         * @throws std::out_of_range if the list is empty.
         */
        T& back()
    	{
            if (!m_tail)
                throw "List is empty";
            return m_tail->m_data;
        }

        /**
         * Iterator class for traversing the list.
         */
        class Iterator
    	{
        public:
            Node<T>* current; ///< The current node.

            /**
             * Constructor to initialize the iterator with a given node.
             * @param node The node to initialize the iterator with.
             */
            Iterator(Node<T>* node) : current(node) {}

            /**
             * Dereferences the iterator to get the current element.
             * @return The current element.
             */
            T& operator*()
        	{
                return current->m_data;
            }

            /**
             * Accesses the current element via pointer.
             * @return A pointer to the current element.
             */
            T* operator->()
        	{
                return &(current->m_data);
            }

            /**
             * Advances the iterator to the next node.
             * @return A reference to the iterator.
             */
            Iterator& operator++()
        	{
                if (current)
                    current = current->m_next;
                return *this;
            }

            /**
             * Advances the iterator to the next node and returns the previous iterator.
             * @return The iterator before incrementing.
             */
            Iterator operator++(int)
        	{
                Iterator temp = *this;
                if (current)
                    current = current->m_next;
                return temp;
            }

            /**
             * Moves the iterator to the previous node.
             * @return A reference to the iterator.
             */
            Iterator& operator--()
        	{
                if (current)
                    current = current->m_prev;
                return *this;
            }

            /**
             * Moves the iterator to the previous node and returns the iterator before decrementing.
             * @return The iterator before decrementing.
             */
            Iterator operator--(int)
        	{
                Iterator temp = *this;
                if (current)
                    current = current->m_prev;
                return temp;
            }

            /**
             * Checks if two iterators are equal.
             * @param other The iterator to compare with.
             * @return True if the iterators are equal, false otherwise.
             */
            bool operator==(const Iterator& other) const
        	{
                return current == other.current;
            }

            /**
             * Checks if two iterators are not equal.
             * @param other The iterator to compare with.
             * @return True if the iterators are not equal, false otherwise.
             */
            bool operator!=(const Iterator& other) const
        	{
                return current != other.current;
            }
        };

        /**
         * Constant iterator class for traversing the list.
         */
        class ConstIterator
    	{
        public:
            const Node<T>* current; ///< The current node.

            /**
             * Constructor to initialize the constant iterator with a given node.
             * @param node The node to initialize the iterator with.
             */
            ConstIterator(const Node<T>* node) : current(node) {}

            /**
             * Dereferences the iterator to get the current element.
             * @return The current element.
             */
            const T& operator*() const
        	{
                return current->m_data;
            }

            /**
             * Accesses the current element via pointer.
             * @return A pointer to the current element.
             */
            const T* operator->() const
        	{
                return &(current->m_data);
            }

            /**
             * Advances the iterator to the next node.
             * @return A reference to the iterator.
             */
            ConstIterator& operator++()
        	{
                if (current)
                    current = current->m_next;
                return *this;
            }

            /**
             * Advances the iterator to the next node and returns the previous iterator.
             * @return The iterator before incrementing.
             */
            ConstIterator operator++(int)
        	{
                ConstIterator temp = *this;
                if (current)
                    current = current->m_next;
                return temp;
            }

            /**
             * Checks if two iterators are equal.
             * @param other The iterator to compare with.
             * @return True if the iterators are equal, false otherwise.
             */
            bool operator==(const ConstIterator& other) const
        	{
                return current == other.current;
            }

            /**
             * Checks if two iterators are not equal.
             * @param other The iterator to compare with.
             * @return True if the iterators are not equal, false otherwise.
             */
            bool operator!=(const ConstIterator& other) const
        	{
                return current != other.current;
            }
        };

        /**
         * Gets the iterator to the beginning of the list.
         * @return An iterator to the first node in the list.
         */
        Iterator begin()
    	{
            return Iterator(m_head);
        }

        /**
         * Gets the iterator to the end of the list (past the last element).
         * @return An iterator to the position just after the last node.
         */
        Iterator end()
    	{
            return Iterator(nullptr);
        }

        /**
         * Gets the constant iterator to the beginning of the list.
         * @return A constant iterator to the first node in the list.
         */
        ConstIterator begin() const
    	{
            return ConstIterator(m_head);
        }

        /**
         * Gets the constant iterator to the end of the list (past the last element).
         * @return A constant iterator to the position just after the last node.
         */
        ConstIterator end() const
    	{
            return ConstIterator(nullptr);
        }

        /**
         * Prints the list in forward order.
         */
        void print() const
    	{
            Node<T>* current = m_head;
            while (current) {
                std::cout << current->m_data << " ";
                current = current->m_next;
            }
            std::cout << std::endl;
        }

        /**
         * Prints the list in reverse order.
         */
        void reversePrint() const
    	{
            Node<T>* current = m_tail;
            while (current) {
                std::cout << current->m_data << " ";
                current = current->m_prev;
            }
            std::cout << std::endl;
        }
    };

} // namespace mylib

#endif // MYLIB_INTRUSIVE_LIST_H
