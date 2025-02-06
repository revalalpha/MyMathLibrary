#ifndef MYLIB_ALGO_H
#define MYLIB_ALGO_H

namespace mylib {
    namespace algorithms {

        // ----------------------------
        // Selection sort
        template <typename T>
        void selectionSort(T* begin, T* end)
        {
            for (T* i = begin; i < end - 1; ++i)
            {
                T* minElement = i;
                for (T* j = i + 1; j < end; ++j)
                    if (*j < *minElement)
                        minElement = j;
                if (minElement != i)
                {
                    T temp = *i;
                    *i = *minElement;
                    *minElement = temp;
                }
            }
        }

        // ----------------------------
        // Insertion sort
        template <typename T>
        void insertionSort(T* begin, T* end)
        {
            for (T* i = begin + 1; i < end; ++i)
            {
                T key = *i;
                T* j = i - 1;
                while (j >= begin && *j > key)
                {
                    *(j + 1) = *j;
                    --j;
                }
                *(j + 1) = key;
            }
        }

        // ----------------------------
        // Bubble sort
        template <typename T>
        void bubbleSort(T* begin, T* end)
        {
            bool swapped;
            do
            {
                swapped = false;
                for (T* i = begin; i < end - 1; ++i)
                {
                    if (*i > *(i + 1))
                    {
                        T temp = *i;
                        *i = *(i + 1);
                        *(i + 1) = temp;
                        swapped = true;
                    }
                }
            } while (swapped);
        }

        // ----------------------------
        // Fusion sort
        template <typename T>
        void merge(T* begin, T* mid, T* end)
        {
            unsigned int n1 = mid - begin;
            unsigned int n2 = end - mid;

            T* left = new T[n1];
            T* right = new T[n2];

            for (unsigned int i = 0; i < n1; ++i)
                left[i] = *(begin + i);
            for (unsigned int j = 0; j < n2; ++j)
                right[j] = *(mid + j);

            unsigned int i = 0, j = 0, k = 0;
            while (i < n1 && j < n2)
            {
                if (left[i] <= right[j])
                {
                    *(begin + k) = left[i];
                    ++i;
                }
                else
                {
                    *(begin + k) = right[j];
                    ++j;
                }
                ++k;
            }

            while (i < n1)
            {
                *(begin + k) = left[i];
                ++i;
                ++k;
            }

            while (j < n2)
            {
                *(begin + k) = right[j];
                ++j;
                ++k;
            }

            delete[] left;
            delete[] right;
        }

        template <typename T>
        void mergeSort(T* begin, T* end)
        {
            if (end - begin > 1)
            {
                T* mid = begin + (end - begin) / 2;
                mergeSort(begin, mid);
                mergeSort(mid, end);
                merge(begin, mid, end);
            }
        }

        // ----------------------------
        // Quicksort
        template <typename T>
        T* partition(T* begin, T* end)
        {
            T* pivot = end - 1;
            T* i = begin - 1;

            for (T* j = begin; j < end - 1; ++j)
            {
                if (*j <= *pivot)
                {
                    ++i;
                    T temp = *i;
                    *i = *j;
                    *j = temp;
                }
            }

            T* j = i + 1;
            T temp = *j;
            *j = *pivot;
            *pivot = temp;

            return j;
        }

        template <typename T>
        void quickSort(T* begin, T* end)
        {
            if (begin < end)
            {
                T* pivot = partition(begin, end);
                quickSort(begin, pivot);
                quickSort(pivot + 1, end);
            }
        }

    } // namespace algorithms
} // namespace mylib

#endif