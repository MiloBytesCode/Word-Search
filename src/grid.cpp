/* ========================================================================= */
// 11-zogwidrouhua-3a
//
// PROJECT WORD SEARCH
//
// The implementation for the Dictionary Class
/* ========================================================================= */

#include "grid.h"
#include <fstream>
#include <cctype>
#include <vector>
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
/*
    char c;
    int rows, cols;

    // read size of grid and resize matrix
    letterGrid >> rows;
    letterGrid >> cols;
    letters.resize(rows, cols);
    cout << "Creating grid with dimension (" << rows << "," << cols << ")...";

    // read chars into the letters matrix
    int i = 0, j = 0;
    while (!letterGrid.eof())
    {
        letterGrid.get(c);
        if (c == '\n')
        {
            i++;
            j = 0;
        } 
        else if (c != ' ')
        {
            letters[i - 1][j] = c;
            j++;
        }
    } // end while not EOF
*/
    int rows, cols;

    // read size of grid and resize matrix
    letterGrid >> rows >> cols;
    letters.resize(rows, cols);
    cout << "Creating grid with dimension (" << rows << "," << cols << ")...";

    // read characters directly into matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            letterGrid >> letters[i][j];
        }
    }
    cout << "done\n";
    // close file once finished
    letterGrid.close();
} // end Grid constructor

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
} // end << operator

int Grid::numRows() const
{
    return letters.rows();
}

int Grid::numCols() const
{
    return letters.cols();
}

char Grid::readIndex(int row, int col) const
{
    return letters[row][col];
}