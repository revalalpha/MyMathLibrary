#ifndef MYLIB_LIST_H
#define MYLIB_LIST_H

#include <stdexcept>
#include <sstream>

namespace mylib {

    template <typename T>
    class List {
    public:
        List() : m_head(nullptr), m_tail(nullptr), m_size(0) {}

        ~List() {
            clear();
        }

        void push_back(const T& value) {
            Node* newNode = new Node(value);
            if (m_tail) {
                m_tail->m_next = newNode;
                newNode->m_prev = m_tail;
                m_tail = newNode;
            }
            else {
                m_head = m_tail = newNode;
            }
            ++m_size;
        }

        void push_front(const T& value) {
            Node* newNode = new Node(value);
            if (m_head) {
                m_head->m_prev = newNode;
                newNode->m_next = m_head;
                m_head = newNode;
            }
            else {
                m_head = m_tail = newNode;
            }
            ++m_size;
        }

        void pop_front() {
            if (!m_head)
                throw std::out_of_range("List is empty");
            Node* temp = m_head;
            m_head = m_head->m_next;
            if (m_head)
                m_head->m_prev = nullptr;
            else
                m_tail = nullptr;
            delete temp;
            --m_size;
        }

        void pop_back() {
            if (!m_tail)
                throw std::out_of_range("List is empty");
            Node* temp = m_tail;
            m_tail = m_tail->m_prev;
            if (m_tail)
                m_tail->m_next = nullptr;
            else
                m_head = nullptr;
            delete temp;
            --m_size;
        }

        T& front() {
            if (m_head)
                return m_head->m_data;
            throw std::out_of_range("List is empty");
        }

        const T& front() const {
            if (m_head)
                return m_head->m_data;
            throw std::out_of_range("List is empty");
        }

        T& back() {
            if (m_tail)
                return m_tail->m_data;
            throw std::out_of_range("List is empty");
        }

        const T& back() const {
            if (m_tail)
                return m_tail->m_data;
            throw std::out_of_range("List is empty");
        }

        bool empty() const {
            return m_size == 0;
        }

        size_t size() const {
            return m_size;
        }

        void clear() {
            while (m_head)
                pop_front();
        }

        void insert(size_t index, const T& value) {
            if (index > m_size) throw std::out_of_range("Index out of range");

            if (index == 0) {
                push_front(value);
            }
            else if (index == m_size) {
                push_back(value);
            }
            else {
                Node* newNode = new Node(value);
                Node* current = m_head;
                for (size_t i = 0; i < index; ++i) {
                    current = current->m_next;
                }
                newNode->m_next = current;
                newNode->m_prev = current->m_prev;
                if (current->m_prev) {
                    current->m_prev->m_next = newNode;
                }
                current->m_prev = newNode;
                ++m_size;
            }
        }

        void erase(size_t index) {
            if (index >= m_size) throw std::out_of_range("Index out of range");

            if (index == 0) {
                pop_front();
            }
            else if (index == m_size - 1) {
                pop_back();
            }
            else {
                Node* current = m_head;
                for (size_t i = 0; i < index; ++i) {
                    current = current->m_next;
                }
                if (current->m_prev) {
                    current->m_prev->m_next = current->m_next;
                }
                if (current->m_next) {
                    current->m_next->m_prev = current->m_prev;
                }
                delete current;
                --m_size;
            }
        }

        void remove(const T& value) {
            Node* current = m_head;
            while (current) {
                if (current->m_data == value) {
                    if (current == m_head) {
                        pop_front();
                    }
                    else if (current == m_tail) {
                        pop_back();
                    }
                    else {
                        current->m_prev->m_next = current->m_next;
                        if (current->m_next) {
                            current->m_next->m_prev = current->m_prev;
                        }
                        delete current;
                        --m_size;
                    }
                    return;
                }
                current = current->m_next;
            }
            throw std::out_of_range("Element not found");
        }

        T& at(size_t index) {
            if (index >= m_size) throw std::out_of_range("Index out of range");
            Node* current = m_head;
            for (size_t i = 0; i < index; ++i) {
                current = current->m_next;
            }
            return current->m_data;
        }

        const T& at(size_t index) const {
            if (index >= m_size) throw std::out_of_range("Index out of range");
            Node* current = m_head;
            for (size_t i = 0; i < index; ++i) {
                current = current->m_next;
            }
            return current->m_data;
        }

