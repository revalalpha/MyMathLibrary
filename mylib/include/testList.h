#ifndef TEST_LIST_H
#define TEST_LIST_H

#include <iostream>
#include "MyList.h"

namespace mylib
{
    class testList
	{
    public:
        static void runTests()
        {
            std::cout <<
                "     -----------------------------------\n"
                "     ----- '-'   LIST TEST   '-' -----\n"
                "     -----------------------------------\n";

            testPushBack();
            testPushFront();
            testPopBack();
            testPopFront();
            testRemove();
            testFind();
            testInsert();
            testErase();
            testReverse();
            testIterators();
            testReverseIterators();
            testAccessors();
            testSize();
            testEmpty();

            std::cout <<
                "     -----------------------------------\n"
                "     ----- '-' ALL TEST PASSED '-' -----\n"
                "     -----------------------------------\n\n\n";
        }

    private:
        // Test for pushing elements to the back of the list
        static void testPushBack()
        {
            mylib::List<int> list;
            list.push_back(10);
            list.push_back(20);
            list.push_back(30);

            std::cout << "testPushBack: ";
            list.print();
        }

        // Test for pushing elements to the front of the list
        static void testPushFront()
        {
            mylib::List<int> list;
            list.push_front(10);
            list.push_front(20);
            list.push_front(30);

            std::cout << "testPushFront: ";
            list.print();
        }

        // Test for popping elements from the back of the list
        static void testPopBack()
        {
            mylib::List<int> list;
            list.push_back(10);
            list.push_back(20);
            list.push_back(30);
            list.pop_back();

            std::cout << "testPopBack: ";
            list.print();
        }

        // Test for popping elements from the front of the list
        static void testPopFront()
        {
            mylib::List<int> list;
            list.push_back(10);
            list.push_back(20);
            list.push_back(30);
            list.pop_front();

            std::cout << "testPopFront: ";
            list.print();
        }

        // Test for removing a specific element from the list
        static void testRemove()
        {
            mylib::List<int> list;
            list.push_back(10);
            list.push_back(20);
            list.push_back(30);
            list.remove(20);

            std::cout << "testRemove: ";
            list.print();
        }

        // Test for finding an element in the list
        static void testFind()
        {
            mylib::List<int> list;
            list.push_back(10);
            list.push_back(20);
            list.push_back(30);

            auto it = list.find(20);
            std::cout << "testFind (found 20): " << (it != list.end() ? *it : -1) << std::endl;
        }

        // Test for inserting an element in the list
        static void testInsert()
        {
            mylib::List<int> list;
            list.push_back(10);
            list.push_back(30);

            auto it = list.begin();
            list.insert(++it, 20);

            std::cout << "testInsert: ";
            list.print();
        }

        // Test for erasing an element from the list
        static void testErase()
        {
            mylib::List<int> list;
            list.push_back(10);
            list.push_back(20);
            list.push_back(30);

            auto it = list.begin();
            list.erase(++it);

            std::cout << "testErase: ";
            list.print();
        }

        // Test for reversing the list
        static void testReverse()
        {
            mylib::List<int> list;
            list.push_back(10);
            list.push_back(20);
            list.push_back(30);
            list.reverse();

            std::cout << "testReverse: ";
            list.print();
        }

        // Test for iterating over the list with normal iterators
        static void testIterators()
        {
            mylib::List<int> list;
            list.push_back(10);
            list.push_back(20);
            list.push_back(30);

            std::cout << "testIterators: ";
            for (auto it = list.begin(); it != list.end(); ++it) {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }

        // Test for iterating over the list with reverse iterators
        static void testReverseIterators()
        {
            mylib::List<int> list;
            list.push_back(10);
            list.push_back(20);
            list.push_back(30);

            std::cout << "testReverseIterators: ";
            for (auto it = list.rbegin(); it != list.rend(); --it) {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }

        // Test for accessing the front and back elements of the list
        static void testAccessors()
        {
            mylib::List<int> list;
            list.push_back(10);
            list.push_back(20);
            list.push_back(30);

            std::cout << "testAccessors (front): " << list.front() << std::endl;
            std::cout << "testAccessors (back): " << list.back() << std::endl;
        }

        // Test for getting the size of the list
        static void testSize()
        {
            mylib::List<int> list;
            list.push_back(10);
            list.push_back(20);

            std::cout << "testSize: " << list.getSize() << std::endl;
        }

        // Test for checking if the list is empty
        static void testEmpty()
        {
            mylib::List<int> list;

            std::cout << "testEmpty: " << (list.empty() ? "Empty" : "Not Empty") << std::endl;
            list.push_back(10);
            std::cout << "testEmpty after push_back: " << (list.empty() ? "Empty" : "Not Empty") << std::endl;
        }
    };
}
#endif // TEST_LIST_H
