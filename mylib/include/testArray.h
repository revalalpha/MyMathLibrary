#ifndef TEST_ARRAY_H
#define TEST_ARRAY_H

#include <iostream>

#include "MyArray.h"
#include "MyAlgo.h"

namespace mylib {
    class testArray {
    public:
        static void runTests()
        {
            testResize();
            testAssign();
            testClear();
            testFill();
            testFrontBack();
            testSwap();
            testEquality();
            testIterators();
            testSelectionSort();
            testInsertionSort();
            testBubbleSort();
            testMergeSort();
            testQuickSort();
        }

    private:
        static void testResize()
        {
            Array<int> arr(3);
            arr[0] = 10;
            arr[1] = 20;
            arr[2] = 30;
            arr.resize(5);
            std::cout << "testResize: ";
            for (size_t i = 0; i < arr.getSize(); ++i)
                std::cout << arr[i] << " ";
            std::cout << "\n" << std::endl;
        }

        static void testAssign()
        {
            Array<int> arr;
            arr.assign(5, 10);
            std::cout << "testAssign: ";
            for (size_t i = 0; i < arr.getSize(); ++i)
                std::cout << arr[i] << " ";
            std::cout << "\n" << std::endl;
        }

        static void testClear()
        {
            Array<int> arr(3);
            arr[0] = 10;
            arr[1] = 20;
            arr[2] = 30;
            arr.clear();
            std::cout << "testClear: ";
            std::cout << (arr.empty() ? "Array is empty" : "Array is not empty");
            std::cout << "\n" << std::endl;
        }

        static void testFill()
        {
            Array<int> arr(3);
            arr.fill(7);
            std::cout << "testFill: ";
            for (size_t i = 0; i < arr.getSize(); ++i)
                std::cout << arr[i] << " ";
            std::cout << "\n" << std::endl;
        }

        static void testFrontBack()
        {
            Array<int> arr(3);
            arr[0] = 10;
            arr[1] = 20;
            arr[2] = 30;
            std::cout << "testFrontBack: ";
            std::cout << "Front: " << arr.front() << ", Back: " << arr.back();
            std::cout << "\n" << std::endl;
        }

        static void testSwap()
        {
            Array<int> arr1(3);
            arr1[0] = 10;
            arr1[1] = 20;
            arr1[2] = 30;

            Array<int> arr2(3);
            arr2[0] = 100;
            arr2[1] = 200;
            arr2[2] = 300;

            arr1.swap(arr2);
            std::cout << "testSwap: ";
            std::cout << "arr1: ";
            for (size_t i = 0; i < arr1.getSize(); ++i)
                std::cout << arr1[i] << " ";
            std::cout << "| arr2: ";
            for (size_t i = 0; i < arr2.getSize(); ++i)
                std::cout << arr2[i] << " ";
            std::cout << "\n" << std::endl;
        }

        static void testEquality()
        {
            Array<int> arr1(3);
            arr1[0] = 10;
            arr1[1] = 20;
            arr1[2] = 30;

            Array<int> arr2(3);
            arr2[0] = 10;
            arr2[1] = 20;
            arr2[2] = 30;

            std::cout << "testEquality: ";
            std::cout << (arr1 == arr2 ? "Equal" : "Not Equal");
            std::cout << "\n" << std::endl;
        }

        static void testIterators()
        {
            Array<int> arr(3);
            arr[0] = 10;
            arr[1] = 20;
            arr[2] = 30;

            std::cout << "testIterators: ";
            for (auto it = arr.begin(); it != arr.end(); ++it)
                std::cout << *it << " ";
            std::cout << "\n" << std::endl;
        }

        static void testSelectionSort()
        {
            Array<int> arr(5);
            arr[0] = 4;
            arr[1] = 2;
            arr[2] = 5;
            arr[3] = 1;
            arr[4] = 3;

            std::cout << "Original Array for SelectionSort: ";
            for (size_t i = 0; i < arr.getSize(); ++i)
                std::cout << arr[i] << " ";
            std::cout << std::endl;

            mylib::algorithms::selectionSort(arr.dataPointer(), arr.dataPointer() + arr.getSize());

            std::cout << "Sorted with SelectionSort: ";
            for (size_t i = 0; i < arr.getSize(); ++i)
                std::cout << arr[i] << " ";
            std::cout << "\n" << std::endl;
        }

        static void testInsertionSort()
        {
            Array<int> arr(5);
            arr[0] = 4;
            arr[1] = 2;
            arr[2] = 5;
            arr[3] = 1;
            arr[4] = 3;

            std::cout << "Original Array for InsertionSort: ";
            for (size_t i = 0; i < arr.getSize(); ++i)
                std::cout << arr[i] << " ";
            std::cout << std::endl;

            mylib::algorithms::insertionSort(arr.dataPointer(), arr.dataPointer() + arr.getSize());

            std::cout << "Sorted with InsertionSort: ";
            for (size_t i = 0; i < arr.getSize(); ++i)
                std::cout << arr[i] << " ";
            std::cout << "\n" << std::endl;
        }

        static void testBubbleSort()
        {
            Array<int> arr(5);
            arr[0] = 4;
            arr[1] = 2;
            arr[2] = 5;
            arr[3] = 1;
            arr[4] = 3;

            std::cout << "Original Array for BubbleSort: ";
            for (size_t i = 0; i < arr.getSize(); ++i)
                std::cout << arr[i] << " ";
            std::cout << std::endl;

            mylib::algorithms::bubbleSort(arr.dataPointer(), arr.dataPointer() + arr.getSize());

            std::cout << "Sorted with BubbleSort: ";
            for (size_t i = 0; i < arr.getSize(); ++i)
                std::cout << arr[i] << " ";
            std::cout << "\n" << std::endl;
        }

        static void testMergeSort()
        {
            Array<int> arr(5);
            arr[0] = 4;
            arr[1] = 2;
            arr[2] = 5;
            arr[3] = 1;
            arr[4] = 3;

            std::cout << "Original Array for MergeSort: ";
            for (size_t i = 0; i < arr.getSize(); ++i)
                std::cout << arr[i] << " ";
            std::cout << std::endl;

            mylib::algorithms::mergeSort(arr.dataPointer(), arr.dataPointer() + arr.getSize());

            std::cout << "Sorted with MergeSort: ";
            for (size_t i = 0; i < arr.getSize(); ++i)
                std::cout << arr[i] << " ";
            std::cout << "\n" << std::endl;
        }

        static void testQuickSort()
        {
            Array<int> arr(5);
            arr[0] = 4;
            arr[1] = 2;
            arr[2] = 5;
            arr[3] = 1;
            arr[4] = 3;

            std::cout << "Original Array for QuickSort: ";
            for (size_t i = 0; i < arr.getSize(); ++i)
                std::cout << arr[i] << " ";
            std::cout << std::endl;

            mylib::algorithms::quickSort(arr.dataPointer(), arr.dataPointer() + arr.getSize());

            std::cout << "Sorted with QuickSort: ";
            for (size_t i = 0; i < arr.getSize(); ++i)
                std::cout << arr[i] << " ";
            std::cout << "\n" << std::endl;
        }

    };
}

#endif // TEST_ARRAY_H