/* ========================================================================= */
// 11-zogwidrouhua-3a
//
// PROJECT WORD SEARCH
//
// The implementation for the global functions
/* ========================================================================= */

#include "word_search.h"
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;


void findMatches(Dictionary& dict, Grid& grid, string output_fn)
// given dictionary and grid objects and an output file string, find all 
// words in grid that match in the dictionary and save to output file
{
    ofstream found_words(output_fn);
    // possible directions to expand word vector
    int dir_row[8] = {-1, -1,  0,  1,  1,  1,  0, -1};
    int dir_col[8] = { 0,  1,  1,  1,  0, -1, -1, -1};

    int maximum_word_size = max(grid.numRows(), grid.numCols());

    int total_words_found = 0;

    found_words << left
            << setw(15) << "word"
            << setw(22) << "start point (i,j)"
            << setw(12) << "found index"
            << "\n";

    for (int i = 0; i < grid.numRows(); i++)
    {
        for (int j = 0; j < grid.numCols(); j++)
        {
            for (int k = 0; k < 8; k++)
            // iterate through all directions available to current index
            {
                // instantiate current word and save place in grid
                string potential_word = "";
                int r = i;
                int c = j;

                for(int step = 0; step < maximum_word_size; step++)
                {
                    // add letter to potential word
                    potential_word += grid.readIndex(r,c);

                    // once word is at least 5 characters, test against dict
                    if (potential_word.length() >= 5)
                    {
                        int word_index = dict.wordLookup(potential_word);
                        if (word_index != -1)
                        {
                            total_words_found++;
                            cout << "found >"<< potential_word << " | total [";
                            cout << total_words_found << "]\n";

                            // setup proper format for output
                            found_words << left
                            << setw(15) << potential_word
                            << setw(22) << ("(" + to_string(i) + "," + to_string(j) + ")")
                            << setw(12) << word_index
                            << "\n";
                        } // endif wordMatch
                    } // endif word length >= 5

                    // move in direction
                    r = (r + dir_row[k] + grid.numRows()) % grid.numRows();
                    c = (c + dir_col[k] + grid.numCols()) % grid.numCols();
                } // end while in bounds
            } // end for (k)
        } // end for (j)
    } // end for (i)
} // end findMatches

void search(int sortType)
// prompts user for grid file, dictionary file, and output file. Then, a word
// search is started and results are saved to the output file
{
    string grid_file, dict_file, out_file;

    // get file names from keyboard input
    cout << "Enter name for \"GRID_FILE\": ";
    cin >> grid_file;

    cout << "Enter name for \"DICT_FILE\": ";
    cin >> dict_file;


    // create dict and grid objects to perform search and match
    Grid grid(grid_file);
    Dictionary dict(dict_file);
    /*
    if (n == 0) { dict.sort(); }
    else {dict.heapsort();}
    */

     // choose sorting algorithm
    if (sortType == 0) {
        dict.sort();          // selection sort
    }
    else if (sortType == 1) {
        dict.quicksort();     // quicksort
    }
    else if (sortType == 2) {
        dict.heapsort();      // heapsort
    }
    else {
        cout << "Invalid sorting choice. Using selection sort.\n";
        dict.sort();
    }

    cout << "Enter name for \"OUTPUT_FILE\": ";
    cin >> out_file;

    cout << "Search started...";
    findMatches(dict, grid, out_file);

    cout << "completed\nOutput written to \"" << out_file << "\"\n";
    
/*
    // get name for output file
    cout << "Enter name for \"OUTPUT_FILE\": ";
    cin >> out_file;

    cout << "Search started...";
    findMatches(dict, grid, out_file);

    // search complete and data written to out file
    cout << "completed\nOutput written to \"" << out_file << "\"\n";
    */
} // end search