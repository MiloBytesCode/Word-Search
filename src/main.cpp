/* ========================================================================= */
// 11-zogwidrouhua-3b
//
// PROJECT WORD SEARCH
//
// The runtime for WORD SEARCH PART A
/* ========================================================================= */

#include <iostream>
#include "dictionary.h"
#include "word_search.h"
#include "grid.h"
#include "heap.h"
using namespace std;

int main()
/*
Implement a global function search() which (1) reads the name of the grid file from the
keyboard, (2) read the data from input files for grid and dictionary, (3) sort all words in the
dictionary, and (4) prints out candidate words that can be found in the dictionary.
*/
{
    
   int choice;

    cout << "Choose sorting algorithm:\n";
    cout << "0 = selection sort\n";
    cout << "1 = quicksort\n";
    cout << "2 = heapsort\n";
    cout << "Enter choice: ";
    cin >> choice;

    search(choice);
    return 0;
} 

// In general Quicksort is fastest , and then heapsort, and lastly selection sort is the slowest.