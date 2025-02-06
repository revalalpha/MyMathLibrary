#ifndef TEST_VECTOR_H
#define TEST_VECTOR_H

#include <iostream>
#include "MyVector.h"
#include "MyAlgo.h"

namespace mylib {
    class testVector {
    public:
        static void runTests()
        {
            testPushBack();
            testPopBack();
            testInsert();
            testErase();
            testResize();
            testReserve();
            testEquality();
            testAssign();
            testSelectionSort();
            testInsertionSort();
            testBubbleSort();
            testMergeSort();
            testQuickSort();

        }

    private:
        static void testPushBack()
        {
            Vector<int> vec;
            vec.push_back(10);
            vec.push_back(20);
            vec.push_back(30);

            std::cout << "testPushBack: ";
            printVector(vec);
        }

        static void testPopBack()
        {
            Vector<int> vec;
            vec.push_back(10);
            vec.push_back(20);
            vec.push_back(30);
            vec.pop_back();

            std::cout << "testPopBack: ";
            printVector(vec);
        }

        static void testInsert()
        {
            Vector<int> vec;
            vec.push_back(10);
            vec.push_back(30);
            vec.insert(1, 20);

            std::cout << "testInsert: ";
            printVector(vec);
        }

        static void testErase()
        {
            Vector<int> vec;
            vec.push_back(10);
            vec.push_back(20);
            vec.push_back(30);
            vec.erase(1);

            std::cout << "testErase: ";
            printVector(vec);
        }

        static void testResize()
        {
            Vector<int> vec;
            vec.push_back(10);
            vec.push_back(20);
            vec.resize(5);

            std::cout << "testResize: ";
            printVector(vec);
        }

        static void testReserve()
        {
            Vector<int> vec;
            vec.push_back(10);
            vec.push_back(20);
            vec.reserve(10);

            std::cout << "testReserve: ";
            printVector(vec);
        }

        static void testEquality()
        {
            Vector<int> vec1, vec2;
            vec1.push_back(10);
            vec1.push_back(20);
            vec2.push_back(10);
            vec2.push_back(20);

            std::cout << "testEquality: ";
            std::cout << (vec1 == vec2 ? "Equal" : "Not Equal") << std::endl;
        }

        static void testAssign()
        {
            mylib::Vector<int> vec;
            vec.assign(5, 10);
            std::cout << "After assign(5, 10): ";
            for (unsigned int i = 0; i < vec.size(); ++i)
                std::cout << vec[i] << " ";
            std::cout << std::endl;
        }

        static void testSelectionSort()
        {
            Vector<int> vec;
            vec.push_back(4);
            vec.push_back(2);
            vec.push_back(5);
            vec.push_back(1);
            vec.push_back(3);

            std::cout << "Original Vector for SelectionSort: ";
            printVector(vec);

            algorithms::selectionSort(vec.data(), vec.data() + vec.size());

            std::cout << "Sorted with SelectionSort: ";
            printVector(vec);
            std::cout << std::endl;
        }

        static void testInsertionSort()
        {
            Vector<int> vec;
            vec.push_back(4);
            vec.push_back(2);
            vec.push_back(5);
            vec.push_back(1);
            vec.push_back(3);

            std::cout << "Original Vector for InsertionSort: ";
            printVector(vec);

            algorithms::insertionSort(vec.data(), vec.data() + vec.size());

            std::cout << "Sorted with InsertionSort: ";
            printVector(vec);
            std::cout << std::endl;
        }

        static void testBubbleSort()
        {
            Vector<int> vec;
            vec.push_back(4);
            vec.push_back(2);
            vec.push_back(5);
            vec.push_back(1);
            vec.push_back(3);

            std::cout << "Original Vector for BubbleSort: ";
            printVector(vec);

            algorithms::bubbleSort(vec.data(), vec.data() + vec.size());

            std::cout << "Sorted with BubbleSort: ";
            printVector(vec);
            std::cout << std::endl;
        }

        static void testMergeSort()
        {
            Vector<int> vec;
            vec.push_back(4);
            vec.push_back(2);
            vec.push_back(5);
            vec.push_back(1);
            vec.push_back(3);

            std::cout << "Original Vector for MergeSort: ";
            printVector(vec);

            algorithms::mergeSort(vec.data(), vec.data() + vec.size());

            std::cout << "Sorted with MergeSort: ";
            printVector(vec);
            std::cout << std::endl;
        }

        static void testQuickSort()
        {
            Vector<int> vec;
            vec.push_back(4);
            vec.push_back(2);
            vec.push_back(5);
            vec.push_back(1);
            vec.push_back(3);

            std::cout << "Original Vector for QuickSort: ";
            printVector(vec);

            algorithms::quickSort(vec.data(), vec.data() + vec.size());

            std::cout << "Sorted with QuickSort: ";
            printVector(vec);
            std::cout << std::endl;
        }

        static void printVector(const Vector<int>& vec)
        {
            for (unsigned int i = 0; i < vec.size(); ++i)
                std::cout << vec[i] << " ";
            std::cout << std::endl;
        }
    };
}

#endif // TEST_VECTOR_H