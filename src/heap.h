/* ========================================================================= */
// 11-zogwidrouhua-3b
//
// PROJECT WORD SEARCH
//
// The header for the heap Class
/* ========================================================================= */
#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class Heap
{
    public:

        int parent(int) const;
        int left(int) const;
        int right(int) const;
        T getItem(int) const;
    /*
        T parent(int); //returns value of parent of a node
        T left(int); //returns value of left child of node
        T right(int); // returns value of right child of node
        T getItem(int); // returns node value
    */
        void initializeMaxHeap(vector<T>); //set stored to vector and sort
        void maxHeapify(int); //max heapify a single node
        void buildMaxHeap(); //sort stored vector

        vector<T> heapsort(); //builds max heap and returns value

    private:
        vector<T> stored; //heap
        int heapSize;

};

#include "heap.tpp" //function logic