        void reverse() {
            if (m_size <= 1) return;

            Node* current = m_head;
            Node* temp = nullptr;
            while (current) {
                temp = current->m_prev;
                current->m_prev = current->m_next;
                current->m_next = temp;
                current = current->m_prev;
            }
            temp = m_head;
            m_head = m_tail;
            m_tail = temp;
        }

        T& operator[](size_t index) {
            return at(index);
        }

        const T& operator[](size_t index) const {
            return at(index);
        }

        std::string print() const {
            std::ostringstream oss;
            Node* current = m_head;
            while (current) {
                oss << current->m_data << " ";
                current = current->m_next;
            }
            return oss.str();
        }

        std::string reversePrint() const {
            std::ostringstream oss;
            Node* current = m_tail;
            while (current) {
                oss << current->m_data << " ";
                current = current->m_prev;
            }
            return oss.str();
        }

        struct iterator {
            //this iterator compatible with stl
            using iterator_category = std::random_access_iterator_tag;
            using value_type = T;
            using difference_type = std::ptrdiff_t;
            using pointer = T*;
            using reference = T&;
            friend List;
            iterator(pointer ptr) : m_ptr(ptr) {}
            reference operator*() {
                return *m_ptr;
            }
            const reference operator*() const {
                return *m_ptr;
            }
            pointer operator->() {
                return m_ptr;
            }
            const pointer operator->() const {
                return m_ptr;
            }
            iterator& operator++() {
                ++m_ptr;
                return *this;
            }
            iterator& operator--() {
                --m_ptr;
                return *this;
            }
            iterator operator+(difference_type n) const {
                return iterator(m_ptr + n);
            }
            iterator operator-(difference_type n) const {
                return iterator(m_ptr - n);
            }
            difference_type operator-(const iterator& other) const {
                return m_ptr - other.m_ptr;
            }
            bool operator==(const iterator& other) const {
                return m_ptr == other.m_ptr;
            }
            bool operator!=(const iterator& other) const {
                return m_ptr != other.m_ptr;
            }
            bool operator<(const iterator& other) const {
                return m_ptr < other.m_ptr;
            }
            bool operator>(const iterator& other) const {
                return m_ptr > other.m_ptr;
            }
            bool operator<=(const iterator& other) const {
                return m_ptr <= other.m_ptr;
            }
            bool operator>=(const iterator& other) const {
                return m_ptr >= other.m_ptr;
            }
        private:
            pointer m_ptr;
        };

        struct const_iterator {
            //this iterator compatible with stl
            using iterator_category = std::random_access_iterator_tag;
            using value_type = const T;
            using difference_type = std::ptrdiff_t;
            using pointer = const T*;
            using reference = const T&;
            friend List;
            const_iterator(pointer ptr) : m_ptr(ptr) {}
            reference operator*() {
                return *m_ptr;
            }
            const reference operator*() const {
                return *m_ptr;
            }
            pointer operator->() {
                return m_ptr;
            }
            const pointer operator->() const {
                return m_ptr;
            }
            const_iterator& operator++() {
                ++m_ptr;
                return *this;
            }
            const_iterator& operator--() {
                --m_ptr;
                return *this;
            }
            const_iterator operator+(difference_type n) const {
                return const_iterator(m_ptr + n);
            }
            const_iterator operator-(difference_type n) const {
                return const_iterator(m_ptr - n);
            }
            difference_type operator-(const const_iterator& other) const {
                return m_ptr - other.m_ptr;
            }
            bool operator==(const const_iterator& other) const {
                return m_ptr == other.m_ptr;
            }
            bool operator!=(const const_iterator& other) const {
                return m_ptr != other.m_ptr;
            }
            bool operator<(const const_iterator& other) const {
                return m_ptr < other.m_ptr;
            }
            bool operator>(const const_iterator& other) const {
                return m_ptr > other.m_ptr;
            }
            bool operator<=(const const_iterator& other) const {
                return m_ptr <= other.m_ptr;
            }
            bool operator>=(const const_iterator& other) const {
                return m_ptr >= other.m_ptr;
            }
        private:
            pointer m_ptr;
        };

