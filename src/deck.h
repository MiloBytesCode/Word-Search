/* ========================================================================= */
// 11-zogwidrouhua-2a
//
// The DECK class header files
//
// Contains the declaraction for the DECK class. This class stores a linked
// list of CARD instances, which are to be initialized as a standard 52-card
// playing deck. This class can also be shuffled.
/* ========================================================================= */

#pragma once

#include "card.h"
#include "d_node.h"
#include <iostream>
#include <string>


class deck
{
    public:
        // constructor
        deck();

        //destructor
        ~deck();

        deck(bool make_standard); // constructor for hand deck

        // functions
        void shuffle();
        void addCard(std::string s, int fV);
        int get_size();


        
        node<card>* deal(int n = 0); // remove and return the top card node of the deck
        void replace(node<card>* c); // pass a card node as parameter to be added to the bottom of the deck
        
        // operators
        friend std::ostream& operator<<(std::ostream& ostr, const deck& d);

    private:
        // list of cards
        node<card>* front = nullptr;

}; // end class