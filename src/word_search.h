/* ========================================================================= */
// 11-zogwidrouhua-3a
//
// PROJECT WORD SEARCH
//
// The declarations for the global functions
/* ========================================================================= */

#pragma once

#include "dictionary.h"
#include "grid.h"

void findMatches(Dictionary& dict, Grid& grid, string output_fn);
void search(int); //0 - quicksort, 1 - heapsort