#ifndef TEST_INTRUSIVE_LIST_H
#define TEST_INTRUSIVE_LIST_H

#include <iostream>
#include "MyIntrusiveList.h"

namespace mylib {
    // Test class for IntrusiveList
    class testIntrusiveList {
    public:
        static void runTests()
        {
            std::cout <<
                "     -----------------------------------\n"
                "     ----- '-'   INTRUSIVE LIST TEST   '-' -----\n"
                "     -----------------------------------\n";

            testPushBack();
            testPushFront();
            testPopBack();
            testPopFront();
            testRemove();
            testFind();
            testIterators();
            testAccessors();
            testSize();
            testEmpty();
            testPushBackForDouble();
            testPushFrontForDouble();
            testPopBackForDouble();
            testPopFrontForDouble();
            testRemoveForDouble();
            testFindForDouble();
            testIteratorsForDouble();
            testAccessorsForDouble();
            testSizeForDouble();
            testEmptyForDouble();

            std::cout <<
                "     -----------------------------------\n"
                "     ----- '-' ALL TEST PASSED '-' -----\n"
                "     -----------------------------------\n\n\n";
        }

    private:
        // Test for push_back function
        static void testPushBack()
        {
            mylib::IntrusiveList<int> list;
            int a = -5, b = 14, c = 151;
            list.push_back(a);
            list.push_back(b);
            list.push_back(c);

            std::cout << "testPushBack: ";
            for (auto it = list.begin(); it != list.end(); ++it)
                std::cout << *it << " ";
            std::cout << std::endl;
        }

        // Test for push_front function
        static void testPushFront()
        {
            mylib::IntrusiveList<int> list;
            int a = 1148, b = 0.485, c = -47;
            list.push_front(a);
            list.push_front(b);
            list.push_front(c);

            std::cout << "testPushFront: ";
            for (auto it = list.begin(); it != list.end(); ++it)
                std::cout << *it << " ";
            std::cout << std::endl;
        }

        // Test for pop_back function
        static void testPopBack()
        {
            mylib::IntrusiveList<int> list;
            int a = 0, b = 8, c = -5;
            list.push_back(a);
            list.push_back(b);
            list.push_back(c);
            list.pop_back();

            std::cout << "testPopBack: ";
            for (auto it = list.begin(); it != list.end(); ++it)
                std::cout << *it << " ";
            std::cout << std::endl;
        }

        // Test for pop_front function
        static void testPopFront()
        {
            mylib::IntrusiveList<int> list;
            int a = 151, b = 1551, c = -47;
            list.push_back(a);
            list.push_back(b);
            list.push_back(c);
            list.pop_front();

            std::cout << "testPopFront: ";
            for (auto it = list.begin(); it != list.end(); ++it)
                std::cout << *it << " ";
            std::cout << std::endl;
        }

        // Test for remove function
        static void testRemove()
        {
            mylib::IntrusiveList<int> list;
            int a = 0, b = 8, c = -5;
            list.push_back(a);
            list.push_back(b);
            list.push_back(c);
            list.remove(b);

            std::cout << "testRemove: ";
            for (auto it = list.begin(); it != list.end(); ++it)
                std::cout << *it << " ";
            std::cout << std::endl;
        }

        // Test for find function
        static void testFind()
        {
            mylib::IntrusiveList<int> list;
            int a = -5, b = 14, c = 151;
            list.push_back(a);
            list.push_back(b);
            list.push_back(c);

            auto it = list.begin();
            for (; it != list.end(); ++it) 
            {
                if (*it == 14) {
                    std::cout << "testFind (found 14): " << *it << std::endl;
                    break;
                }
            }
            if (it == list.end())
                std::cout << "testFind (not found): " << -1 << std::endl;
        }

        // Test for iterators
        static void testIterators()
        {
            mylib::IntrusiveList<int> list;
            int a = 1148, b = 1551, c = -47;
            list.push_back(a);
            list.push_back(b);
            list.push_back(c);

            std::cout << "testIterators: ";
            for (auto it = list.begin(); it != list.end(); ++it)
                std::cout << *it << " ";
            std::cout << std::endl;
        }

        // Test for accessors (first and last elements)
        static void testAccessors()
        {
            mylib::IntrusiveList<int> list;
            int a = 0, b = 8, c = -5;
            list.push_back(a);
            list.push_back(b);
            list.push_back(c);

            std::cout << "testAccessors (front): " << (list.begin() != list.end() ? *list.begin() : -1) << std::endl;

            auto it = list.end();
            --it;
            std::cout << "testAccessors (back): " << (it != list.end() ? *it : -1) << std::endl;
        }

        // Test for getSize function
        static void testSize()
        {
            mylib::IntrusiveList<int> list;
            int a = -5, b = 14;
            list.push_back(a);
            list.push_back(b);

            std::cout << "testSize: " << list.getSize() << std::endl;
        }

