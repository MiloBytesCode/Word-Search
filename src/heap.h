/* ========================================================================= */
// 11-zogwidrouhua-3a
//
// PROJECT WORD SEARCH
//
// The header for the Grid Class
/* ========================================================================= */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class Heap
{
    public:

        T parent(int);
        T left(int);
        T right(int);
        T getItem(int);

        void initializeMaxHeap(vector<T>);
        void maxHeapify(int);
        void buildMaxHeap();

        vector<T> heapsort();

    private:
        vector<T> stored;

};

#include "heap.tpp"