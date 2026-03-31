/* ========================================================================= */
// 11-zogwidrouhua-3a
//
// PROJECT WORD SEARCH
//
// The class declaraction for the Dictionary
/* ========================================================================= */

#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Dictionary
{
    public:
        // functionality
        Dictionary(const std::string& dictName);
        void sort();
        void quicksort();
        int wordLookup(const std::string& word) const;
        void heapsort();

        // operators
        friend std::ostream& operator<<(std::ostream& ostr, const Dictionary& dict);

    private:
        std::vector<std::string> words;

        // quicksort helper functions
        void quicksortHelper(int low, int high);
        int partition(int low, int high);
};