        // Test for empty function
        static void testEmpty()
        {
            mylib::IntrusiveList<int> list;

            std::cout << "testEmpty: " << (list.empty() ? "Empty" : "Not Empty") << std::endl;
            int a = 8;
            list.push_back(a);
            std::cout << "testEmpty after push_back: " << (list.empty() ? "Empty" : "Not Empty") << std::endl;
        }

        // Test for push_back function with double
        static void testPushBackForDouble()
        {
            mylib::IntrusiveList<double> list;
            double a = -5.5, b = 14.14, c = 151.1;
            list.push_back(a);
            list.push_back(b);
            list.push_back(c);

            std::cout << "testPushBack (double): ";
            for (auto it = list.begin(); it != list.end(); ++it)
                std::cout << *it << " ";
            std::cout << std::endl;
        }

        // Test for push_front function with double
        static void testPushFrontForDouble()
        {
            mylib::IntrusiveList<double> list;
            double a = 1148.2, b = 1551.33, c = -47.6;
            list.push_front(a);
            list.push_front(b);
            list.push_front(c);

            std::cout << "testPushFront (double): ";
            for (auto it = list.begin(); it != list.end(); ++it)
                std::cout << *it << " ";
            std::cout << std::endl;
        }

        // Test for pop_back function with double
        static void testPopBackForDouble()
        {
            mylib::IntrusiveList<double> list;
            double a = 0.8, b = 8.3, c = -5.2;
            list.push_back(a);
            list.push_back(b);
            list.push_back(c);
            list.pop_back();

            std::cout << "testPopBack (double): ";
            for (auto it = list.begin(); it != list.end(); ++it)
                std::cout << *it << " ";
            std::cout << std::endl;
        }

        // Test for pop_front function with double
        static void testPopFrontForDouble()
        {
            mylib::IntrusiveList<double> list;
            double a = 151.5, b = 1551.99, c = -47.3;
            list.push_back(a);
            list.push_back(b);
            list.push_back(c);
            list.pop_front();

            std::cout << "testPopFront (double): ";
            for (auto it = list.begin(); it != list.end(); ++it)
                std::cout << *it << " ";
            std::cout << std::endl;
        }

        // Test for remove function with double
        static void testRemoveForDouble()
        {
            mylib::IntrusiveList<double> list;
            double a = 0.5, b = 14.2, c = -5.8;
            list.push_back(a);
            list.push_back(b);
            list.push_back(c);
            list.remove(b);

            std::cout << "testRemove (double): ";
            for (auto it = list.begin(); it != list.end(); ++it)
                std::cout << *it << " ";
            std::cout << std::endl;
        }

        // Test for find function with double
        static void testFindForDouble()
        {
            mylib::IntrusiveList<double> list;
            double a = -5.5, b = 14.14, c = 151.1;
            list.push_back(a);
            list.push_back(b);
            list.push_back(c);

            auto it = list.begin();
            for (; it != list.end(); ++it)
            {
                if (*it == 14.14) {
                    std::cout << "testFind (found 14.14): " << *it << std::endl;
                    break;
                }
            }
            if (it == list.end()) {
                std::cout << "testFind (not found): " << -1 << std::endl;
            }
        }

        // Test for iterators with double
        static void testIteratorsForDouble()
        {
            mylib::IntrusiveList<double> list;
            double a = 1148.3, b = 1551.75, c = -47.25;
            list.push_back(a);
            list.push_back(b);
            list.push_back(c);

            std::cout << "testIterators (double): ";
            for (auto it = list.begin(); it != list.end(); ++it)
                std::cout << *it << " ";
            std::cout << std::endl;
        }

        // Test for accessors (first and last elements) with double
        static void testAccessorsForDouble()
        {
            mylib::IntrusiveList<double> list;
            double a = 0.8, b = 8.3, c = -5.2;
            list.push_back(a);
            list.push_back(b);
            list.push_back(c);

            std::cout << "testAccessors (front): " << (list.begin() != list.end() ? *list.begin() : -1.0) << std::endl;

            auto it = list.end();
            --it;
            std::cout << "testAccessors (back): " << (it != list.end() ? *it : -1.0) << std::endl;
        }

        // Test for getSize function with double
        static void testSizeForDouble()
        {
            mylib::IntrusiveList<double> list;
            double a = -5.5, b = 14.14;
            list.push_back(a);
            list.push_back(b);

            std::cout << "testSize (double): " << list.getSize() << std::endl;
        }

        // Test for empty function with double
        static void testEmptyForDouble()
        {
            mylib::IntrusiveList<double> list;

            std::cout << "testEmpty (double): " << (list.empty() ? "Empty" : "Not Empty") << std::endl;
            double a = 8.3;
            list.push_back(a);
            std::cout << "testEmpty after push_back (double): " << (list.empty() ? "Empty" : "Not Empty") << std::endl;
        }
    };
}

#endif // TEST_INTRUSIVE_LIST_H
