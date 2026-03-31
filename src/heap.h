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

        T parent(int); //returns value of parent of a node
        T left(int); //returns value of left child of node
        T right(int); // returns value of right child of node
        T getItem(int); // returns node value

        void initializeMaxHeap(vector<T>); //set stored to vector and sort
        void maxHeapify(int); //max heapify a single node
        void buildMaxHeap(); //sort stored vector

        vector<T> heapsort(); //builds max heap and returns value

    private:
        vector<T> stored; //heap

};

#include "heap.tpp" //function logic