#ifndef TESTLIST_H
#define TESTLIST_H

#include "MyList.h"
#include "MyAlgo.h"
#include <cassert>

namespace mylib
{
    class testList {
    public:
        static void runTests() {
            testPushPop();
            testFrontBack();
            testSizeEmpty();
            testClear();
            /*testErase();*/
            testIterators();
            testCopyAssignment();
            testPrint();
        }

    private:
        static void testPushPop() {
            mylib::List<int> list;
            list.push_back(10);
            list.push_back(20);
            list.push_front(5);
            assert(list.front() == 5);
            assert(list.back() == 20);

            list.pop_back();
            assert(list.back() == 10);

            list.pop_front();
            assert(list.front() == 10);
        }

        static void testFrontBack() {
            mylib::List<int> list;
            list.push_back(100);
            list.push_back(200);
            assert(list.front() == 100);
            assert(list.back() == 200);
        }

        static void testSizeEmpty() {
            mylib::List<int> list;
            assert(list.empty());
            assert(list.size() == 0);

            list.push_back(1);
            assert(!list.empty());
            assert(list.size() == 1);

            list.push_back(2);
            assert(list.size() == 2);

            list.pop_front();
            assert(list.size() == 1);
        }

        static void testClear() {
            mylib::List<int> list;
            list.push_back(10);
            list.push_back(20);
            list.push_back(30);
            assert(!list.empty());

            list.clear();
            assert(list.empty());
            assert(list.size() == 0);
        }

        /*static void testErase() {
            mylib::List<int> list;
            list.push_back(1);
            list.push_back(2);
            list.push_back(3);
            list.push_back(4);

            auto it = list.begin();
            ++it;
            list.erase(it);
            assert(list.size() == 3);

            it = list.begin();
            assert(*it == 1);

            ++it;
            assert(*it == 3);
        }*/

        static void testIterators() {
            mylib::List<int> list;
            list.push_back(10);
            list.push_back(20);
            list.push_back(30);

            auto it = list.begin();
            assert(*it == 10);
            ++it;
            assert(*it == 20);
            ++it;
            assert(*it == 30);
            ++it;
            assert(it == list.end());

            auto rit = list.rbegin();
            assert(*rit == 30);
            ++rit;
            assert(*rit == 20);
            ++rit;
            assert(*rit == 10);
            ++rit;
            assert(rit == list.rend());
        }

        static void testCopyAssignment() {
            mylib::List<int> list1;
            list1.push_back(1);
            list1.push_back(2);
            list1.push_back(3);

            mylib::List<int> list2;
            list2 = list1;

            assert(list2.size() == 3);
            assert(list2.front() == 1);
            assert(list2.back() == 3);
        }

        static void testPrint() {
            mylib::List<int> list;
            list.push_back(1);
            list.push_back(2);
            list.push_back(3);

            char buffer[50];
            list.print();
            assert(buffer[0] == '1');
            assert(buffer[2] == '2');
            assert(buffer[4] == '3');

            char revBuffer[50];
            list.reversePrint();
            assert(revBuffer[0] == '3');
            assert(revBuffer[2] == '2');
            assert(revBuffer[4] == '1');
        }
    };
} 

#endif // TESTLIST_H
