/* ========================================================================= */
// 11-zogwidrouhua-3a
//
// PROJECT WORD SEARCH
//
// The implementation for the Dictionary Class
/* ========================================================================= */

#include "dictionary.h"
#include "d_except.h"
using namespace std;


Dictionary::Dictionary(string dictName)
// given a dictionary file, creates Dictionary object
{
    // open and read file
    // read words into vec
}

void Dictionary::sort()
// uses selection sort to organize dictionary word vector
{
    // implement selection sort algorithm
}

int Dictionary::wordLookup(string word) const
// given a word, returns index of word in dictionary if it exists, else -1
{

    return -1;
}

ostream& operator<<(ostream& ostr, const Dictionary& dict)
{
    // print all words in dictionary
}