
#include <vector>
#include <fstream>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

/*public:

        T parent(int);
        T left(int);
        T right(int);
        T getItem(int);

        void initializeMaxHeap();
        void maxHeapify();
        void buildMaxHeap();

        vector<T> heapsort();*/

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