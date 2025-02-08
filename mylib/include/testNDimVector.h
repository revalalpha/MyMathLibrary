#ifndef TEST_NDIMVECTOR_H
#define TEST_NDIMVECTOR_H

#include <iostream>
#include "MyNDimVector.h"

namespace mylib
{
    class testNDimVector
	{
    public:
        static void runTests()
        {
            std::cout <<
                "     -----------------------------------\n"
                "     -- '-'   N DIM VECTOR TEST   '-' --\n"
                "     -----------------------------------\n";

            testDotProduct();
            testCrossProduct();
            testNorm();
            testNormalize();
            testAddition();
            testSubtraction();
            testScalarMultiplication();
            testScalarDivision();
            testReverse();
            testProjection();
            /*testIterator();   failed */
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
        // Tests the dot product of two vectors
        static void testDotProduct()
    	{
            VectorND<int> vec1({ 1, 2, 3 });
            VectorND<int> vec2({ 4, 5, 6 });

            std::cout << "testDotProduct: ";
            std::cout << vec1.dot(vec2) << std::endl;
        }

        // Tests the cross product of two 3D vectors
        static void testCrossProduct()
    	{
            VectorND<int> vec1({ 1, 2, 3 });
            VectorND<int> vec2({ 4, 5, 6 });

            std::cout << "testCrossProduct: ";
            VectorND<int> result = vec1.cross(vec2);
            for (size_t i = 0; i < result.size(); ++i)
                std::cout << result[i] << " ";
            std::cout << std::endl;
        }

        // Tests the norm (magnitude) of a vector
        static void testNorm()
    	{
            VectorND<int> vec({ 3, 4 });

            std::cout << "testNorm: ";
            std::cout << vec.norm() << std::endl;
        }

        // Tests the normalization of a vector (making it a unit vector)
        static void testNormalize()
    	{
            VectorND<int> vec({ 3, 4 });
            vec.normalize();

            std::cout << "testNormalize: ";
            for (size_t i = 0; i < vec.size(); ++i)
                std::cout << vec[i] << " ";
            std::cout << std::endl;
        }

        // Tests the addition of two vectors
        static void testAddition()
    	{
            VectorND<int> vec1({ 1, 2, 3 });
            VectorND<int> vec2({ 4, 5, 6 });

            std::cout << "testAddition: ";
            VectorND<int> result = vec1 + vec2;
            for (size_t i = 0; i < result.size(); ++i)
                std::cout << result[i] << " ";
            std::cout << std::endl;
        }

        // Tests the subtraction of two vectors
        static void testSubtraction()
    	{
            VectorND<int> vec1({ 1, 2, 3 });
            VectorND<int> vec2({ 4, 5, 6 });

            std::cout << "testSubtraction: ";
            VectorND<int> result = vec1 - vec2;
            for (size_t i = 0; i < result.size(); ++i)
                std::cout << result[i] << " ";
            std::cout << std::endl;
        }

        // Tests the scalar multiplication of a vector
        static void testScalarMultiplication()
    	{
            VectorND<int> vec({ 1, 2, 3 });
            int scalar = 2;

            std::cout << "testScalarMultiplication: ";
            VectorND<int> result = vec * scalar;
            for (size_t i = 0; i < result.size(); ++i)
                std::cout << result[i] << " ";
            std::cout << std::endl;
        }

        // Tests the scalar division of a vector
        static void testScalarDivision()
    	{
            VectorND<int> vec({ 2, 4, 6 });
            int scalar = 2;

            std::cout << "testScalarDivision: ";
            VectorND<int> result = vec / scalar;
            for (size_t i = 0; i < result.size(); ++i)
                std::cout << result[i] << " ";
            std::cout << std::endl;
        }

        // Tests the reversal of a vector (reversing its elements)
        static void testReverse()
    	{
            VectorND<int> vec({ 1, 2, 3 });

            std::cout << "testReverse: ";
            VectorND<int> result = vec.reverse();
            for (size_t i = 0; i < result.size(); ++i)
                std::cout << result[i] << " ";
            std::cout << std::endl;
        }

        // Tests the projection of one vector onto another
        static void testProjection()
    	{
            VectorND<int> vec1({ 1, 2, 3 });
            VectorND<int> vec2({ 4, 5, 6 });

            std::cout << "testProjection: ";
            VectorND<int> result = vec1.projection(vec2);
            for (size_t i = 0; i < result.size(); ++i)
                std::cout << result[i] << " ";
            std::cout << std::endl;
        }

        // Sorting tests: Selection Sort, Insertion Sort, Bubble Sort, Merge Sort, Quick Sort
        // Each test sorts an array of integers and outputs the sorted result
        static bool isSorted(int* begin, int* end)
    	{
            for (int* i = begin; i < end - 1; ++i) 
            {
                if (*i > *(i + 1))
                    return false;
            }
            return true;
        }

        static void testSelectionSort()
    	{
            int arr[] = { 64, 25, 12, 22, 11 };
            mylib::algorithms::selectionSort(arr, arr + 5);

            std::cout << "Selection Sort Result: ";
            for (int i = 0; i < 5; ++i) 
            {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
            std::cout << "Selection Sort: " << (isSorted(arr, arr + 5) ? "Passed" : "Failed") << "\n";
        }

        static void testInsertionSort()
    	{
            int arr[] = { 64, 25, 12, 22, 11, 75 };
            mylib::algorithms::insertionSort(arr, arr + 6);

            std::cout << "Insertion Sort Result: ";
            for (int i = 0; i < 6; ++i) 
            {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
            std::cout << "Insertion Sort: " << (isSorted(arr, arr + 6) ? "Passed" : "Failed") << "\n";
        }

        static void testBubbleSort()
    	{
            int arr[] = { 64, 25, 12, 22, 11, 75, 38 };
            mylib::algorithms::bubbleSort(arr, arr + 7);

            std::cout << "Bubble Sort Result: ";
            for (int i = 0; i < 7; ++i) 
            {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
            std::cout << "Bubble Sort: " << (isSorted(arr, arr + 7) ? "Passed" : "Failed") << "\n";
        }

        static void testMergeSort()
    	{
            int arr[] = { 64, 25, 12, 22, 11, 75 };
            mylib::algorithms::mergeSort(arr, arr + 6);

            std::cout << "Merge Sort Result: ";
            for (int i = 0; i < 6; ++i)
            {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
            std::cout << "Merge Sort: " << (isSorted(arr, arr + 6) ? "Passed" : "Failed") << "\n";
        }

        static void testQuickSort()
    	{
            int arr[] = { 64, 25, 12, 22, 11, 75, 50 };
            mylib::algorithms::quickSort(arr, arr + 7);

            std::cout << "Quick Sort Result: ";
            for (int i = 0; i < 7; ++i) 
            {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
            std::cout << "Quick Sort: " << (isSorted(arr, arr + 7) ? "Passed" : "Failed") << "\n";
        }
    };
}

#endif // TEST_NDIMVECTOR_H
