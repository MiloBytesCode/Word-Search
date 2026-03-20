/* ========================================================================= */
// 11-zogwidrouhua-3a
//
// PROJECT WORD SEARCH
//
// The header for the Grid Class
/* ========================================================================= */

#include "d_matrix.h"

class Grid
{
    public:
        // functionality
        Grid(std::string letterGrid_fn);
        char readIndex(int row, int col) const;

    private:
        matrix<std::string> letters;
};