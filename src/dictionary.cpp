/* ========================================================================= */
// 11-zogwidrouhua-3a
//
// PROJECT WORD SEARCH
//
// The implementation for the Dictionary Class
/* ========================================================================= */

#include "dictionary.h"
#include <fstream>
#include <cctype>
#include "d_matrix.h"
using namespace std;

Dictionary::Dictionary(const string& dictName)
// given a letterGrid file, creates a Grid object
{
    // open and read file
    ifstream dict_file(dictName);

    // runs if cannot open file
    if (!dict_file) {
        cerr << "Error opening dict file\n";
        return;
    }

    // read words into words vector
    string line;
    while (getline(dict_file, line))
    {
        if (!line.empty())
            words.push_back(line);
    }
}

void Dictionary::sort()
// uses selection sort to organize dictionary word vector
{
    // iterates through vector
    int size = words.size();
    for(int i = 0; i < size; ++i) {
        int current_min = i;
        // iterates through unsorted portion of vector, keeping track of index 
        // with the lowest value
        for(int j = i + 1; j < size; ++j){
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
    int size = dict.words.size();
    for(int i = 0; i < size; i++){
        ostr << dict.words[i] << '\n';
    }
    return ostr;
}