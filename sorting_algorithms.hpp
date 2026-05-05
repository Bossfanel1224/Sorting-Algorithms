#ifndef SORTING_ALGORITHMS_HPP
#define SORTING_ALGORITHMS_HPP

#include <vector>
#include <algorithm>

inline void bubbleSort(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

inline void selectionSort(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

inline void insertionSort(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

inline void bogoSort(std::vector<int> &arr)
{
    while (!std::is_sorted(arr.begin(), arr.end()))
    {
        for (int i = 0; i < arr.size(); i++)
        {
            std::swap(arr[i], arr[std::rand() % arr.size()]);
        }
    }
}

inline void siftDown(std::vector<int> &arr, int n, int root)
{
    while (true)
    {
        int largest = root;
        int left = 2 * root + 1;
        int right = 2 * root + 2;
        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;
        if (largest == root)
            break;
        std::swap(arr[root], arr[largest]);
        root = largest;
    }
}

inline void heapSort(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        siftDown(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        std::swap(arr[0], arr[i]);
        siftDown(arr, i, 0);
    }
}

inline int partition(std::vector<int> &arr, int low, int high)
{
    int randIndex = low + std::rand() % (high - low + 1);
    std::swap(arr[randIndex], arr[high]);
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

inline void quickSortHelper(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

inline void quickSort(std::vector<int> &arr)
{
    if (!arr.empty())
    {
        quickSortHelper(arr, 0, arr.size() - 1);
    }
}

inline void merge(std::vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

inline void mergeSortHelper(std::vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSortHelper(arr, left, mid);
    mergeSortHelper(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

inline void mergeSort(std::vector<int> &arr)
{
    if (!arr.empty())
    {
        mergeSortHelper(arr, 0, arr.size() - 1);
    }
}

#endif