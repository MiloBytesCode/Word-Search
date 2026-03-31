#include <vector>
#include <fstream>
#include <cctype>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
template <typename T>
T Heap<T>::parent(int n) {
    return this->stored[(n-1)/2];
}

template <typename T>
T Heap<T>::left(int n) {
    return this->stored[2*n+1];
}

template <typename T>
T Heap<T>::right(int n) {
    return this->stored[2*n+2];
}

template <typename T>
T Heap<T>::getItem(int n){
    return this->stored[n];
}

template <typename T>
void Heap<T>::initializeMaxHeap(vector<T> vec){
    stored = vec;
    buildMaxHeap();
}

template <typename T>
void Heap<T>::maxHeapify(int n) {
    int left = 2*n + 1;
    int right = 2*n + 2;
    int largest = n;
    
    if (left < stored.size() && this->stored[n] < this->stored[left]) {
        largest = left;
    }

    if (right < stored.size() && this->stored[n] < this->stored[right]) {
        largest = right;
    }

    if (largest != n) {
        swap(stored[n], stored[largest]);
        maxHeapify(largest);
    }
}

template <typename T>
void Heap<T>::buildMaxHeap() {
    for (int i = 0; i < stored.size() - 1; i--) {
        maxHeapify(i);
    }
}

template <typename T>
vector<T> Heap<T>::heapsort() {
    buildMaxHeap();
    return stored;
}
*/

// updated

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