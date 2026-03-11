/* ========================================================================= */
// 11-zogwidrouhua-2b
//
// The CARD class header files
//
// This file contains the declaration for the CARD class, which has a value
// and a suit (Club, Diamond, Heart, Spade). This class will be used as a 
// member of the DECK class, in which CARD instances will be contained.
/* ========================================================================= */

#pragma once

#include <string>
#include <iostream>

class card 
{
    public:
        // constructor
        card(std::string suit, int faceVal);

        // private member access
        int getValue() const;
        void setValue(int fV);

        std::string getSuit() const;
        void setSuit(std::string s);

        // operators
        friend std::ostream& operator<<(std::ostream& ostr, const card& c);

        card(const card& other); // copy constructor
        card& operator=(const card& other); // copy assignment operator

    private:
        std::string suit;
        int faceVal;

}; // end class


