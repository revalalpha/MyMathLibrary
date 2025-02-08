#ifndef TEST_NDIMVECTOR_H
#define TEST_NDIMVECTOR_H

#include <iostream>
#include "MyNDimVector.h"

namespace mylib
{
    class testNDimVector {
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
            testIterator();

            std::cout <<
                "     -----------------------------------\n"
                "     ----- '-' ALL TEST PASSED '-' -----\n"
                "     -----------------------------------\n\n\n";
        }

    private:
        static void testDotProduct() {
            VectorND<int> vec1({ 1, 2, 3 });
            VectorND<int> vec2({ 4, 5, 6 });

            std::cout << "testDotProduct: ";
            std::cout << vec1.dot(vec2) << std::endl;
        }

        static void testCrossProduct() {
            VectorND<int> vec1({ 1, 2, 3 });
            VectorND<int> vec2({ 4, 5, 6 });

            std::cout << "testCrossProduct: ";
            VectorND<int> result = vec1.cross(vec2);
            for (size_t i = 0; i < result.size(); ++i)
                std::cout << result[i] << " ";
            std::cout << std::endl;
        }

        static void testNorm() {
            VectorND<int> vec({ 3, 4 });

            std::cout << "testNorm: ";
            std::cout << vec.norm() << std::endl;
        }

        static void testNormalize() {
            VectorND<int> vec({ 3, 4 });
            vec.normalize();

            std::cout << "testNormalize: ";
            for (size_t i = 0; i < vec.size(); ++i)
                std::cout << vec[i] << " ";
            std::cout << std::endl;
        }

        static void testAddition() {
            VectorND<int> vec1({ 1, 2, 3 });
            VectorND<int> vec2({ 4, 5, 6 });

            std::cout << "testAddition: ";
            VectorND<int> result = vec1 + vec2;
            for (size_t i = 0; i < result.size(); ++i)
                std::cout << result[i] << " ";
            std::cout << std::endl;
        }

        static void testSubtraction() {
            VectorND<int> vec1({ 1, 2, 3 });
            VectorND<int> vec2({ 4, 5, 6 });

            std::cout << "testSubtraction: ";
            VectorND<int> result = vec1 - vec2;
            for (size_t i = 0; i < result.size(); ++i)
                std::cout << result[i] << " ";
            std::cout << std::endl;
        }

        static void testScalarMultiplication() {
            VectorND<int> vec({ 1, 2, 3 });
            int scalar = 2;

            std::cout << "testScalarMultiplication: ";
            VectorND<int> result = vec * scalar;
            for (size_t i = 0; i < result.size(); ++i)
                std::cout << result[i] << " ";
            std::cout << std::endl;
        }

        static void testScalarDivision() {
            VectorND<int> vec({ 2, 4, 6 });
            int scalar = 2;

            std::cout << "testScalarDivision: ";
            VectorND<int> result = vec / scalar;
            for (size_t i = 0; i < result.size(); ++i)
                std::cout << result[i] << " ";
            std::cout << std::endl;
        }

        static void testReverse() {
            VectorND<int> vec({ 1, 2, 3 });

            std::cout << "testReverse: ";
            VectorND<int> result = vec.reverse();
            for (size_t i = 0; i < result.size(); ++i)
                std::cout << result[i] << " ";
            std::cout << std::endl;
        }

        static void testProjection() {
            VectorND<int> vec1({ 1, 2, 3 });
            VectorND<int> vec2({ 4, 5, 6 });

            std::cout << "testProjection: ";
            VectorND<int> result = vec1.projection(vec2);
            for (size_t i = 0; i < result.size(); ++i)
                std::cout << result[i] << " ";
            std::cout << std::endl;
        }

        static void testIterator() {
            VectorND<int> vec({ 1, 2, 3 });

            std::cout << "testIterator: ";
            for (auto it = vec.begin(); it != vec.end(); ++it)
                std::cout << *it << " ";
            std::cout << std::endl;
        }
    };
}

#endif // TEST_NDIMVECTOR_H
