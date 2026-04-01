/* ========================================================================= */
// 11-zogwidrouhua-3b
//
// PROJECT WORD SEARCH
//
// This file contains the template function to implements for the heap class
// including sorting algorithms heap sort, quicksort.
/* ========================================================================= */
#include <vector>
#include <fstream>
#include <cctype>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;



// updated logic for heap sort, quicksort, and selection sort
template <typename T>
int Heap<T>::parent(int n) const {
    return (n - 1) / 2;
}

template <typename T>
int Heap<T>::left(int n) const {
    return 2 * n + 1;
}

template <typename T>
int Heap<T>::right(int n) const {
    return 2 * n + 2;
}

template <typename T>
T Heap<T>::getItem(int n) const {
    return stored[n];
}

template <typename T>
void Heap<T>::initializeMaxHeap(vector<T> vec) {
    stored = vec;
    heapSize = stored.size();
    buildMaxHeap();
}

template <typename T>
void Heap<T>::maxHeapify(int n) {
    int l = left(n);
    int r = right(n);
    int largest = n;

    if (l < heapSize && stored[l] > stored[largest]) {
        largest = l;
    }

    if (r < heapSize && stored[r] > stored[largest]) {
        largest = r;
    }

    if (largest != n) {
        swap(stored[n], stored[largest]);
        maxHeapify(largest);
    }
}

template <typename T>
void Heap<T>::buildMaxHeap() {
    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        maxHeapify(i);
    }
}

template <typename T>
vector<T> Heap<T>::heapsort() {
    buildMaxHeap();

    int originalSize = heapSize;

    for (int i = stored.size() - 1; i > 0; i--) {
        swap(stored[0], stored[i]);
        heapSize--;
        maxHeapify(0);
    }

    heapSize = originalSize;
    return stored;
}