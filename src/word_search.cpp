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
{
    ofstream found_words(output_fn);
    // possible directions to expand word vector
    int dir_row[8] = {-1, -1,  0,  1,  1,  1,  0, -1};
    int dir_col[8] = { 0,  1,  1,  1,  0, -1, -1, -1};

    int total_words_found = 0;

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

                while (r < grid.numRows() && c < grid.numCols() && r >= 0 && c >= 0)
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
                            cout << "word found [" << total_words_found << "]\n";

                            // setup proper format for output
                            found_words << "word        start point (i,j)      found index\n";
                            found_words << "" << potential_word <<"  (" << i << "," << j << ")";
                            found_words << "    " << word_index << "\n";
                        } // endif wordMatch
                    } // endif word length >= 5

                    // move in direction
                    r += dir_row[k];
                    c += dir_col[k];
                } // end while in bounds
            } // end for (k)
        } // end for (j)
    } // end for (i)
} // end findMatches

void search()
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

    dict.sort();

    // get name for output file
    cout << "Enter name for \"OUTPUT_FILE\": ";
    cin >> out_file;

    cout << "Search started...";
    findMatches(dict, grid, out_file);

    // search complete and data written to out file
    cout << "completed\nOutput written to \"" << out_file << "\"\n";
}