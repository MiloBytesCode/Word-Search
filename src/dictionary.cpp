/* ========================================================================= */
// 11-zogwidrouhua-3b
//
// PROJECT WORD SEARCH
//
// The implementation for the Dictionary Class
/* ========================================================================= */

#include "dictionary.h"
#include <fstream>
#include <cctype>
#include <iostream>
#include "d_matrix.h"
#include "heap.h"
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

    cout << "Initializing dictionary...";
    // read words into words vector
    string line;
    while (getline(dict_file, line))
    {
        if (!line.empty())
            words.push_back(line);
    }
    cout << "done\n";
} // end dictionary constructor

void Dictionary::sort()
// uses selection sort to organize dictionary word vector
{
    cout << "Sorting dictionary...";
    // iterates through vector
    int size = words.size();
    for(int i = 0; i < size -1; ++i) {
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
    cout << "done\n";
} // end selection sort



// updated logic for word lookup
int Dictionary::wordLookup(const string& word) const
{
    int lowest = 0;
    int highest = words.size() - 1;
    // binary search for word in sorted dictionary
    while (lowest <= highest) {
        int middle = (lowest + highest) / 2;

        if (words[middle] == word) {
            return middle;
        }
        else if (words[middle] < word) {
            lowest = middle + 1;
        }
        else {
            highest = middle - 1;
        }
    }

    return -1;
}

// operator overload for printing dictionary
ostream& operator<<(ostream& ostr, const Dictionary& dict)
{
    // print all words in dictionary
    int size = dict.words.size();
    for(int i = 0; i < size; i++){
        ostr << dict.words[i] << '\n';
    }
    return ostr;
}

void Dictionary::quicksort()
{
    cout << "Sorting dictionary with quicksort...";
    if (!words.empty()) {
        quicksortHelper(0, words.size() - 1);
    }
    cout << "done\n";
}

// helper to recursively sort subarrays
void Dictionary::quicksortHelper(int low, int high)
{
    if (low < high) {
        int pivotIndex = partition(low, high);
        quicksortHelper(low, pivotIndex - 1);
        quicksortHelper(pivotIndex + 1, high);
    }
}

// partition function for quicksort
int Dictionary::partition(int low, int high)
{
    string pivot = words[high];
    int i = low - 1;
    // iterate through subarray
    for (int j = low; j < high; j++) {
        if (words[j] <= pivot) {
            i++;
            swap(words[i], words[j]);
        }
    }
    // place pivot in correct position
    swap(words[i + 1], words[high]);
    return i + 1;
}

// organize dictionary word vector with heapsort
void Dictionary::heapsort() {
    cout << "Sorting dictionary with heapsort...";
    Heap<string> h;
    h.initializeMaxHeap(words);
    words = h.heapsort();
    cout << "done\n";
    /*
    for (const auto& word : words) {
        std::cout << word << " ";
    }
    */
}
    
