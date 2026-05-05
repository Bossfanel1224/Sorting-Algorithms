# Sorting Algorithm Experiments

Source code and results for the paper *An Experimental Comparison of Sorting Algorithms*,
written for the Methods of Programming and Investigation (MPI) course at the
West University of Timișoara.

## Algorithms implemented

- Bubble Sort (with early-exit flag)
- Selection Sort
- Insertion Sort
- Bogo Sort
- Heap Sort
- Quick Sort (with random pivot)
- Merge Sort

## Files

- `sorting_algorithms.hpp` — implementations of all seven algorithms
- `main.cpp` — input generators, timing harness, and main benchmark loop
- `results.txt` — raw output from the runs presented in the paper

## Compile and run
```
g++ -O2 -std=c++17 main.cpp -o sorting
./sorting
```
The program prints the average running time in milliseconds for every combination of algorithm, input type, and array size.
