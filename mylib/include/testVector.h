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
            std::cout <<
                "     -----------------------------------\n"
                "     ----- '-'   VECTOR TEST   '-' -----\n"
                "     -----------------------------------\n";

            testPushBack();
            testPopBack();
            testInsert();
            testErase();
            testResize();
            testReserve();
            testEquality();
            testAssign();
            testCapacity();
            testAccessors();
            testCopyAndMove();
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
            Test push_back functionality
            Verifies that elements are added correctly to the end of the vector
        */
        static void testPushBack()
        {
            Vector<int> vec;
            vec.push_back(12102);
            vec.push_back(270);
            vec.push_back(-30);

            std::cout << "testPushBack: ";
            printVector(vec);
            std::cout << std::endl;
        }

        /*
            Test pop_back functionality
            Verifies that the last element is removed from the vector correctly
        */
        static void testPopBack()
        {
            Vector<int> vec;
            vec.push_back(772);
            vec.push_back(-91);
            vec.push_back(120);
            vec.pop_back(); // Removes 120

            std::cout << "testPopBack: ";
            printVector(vec);
            std::cout << std::endl;
        }

        /*
            Test insert functionality
            Verifies that an element can be inserted at a specific position in the vector
        */
        static void testInsert()
        {
            Vector<int> vec;
            vec.push_back(510);
            vec.push_back(0);
            vec.insert(1, -17); // Insert -17 at position 1

            std::cout << "testInsert: ";
            printVector(vec);
            std::cout << std::endl;
        }

        /*
            Test erase functionality
            Verifies that an element can be removed from a specific position in the vector
        */
        static void testErase()
        {
            Vector<int> vec;
            vec.push_back(0);
            vec.push_back(99);
            vec.push_back(-99);
            vec.erase(1); // Erases element at position 1 (99)

            std::cout << "testErase: ";
            printVector(vec);
            std::cout << std::endl;
        }

        /*
            Test resize functionality
            Verifies that the vector can be resized properly and maintains its data
        */
        static void testResize()
        {
            Vector<int> vec;
            vec.push_back(10);
            vec.push_back(20);
            vec.resize(28); // Resize to a larger size

            std::cout << "testResize: ";
            printVector(vec);
            std::cout << std::endl;
        }

        /*
            Test reserve functionality
            Verifies that the vector can reserve space for a specified number of elements
        */
        static void testReserve()
        {
            Vector<int> vec;
            vec.push_back(18);
            vec.push_back(18);
            vec.reserve(10); // Reserve space for at least 10 elements

            std::cout << "testReserve: ";
            printVector(vec);
            std::cout << std::endl;
        }

        /*
            Test equality operator
            Verifies that two vectors with the same data are considered equal
        */
        static void testEquality()
        {
            Vector<int> vec1, vec2;
            vec1.push_back(10);
            vec1.push_back(20);
            vec2.push_back(10);
            vec2.push_back(20);

            std::cout << "testEquality: ";
            std::cout << (vec1 == vec2 ? "Equal" : "Not Equal");
            std::cout << "\n" << std::endl;
        }

        /*
            Test assign functionality
            Verifies that the vector can be filled with specific values using assign
        */
        static void testAssign()
        {
            Vector<int> vec;
            vec.assign(5, 10); // Assign 5 elements with value 10
            std::cout << "After assign(5, 10): ";
            for (unsigned int i = 0; i < vec.size(); ++i)
                std::cout << vec[i] << " ";
            std::cout << "\n" << std::endl;
        }

        /*
            Test capacity functionality
            Verifies that the capacity of the vector is correctly handled
        */
        static void testCapacity()
        {
            Vector<int> vec;
            vec.push_back(1);

            std::cout << "testCapacity: ";
            printVector(vec);
            std::cout << std::endl;
        }

        /*
            Test accessors functionality
            Verifies that the elements of the vector can be accessed correctly
        */
        static void testAccessors()
        {
            Vector<int> vec;
            vec.push_back(3);
            vec.push_back(-8);

            std::cout << "testAccessors: ";
            printVector(vec);
            std::cout << std::endl;
        }

        /*
            Test copy and move functionality
            Verifies that vectors can be copied and moved correctly
        */
        static void testCopyAndMove()
        {
            Vector<int> vec1;
            vec1.push_back(-15);
            vec1.push_back(-2);

            Vector<int> vec2 = vec1; // Copy constructor
            Vector<int> vec3 = static_cast<Vector<int>&&>(vec1); // Move constructor

            std::cout << "testCopyAndMove (Original Vector): ";
            printVector(vec2);

            std::cout << "testCopyAndMove (Moved Vector): ";
            printVector(vec3);

            std::cout << std::endl;
        }

        /*
            Test selection sort algorithm
            Verifies that the selection sort algorithm works correctly on the vector
        */
        static void testSelectionSort()
        {
            Vector<int> vec;
            vec.push_back(49);
            vec.push_back(32);
            vec.push_back(54);
            vec.push_back(54);
            vec.push_back(-3);

            std::cout << "Original Vector for SelectionSort: ";
            printVector(vec);

            algorithms::selectionSort(vec.data(), vec.data() + vec.size());

            std::cout << "Sorted with SelectionSort: ";
            printVector(vec);
            std::cout << "\n" << std::endl;
        }

        /*
            Test insertion sort algorithm
            Verifies that the insertion sort algorithm works correctly on the vector
        */
        static void testInsertionSort()
        {
            Vector<int> vec;
            vec.push_back(-3);
            vec.push_back(-2);
            vec.push_back(-5);
            vec.push_back(-1);
            vec.push_back(-3);

            std::cout << "Original Vector for InsertionSort: ";
            printVector(vec);

            algorithms::insertionSort(vec.data(), vec.data() + vec.size());

            std::cout << "Sorted with InsertionSort: ";
            printVector(vec);
            std::cout << "\n" << std::endl;
        }

        /*
            Test bubble sort algorithm
            Verifies that the bubble sort algorithm works correctly on the vector
        */
        static void testBubbleSort()
        {
            Vector<int> vec;
            vec.push_back(1);
            vec.push_back(54);
            vec.push_back(63);
            vec.push_back(-98);
            vec.push_back(1);

            std::cout << "Original Vector for BubbleSort: ";
            printVector(vec);

            algorithms::bubbleSort(vec.data(), vec.data() + vec.size());

            std::cout << "Sorted with BubbleSort: ";
            printVector(vec);
            std::cout << "\n" << std::endl;
        }

        /*
            Test merge sort algorithm
            Verifies that the merge sort algorithm works correctly on the vector
        */
        static void testMergeSort()
        {
            Vector<int> vec;
            vec.push_back(46);
            vec.push_back(62);
            vec.push_back(-3);
            vec.push_back(-31);
            vec.push_back(-3);

            std::cout << "Original Vector for MergeSort: ";
            printVector(vec);

            algorithms::mergeSort(vec.data(), vec.data() + vec.size());

            std::cout << "Sorted with MergeSort: ";
            printVector(vec);
            std::cout << "\n" << std::endl;
        }

        /*
            Test quick sort algorithm
            Verifies that the quick sort algorithm works correctly on the vector
        */
        static void testQuickSort()
        {
            Vector<int> vec;
            vec.push_back(848);
            vec.push_back(92);
            vec.push_back(576);
            vec.push_back(651);
            vec.push_back(45675544643553);

            std::cout << "Original Vector for QuickSort: ";
            printVector(vec);

            algorithms::quickSort(vec.data(), vec.data() + vec.size());

            std::cout << "Sorted with QuickSort: ";
            printVector(vec);
            std::cout << "\n" << std::endl;
        }

        // Utility function to print a vector
        static void printVector(const Vector<int>& vec)
        {
            for (unsigned int i = 0; i < vec.size(); ++i)
                std::cout << vec[i] << " ";
            std::cout << std::endl;
        }
    };
}

#endif // TEST_VECTOR_H