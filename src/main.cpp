/* ========================================================================= */
// 11-zogwidrouhua-3a
//
// PROJECT WORD SEARCH
//
// The runtime for WORD SEARCH PART A
/* ========================================================================= */

#include <iostream>
#include "dictionary.h"
#include "word_search.h"
#include "dictionary.cpp"
#include "word_search.cpp"
#include "grid.cpp"
#include "grid.h"
using namespace std;

int main()
/*
Implement a global function search() which (1) reads the name of the grid file from the
keyboard, (2) read the data from input files for grid and dictionary, (3) sort all words in the
dictionary, and (4) prints out candidate words that can be found in the dictionary.
*/
{
    // Reads name of grid file from keyboard
    string GridFile;
    cout << "Please enter the name of your gridfile : ";
    cin >> GridFile;
    Grid InputGrid (GridFile);
    cout << "grid read!";
    

    // Read data from input grid file and dictionary
    Dictionary InputDict("Dictionary");
    cout << "Dict read!";

    // Sort dictionary
    InputDict.sort();
    cout << "dict sorted!";

    // Prints out candidtae words that are found in dictionary
    findMatches(InputDict, InputGrid, "output");
    cout << "matches found!";

    return 0;
} 