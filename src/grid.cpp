/* ========================================================================= */
// 11-zogwidrouhua-3a
//
// PROJECT WORD SEARCH
//
// The implementation for the Dictionary Class
/* ========================================================================= */

#include "grid.h"
#include <fstream>
using namespace std;

Grid::Grid(const string& letterGrid_fn)
// given a letterGrid file, creates a Grid object
{
    // open file and test 
    ifstream letterGrid(letterGrid_fn);
    if (!letterGrid)
    {
        cerr << "Error opening letter grid file\n";
        return;
    }

    vector<string> lines;
    string line;

    // read lines into vector
    while (getline(letterGrid, line))
    {
        if (!line.empty())
            lines.push_back(line);
    }

    // resize matric to fit all letters
    letters.resize(lines.size(), lines[0].size());

    // populate matrix with letters
    for (int i = 0; i < lines.size(); i++)
    {
        for (int j = 0; j < lines[0].size(); j++)
            letters[i][j] = lines[i][j];
    }

}

char Grid::readIndex(int row, int col) const
// given a row and col, returns the value at that index
{
    return letters[row][col];
}

ostream& operator<<(ostream& ostr, const Grid& grid)
// prints out all letters in the grid in the shape of the grid
{
    for(int i = 0; i < grid.letters.rows(); i++)
    {
        for (int j = 0; j < grid.letters.cols(); j++)
            ostr << grid.letters[i][j];

        ostr << endl;
    }
    return ostr;
}