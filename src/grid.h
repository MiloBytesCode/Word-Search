/* ========================================================================= */
// 11-zogwidrouhua-3b
//
// PROJECT WORD SEARCH
//
// The header for the Grid Class
/* ========================================================================= */

#pragma once

#include "d_matrix.h"
#include <iostream>

class Grid
{
    public:
        // functionality
        Grid(const std::string& letterGrid_fn);
        char readIndex(int row, int col) const;
        int numRows() const;
        int numCols() const;

        // operators
        friend std::ostream& operator<<(std::ostream& ostr, const Grid& grid);

    private:
        matrix<char> letters;
};