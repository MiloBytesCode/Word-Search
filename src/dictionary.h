/* ========================================================================= */
// 11-zogwidrouhua-3a
//
// PROJECT WORD SEARCH
//
// The class declaraction for the Dictionary
/* ========================================================================= */

#include <string>
#include <vector>
#include <iostream>

#pragma once

class Dictionary
{
    public:
        // functionality
        Dictionary(const std::string& dictName);
        void sort();
        int wordLookup(std::string word) const;

        // operators
        friend std::ostream& operator<<(std::ostream& ostr, const Dictionary& dict);

    private:
        std::vector<std::string> words;
};

