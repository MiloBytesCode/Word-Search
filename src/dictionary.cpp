/* ========================================================================= */
// 11-zogwidrouhua-3a
//
// PROJECT WORD SEARCH
//
// The implementation for the Dictionary Class
/* ========================================================================= */

#include "dictionary.h"
#include "d_except.h"
#include <iostream>
#include <fstream>
using namespace std;


Dictionary::Dictionary(string dictName)
// given a dictionary file, creates Dictionary object
{
    string DictLine;
    // open and read file
        ifstream DictFile("../" + dictName);
    // runs if cannot open file
    if (!DictFile) {
        cerr << "Error opening file\n";
        return;
    }
    // read words into vec
    while (getline (DictFile, DictLine)) {
        words.push_back(DictLine);
    }
}

void Dictionary::sort()
// uses selection sort to organize dictionary word vector
{
    // iterates through vector
    for(int i = 0; i < words.size(); ++i) {
        int current_min = i;
        // iterates through unsorted portion of vector, keeping track of index with the lowest value
        for(int j = i + 1; j < words.size(); ++j){
            if(words[j] < words[current_min]){
                current_min = j;
            }
        }
        // swaps 1st unsorted index with the lowest unsorted value
        swap(words[i], words[current_min]);
    }
}

int Dictionary::wordLookup(string word) const
// given a word, returns index of word in dictionary if it exists, else -1
{
    int lowest = 0;
    int highest = words.size() - 1;

    while(lowest <= highest){
        int middle = (lowest + highest) / 2;
        // if word is found this evaulates as true and returns index of word
        if(words[middle] == word){
            return middle;
        }
        // if word is greater than middle word, changes the lowest possible index to midd + 1
        else if(words[middle] < word){
            lowest = middle + 1;
        }
        // only get here if words[middle] > word, so now highest possible value is middle - 1
        else{
            highest = middle - 1;
        }
    }
    // returns -1 if not found
    return -1;
}

ostream& operator<<(ostream& ostr, const Dictionary& dict)
{
    // print all words in dictionary
    for(int i = 0; i < dict.words.size(); i++){
        ostr << dict.words[i] << '\n';
    }
    return ostr;
}