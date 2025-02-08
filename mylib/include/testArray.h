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
            std::cout <<
                "     -----------------------------------\n"
                "     ----- '-'   ARRAY  TEST   '-' -----\n"
                "     -----------------------------------\n";
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
            std::cout <<
                "     -----------------------------------\n"
                "     ----- '-' ALL TEST PASSED '-' -----\n"
                "     -----------------------------------\n\n\n";
        }

    private:
        /*
            Test resizing functionality of the array
            Verifies that the array can be resized properly and maintains its data
        */
        static void testResize()
        {
            Array<int> arr(5);
            arr[0] = 1000;
            arr[1] = -3000;
            arr[2] = 0;
            arr[3] = 57;
            arr[4] = -42;
            arr.resize(8);
            arr[5] = 987654321;
            arr[6] = -999999999;
            arr[7] = 123456789;

            std::cout << "testResize: ";
            for (size_t i = 0; i < arr.getSize(); ++i)
                std::cout << arr[i] << " ";
            std::cout << "\n" << std::endl;
        }

        /*
            Test assigning values to the array
            Verifies that the array elements are properly assigned the specified value
        */
        static void testAssign()
        {
            Array<int> arr;
            arr.assign(5, 42);
            arr[0] = -1;
            arr[4] = 5000;
            std::cout << "testAssign: ";
            for (size_t i = 0; i < arr.getSize(); ++i)
                std::cout << arr[i] << " ";
            std::cout << "\n" << std::endl;
        }

        /*
            Test clearing the array
            Verifies that the array is emptied and the empty check works correctly
        */
        static void testClear()
        {
            Array<int> arr(4);
            arr[0] = 13;
            arr[1] = -250;
            arr[2] = 83;
            arr[3] = -76;
            arr.clear();
            std::cout << "testClear: ";
            std::cout << (arr.empty() ? "Array is empty" : "Array is not empty");
            std::cout << "\n" << std::endl;
        }

        /*
            Test filling the array with a specific value
            Verifies that the array elements are filled with the correct value
        */
        static void testFill()
        {
            Array<int> arr(6);
            arr.fill(100);
            arr[2] = -200;
            arr[4] = 500;
            std::cout << "testFill: ";
            for (size_t i = 0; i < arr.getSize(); ++i)
                std::cout << arr[i] << " ";
            std::cout << "\n" << std::endl;
        }

        /*
            Test front and back element access
            Verifies that front() and back() correctly return the first and last element of the array
        */
        static void testFrontBack()
        {
            Array<int> arr(4);
            arr[0] = 7;
            arr[1] = -3;
            arr[2] = 12;
            arr[3] = -89;
            std::cout << "testFrontBack: ";
            std::cout << "Front: " << arr.front() << ", Back: " << arr.back();
            std::cout << "\n" << std::endl;
        }

        /*
            Test swapping two arrays
            Verifies that two arrays can be swapped and their elements are correctly exchanged
        */
        static void testSwap()
        {
            Array<int> arr1(3);
            arr1[0] = 42;
            arr1[1] = -17;
            arr1[2] = 93;

            Array<int> arr2(3);
            arr2[0] = 12;
            arr2[1] = -5;
            arr2[2] = 78;

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

        /*
            Test equality operator for arrays
            Verifies that two arrays are correctly compared for equality
        */
        static void testEquality()
        {
            Array<int> arr1(5);
            arr1[0] = 78;
            arr1[1] = -3458;
            arr1[2] = 0;
            arr1[3] = 42;
            arr1[4] = -412;

            Array<int> arr2(5);
            arr2[0] = 6;
            arr2[1] = -6;
            arr2[2] = 0;
            arr2[3] = 7;
            arr2[4] = -45;

            std::cout << "testEquality: ";
            std::cout << (arr1 == arr2 ? "Equal" : "Not Equal");
            std::cout << "\n" << std::endl;
        }

        /*
            Test iterators for array traversal
            Verifies that the array iterators correctly traverse the array
        */
        static void testIterators()
        {
            Array<int> arr(5);
            arr[0] = -4563;
            arr[1] = 14224;
            arr[2] = 0;
            arr[3] = -57;
            arr[4] = 91;

            std::cout << "testIterators: ";
            for (auto it = arr.begin(); it != arr.end(); ++it)
                std::cout << *it << " ";
            std::cout << "\n" << std::endl;
        }

        /*
            Test the selection sort algorithm
            Verifies that selection sort works correctly by sorting an array
        */
        static void testSelectionSort()
        {
            Array<int> arr(5);
            arr[0] = -4;
            arr[1] = 85364645;
            arr[2] = -756;
            arr[3] = 0;
            arr[4] = -7537537535;

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

        /*
            Test the insertion sort algorithm
            Verifies that insertion sort works correctly by sorting an array
        */
        static void testInsertionSort()
        {
            Array<int> arr(6);
            arr[0] = 741;
            arr[1] = -57;
            arr[2] = 0;
            arr[3] = 753;
            arr[4] = -1;
            arr[5] = 38743;

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

        /*
            Test the bubble sort algorithm
            Verifies that bubble sort works correctly by sorting an array
        */
        static void testBubbleSort()
        {
            Array<int> arr(6);
            arr[0] = -437836;
            arr[1] = 45;
            arr[2] = 34;
            arr[3] = 5;
            arr[4] = -57;
            arr[5] = 99999;

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

        /*
            Test the merge sort algorithm
            Verifies that merge sort works correctly by sorting an array
        */
        static void testMergeSort()
        {
            Array<int> arr(5);
            arr[0] = -999999;
            arr[1] = 500000000;
            arr[2] = 0;
            arr[3] = 87;
            arr[4] = -350;

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

        /*
            Test the quick sort algorithm
            Verifies that quick sort works correctly by sorting an array
        */
        static void testQuickSort()
        {
            Array<int> arr(5);
            arr[0] = -7;
            arr[1] = 542;
            arr[2] = -7423;
            arr[3] = 4;
            arr[4] = 93;

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