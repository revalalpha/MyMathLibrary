#ifndef TEST_MATRIX_H
#define TEST_MATRIX_H

#include <iostream>
#include "MyMatrix.h"
#include "MyAlgo.h"

namespace mylib {
    /*
		Class for testing Matrix operations.
    */
    class testMatrix {
    public:
        static void runTests()
        {
            testAddition();
            testSubtraction();
            testMultiplication();
            testScalarMultiplication();
            testTranspose();
            testDeterminant();
            testInverse();
            testEquality();
            testMatrixSelectionSort();
            testMatrixColumnSelectionSort();
            testMatrixInsertionSort();
            testMatrixBubbleSort();
        }

    private:
        /*
			Tests matrix addition.
        */
        static void testAddition()
        {
            Matrix<int> mat1(2), mat2(2);
            mat1(0, 0) = 1; mat1(0, 1) = 2;
            mat1(1, 0) = 3; mat1(1, 1) = 4;
            mat2(0, 0) = 5; mat2(0, 1) = 6;
            mat2(1, 0) = 7; mat2(1, 1) = 8;

            Matrix<int> result = mat1 + mat2;
            std::cout << "testAddition: \n" << result << "\n" << std::endl;
        }

        /*
			Tests matrix subtraction.
        */
        static void testSubtraction()
        {
            Matrix<int> mat1(2), mat2(2);
            mat1.fill(5);
            mat2.fill(3);

            Matrix<int> result = mat1 - mat2;
            std::cout << "testSubtraction: \n" << result << "\n" << std::endl;
        }

        /*
			Tests matrix multiplication.
        */
        static void testMultiplication()
        {
            Matrix<int> mat1(2), mat2(2);
            mat1(0, 0) = 1; mat1(0, 1) = 2;
            mat1(1, 0) = 3; mat1(1, 1) = 4;
            mat2(0, 0) = 2; mat2(0, 1) = 0;
            mat2(1, 0) = 1; mat2(1, 1) = 2;

            Matrix<int> result = mat1 * mat2;
            std::cout << "testMultiplication: \n" << result << "\n" << std::endl;
        }

        /*
			Tests scalar multiplication on matrix.
        */
        static void testScalarMultiplication()
        {
            Matrix<int> mat(2);
            mat.fill(3);
            Matrix<int> result = mat * 2;

            std::cout << "testScalarMultiplication: \n" << result << "\n" << std::endl;
        }

        /*
			Tests matrix transpose.
        */
        static void testTranspose()
        {
            Matrix<int> mat(2);
            mat(0, 0) = 1; mat(0, 1) = 2;
            mat(1, 0) = 3; mat(1, 1) = 4;

            Matrix<int> result = mat.transpose();
            std::cout << "testTranspose: \n" << result << "\n" << std::endl;
        }

        /*
			Tests matrix determinant calculation.
        */
        static void testDeterminant()
        {
            Matrix<int> mat(2);
            mat(0, 0) = 1; mat(0, 1) = 2;
            mat(1, 0) = 3; mat(1, 1) = 4;

            std::cout << "testDeterminant: " << mat.determinant() << "\n" << std::endl;
        }

        /*
			Tests matrix inversion.
        */
        static void testInverse()
        {
            Matrix<double> mat(2);
            mat(0, 0) = 4; mat(0, 1) = 7;
            mat(1, 0) = 2; mat(1, 1) = 6;

            Matrix<double> result = mat.inverse();
            std::cout << "testInverse: \n" << result << "\n" << std::endl;
        }

        /*
			Tests equality operator for matrices.
        */
        static void testEquality()
        {
            Matrix<int> mat1(2), mat2(2);
            mat1.fill(1);
            mat2.fill(1);

            std::cout << "testEquality: " << (mat1 == mat2 ? "Equal" : "Not Equal") << "\n" << std::endl;
        }

        /*
			Tests matrix sorting using selection sort.
        */
        static void testMatrixSelectionSort()
        {
            std::cout << "testMatrixSelectionSort:\n";
            int mat[3][3] = {
                {101, 55, 618},
                {14, 32, 17},
                {96, 65, 12}
            };
            size_t rows = 3;
            size_t cols = 3;
            for (size_t i = 0; i < rows; ++i)
                mylib::algorithms::selectionSort(mat[i], mat[i] + cols);
            for (size_t i = 0; i < rows; ++i)
            {
                for (size_t j = 0; j < cols; ++j)
                    std::cout << mat[i][j] << " ";
                std::cout << "\n";
            }

            std::cout << "\n";
        }

        /*
			Tests matrix sorting using insertion sort.
        */
        static void testMatrixInsertionSort()
        {
            std::cout << "testMatrixInsertionSort:\n";
            int mat[3][3] = {
                {10, 451516, -15168},
                {12, 31, 751},
                {149, 566, 352}
            };
            size_t rows = 3;
            size_t cols = 3;
            for (size_t i = 0; i < rows; ++i)
                mylib::algorithms::insertionSort(mat[i], mat[i] + cols);
            for (size_t i = 0; i < rows; ++i)
            {
                for (size_t j = 0; j < cols; ++j)
                    std::cout << mat[i][j] << " ";
                std::cout << "\n";
            }

            std::cout << "\n";
        }

        /*
			Tests matrix sorting using bubble sort.
        */
        static void testMatrixBubbleSort()
        {
            std::cout << "testMatrixBubbleSort:\n";
            int mat[5][5] = {
                {10, 5, 8,4,7},
                {1, 3, 7, 0, 2},
                {9, 46, -412, 0, 8},
                {145223, -6, 2, 4, 148},
                {99, 69, 22, 51, 654}
            };
            size_t rows = 5;
            size_t cols = 5;
            for (size_t i = 0; i < rows; ++i)
                mylib::algorithms::bubbleSort(mat[i], mat[i] + cols);
            for (size_t i = 0; i < rows; ++i)
            {
                for (size_t j = 0; j < cols; ++j)
                    std::cout << mat[i][j] << " ";
                std::cout << "\n";
            }

            std::cout << "\n";
        }

        /*
			Tests matrix sorting by columns using selection sort.
        */
        static void testMatrixColumnSelectionSort()
        {
            std::cout << "testMatrixColumnSelectionSort:\n";
            int mat[3][3] = {
                {010, 1215, 58},
                {151, 3561, 17},
                {915, 66, 12}
            };
            size_t rows = 3;
            size_t cols = 3;
            for (size_t j = 0; j < cols; ++j)
            {
                int col[3] = { mat[0][j], mat[1][j], mat[2][j] };
                mylib::algorithms::selectionSort(col, col + rows);
                for (size_t i = 0; i < rows; ++i)
                    mat[i][j] = col[i];
            }

            for (size_t i = 0; i < rows; ++i)
            {
                for (size_t j = 0; j < cols; ++j)
                    std::cout << mat[i][j] << " ";
                std::cout << "\n";
            }

            std::cout << "\n";
        }
    };
}

#endif // TEST_MATRIX_H
