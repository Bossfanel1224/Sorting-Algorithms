#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include "sorting_algorithms.hpp"

using namespace std;

vector<int> randomArr(int n)
{
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = rand() % 10000;
    return v;
}

vector<int> sortedArr(int n)
{
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = i;
    return v;
}

vector<int> halfSortedArr(int n)
{
    vector<int> v(n);
    for (int i = 0; i < n / 2; i++)
        v[i] = i;
    for (int i = n / 2; i < n; i++)
        v[i] = rand() % 10000;
    return v;
}

vector<int> reverseArr(int n)
{
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = n - i;
    return v;
}

double avgTime(string algo, vector<int> original, int runs)
{
    double total = 0;
    for (int r = 0; r < runs; r++)
    {
        vector<int> arr = original;
        clock_t start = clock();
        if (algo == "bubble")
            bubbleSort(arr);
        else if (algo == "selection")
            selectionSort(arr);
        else if (algo == "insertion")
            insertionSort(arr);
        else if (algo == "heap")
            heapSort(arr);
        else if (algo == "quick")
            quickSort(arr);
        else if (algo == "merge")
            mergeSort(arr);
        else if (algo == "bogo")
            bogoSort(arr);
        clock_t stop = clock();
        total += (double)(stop - start) / CLOCKS_PER_SEC * 1000.0;
    }
    return total / runs;
}

int main()
{
    srand(42);
    int RUNS = 5;
    int sizes[3] = {10, 1000, 100000};

    string algos[7] = {"bubble", "selection", "insertion", "heap", "quick", "merge", "bogo"};
    string algoNames[7] = {"Bubble Sort", "Selection Sort", "Insertion Sort",
                           "Heap Sort", "Quick Sort", "Merge Sort", "Bogo Sort"};

    for (int q = 0; q < 7; q++)
    {
        cout << "\n " << algoNames[q] << endl;

        for (int i = 0; i < 3; i++)
        {
            int n = sizes[i];

            if (algos[q] == "bogo" && n > 10)
            {
                cout << "  n=" << n << ": skipped (too slow)" << endl;
                continue;
            }

            cout << "  n=" << n << ":" << endl;

            vector<int> rnd = randomArr(n);
            vector<int> srt = sortedArr(n);
            vector<int> half = halfSortedArr(n);
            vector<int> rev = reverseArr(n);

            cout << "    random:      " << avgTime(algos[q], rnd, RUNS) << " ms" << endl;
            cout << "    sorted:      " << avgTime(algos[q], srt, RUNS) << " ms" << endl;
            cout << "    half-sorted: " << avgTime(algos[q], half, RUNS) << " ms" << endl;
            cout << "    reverse:     " << avgTime(algos[q], rev, RUNS) << " ms" << endl;
        }
    }

    return 0;
}
