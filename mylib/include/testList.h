#ifndef TEST_LIST_H
#define TEST_LIST_H

#include <iostream>
#include "MyList.h"

namespace mylib {
    class testList {
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
        static void testPushBack()
        {
            mylib::List<int> list;
            list.push_back(10);
            list.push_back(20);
            list.push_back(30);

            std::cout << "testPushBack: ";
            list.print();
        }

        static void testPushFront()
        {
            mylib::List<int> list;
            list.push_front(10);
            list.push_front(20);
            list.push_front(30);

            std::cout << "testPushFront: ";
            list.print();
        }

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

        static void testFind()
        {
            mylib::List<int> list;
            list.push_back(10);
            list.push_back(20);
            list.push_back(30);

            auto it = list.find(20);
            std::cout << "testFind (found 20): " << (it != list.end() ? *it : -1) << std::endl;
        }

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

        static void testAccessors()
        {
            mylib::List<int> list;
            list.push_back(10);
            list.push_back(20);
            list.push_back(30);

            std::cout << "testAccessors (front): " << list.front() << std::endl;
            std::cout << "testAccessors (back): " << list.back() << std::endl;
        }

        static void testSize()
        {
            mylib::List<int> list;
            list.push_back(10);
            list.push_back(20);

            std::cout << "testSize: " << list.getSize() << std::endl;
        }

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