        struct reverse_iterator {
            //this iterator compatible with stl
            using iterator_category = std::random_access_iterator_tag;
            using value_type = T;
            using difference_type = std::ptrdiff_t;
            using pointer = T*;
            using reference = T&;
            friend List;
            reverse_iterator(pointer ptr) : m_ptr(ptr) {}
            reference operator*() {
                return *m_ptr;
            }
            const reference operator*() const {
                return *m_ptr;
            }
            pointer operator->() {
                return m_ptr;
            }
            const pointer operator->() const {
                return m_ptr;
            }
            reverse_iterator& operator++() {
                --m_ptr;
                return *this;
            }
            reverse_iterator& operator--() {
                ++m_ptr;
                return *this;
            }
            reverse_iterator operator+(difference_type n) const {
                return reverse_iterator(m_ptr - n);
            }
            reverse_iterator operator-(difference_type n) const {
                return reverse_iterator(m_ptr + n);
            }
            difference_type operator-(const reverse_iterator& other) const {
                return m_ptr + other.m_ptr;
            }
            bool operator==(const reverse_iterator& other) const {
                return m_ptr == other.m_ptr;
            }
            bool operator!=(const reverse_iterator& other) const {
                return m_ptr != other.m_ptr;
            }
            bool operator<(const reverse_iterator& other) const {
                return m_ptr < other.m_ptr;
            }
            bool operator>(const reverse_iterator& other) const {
                return m_ptr > other.m_ptr;
            }
            bool operator<=(const reverse_iterator& other) const {
                return m_ptr <= other.m_ptr;
            }
            bool operator>=(const reverse_iterator& other) const {
                return m_ptr >= other.m_ptr;
            }
        private:
            pointer m_ptr;
        };

        struct const_reverse_iterator {
            //this iterator compatible with stl
            using iterator_category = std::random_access_iterator_tag;
            using value_type = const T;
            using difference_type = std::ptrdiff_t;
            using pointer = const T*;
            using reference = const T&;
            friend List;
            const_reverse_iterator(pointer ptr) : m_ptr(ptr) {}
            reference operator*() {
                return *m_ptr;
            }
            const reference operator*() const {
                return *m_ptr;
            }
            pointer operator->() {
                return m_ptr;
            }
            const pointer operator->() const {
                return m_ptr;
            }
            const_reverse_iterator& operator++() {
                --m_ptr;
                return *this;
            }
            const_reverse_iterator& operator--() {
                ++m_ptr;
                return *this;
            }
            const_reverse_iterator operator+(difference_type n) const {
                return const_reverse_iterator(m_ptr - n);
            }
            const_reverse_iterator operator-(difference_type n) const {
                return const_reverse_iterator(m_ptr + n);
            }
            difference_type operator-(const const_reverse_iterator& other) const {
                return m_ptr + other.m_ptr;
            }
            bool operator==(const const_reverse_iterator& other) const {
                return m_ptr == other.m_ptr;
            }
            bool operator!=(const const_reverse_iterator& other) const {
                return m_ptr != other.m_ptr;
            }
            bool operator<(const const_reverse_iterator& other) const {
                return m_ptr < other.m_ptr;
            }
            bool operator>(const const_reverse_iterator& other) const {
                return m_ptr > other.m_ptr;
            }
            bool operator<=(const const_reverse_iterator& other) const {
                return m_ptr <= other.m_ptr;
            }
            bool operator>=(const const_reverse_iterator& other) const {
                return m_ptr >= other.m_ptr;
            }
        private:
            pointer m_ptr;
        };

        iterator begin()
    	{
            return iterator(m_head);
        }

        const_iterator begin() const
    	{
            return const_iterator(m_head);
        }

        iterator end()
    	{
            return iterator(nullptr);
        }

        const_iterator end() const
    	{
            return const_iterator(nullptr);
        }

        reverse_iterator rbegin()
    	{
            return reverse_iterator(m_tail);
        }

        reverse_iterator rend()
    	{
            return reverse_iterator(nullptr);
        }

        iterator find(const T& value)
        {
            Node* current = m_head;
            while (current) {
                if (current->m_data == value)
                    return iterator(&current->m_data);
                current = current->m_next;
            }
            return end();
        }

        const_iterator find(const T& value) const
        {
            Node* current = m_head;
            while (current) {
                if (current->m_data == value)
                    return const_iterator(&current->m_data);
                current = current->m_next;
            }
            return end();
        }

        /*reverse_iterator find_reverse(const T& value) {
            Node* current = m_tail;
            while (current) {
                if (current->m_data == value)
                    return reverse_iterator(&current->m_data);
                current = current->m_prev;
            }
            return rend();
        }*/

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
    };

} // namespace mylib

#endif // MYLIB_LIST_H