/* ========================================================================= */
// 11-zogwidrouhua-2a
//
// The DECK class implementation
//
// Contains the implementation for the DECK class, including the constructor
// which produces an standard, ordered 52-card deck by default. 
/* ========================================================================= */

#include "deck.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
using namespace std;


deck::deck()
// constructor for the DECK class, creating a list of 52-card
{
    string suits[4] = {"Spade", "Heart", "Diamond", "Club"};

    // for each suit
    for (int i = 0; i < 4; i++)
    {
        // for each value within the suit
        for (int fV = 13; fV >= 1; fV--) 
        {
            addCard(suits[i], fV);
        }
    }

} // end deck constructor


// destructor for deck class
deck::~deck()
{
    node<card>* curr = front;
    while (curr != nullptr)
    {
        node<card>* temp = curr;
        curr = curr->next;
        delete temp; // deallocate memory for node
    }
} // end deck destructor


void deck::addCard(std::string s, int fV)
// puts a new card on the front of the deck
{
    card new_card(s, fV);
    front = new node<card>(new_card, front);  
} // end addCard


node<card>* deck::deal()
// removes and returns the top card node of the deck
{
    if (front == nullptr)
    {
        return nullptr; // return null if deck is empty
    }

    // store card node, update front, return the top card node
    node<card>* top_card = front; 
    front = front->next; 
    top_card->next = nullptr; 

    return top_card; 
} 

void deck::replace(node<card>* c)
// takes a card node as parameter and add it to the bottom of the deck
{
    if (c == nullptr)
    {
        return; 
    }
    
    c->next = nullptr; // make sure card node points to null

    if (front == nullptr)
    {
        front = c; //set front to new node when empty deck
        return;
    }

    // go to the end of the deck and add the card node
    node<card>* curr = front;
    while (curr->next != nullptr)
    {
        curr = curr->next; 
    }
    curr->next = c; 
}


void deck::shuffle()
// shuffles the entire deck into a random arrangement
{
    cout << "><><>< Shuffling initiated ><><><\n*shuffling noises...*\n";

    if(front == nullptr || front->next == NULL)
    // make sure deck is not empty
    {
        return;
    }

    std::vector<node<card>*> cards; //makes a vector of nodes (of type card)
    node<card>* curr = front;

    while(curr != nullptr)
    // adds all cards to new vector
    {
        cards.push_back(curr);
        curr = curr->next;

    }

    // uses std::shuffle to randomize vector
    std::random_device rd;
    std::mt19937 g(rd()); //makes seed for shuffle function
    std::shuffle(cards.begin(), cards.end(), g);//rearranges pointers

    // sets up new linked list
    int deck_size = cards.size() - 1; 
    front = cards[deck_size]; 
    curr = front;
    cards.pop_back(); 
    deck_size--;

    while(cards.empty() == false)
    // reassemble the linked list from the vector
    {
        curr->next = cards[deck_size]; 
        cards.pop_back();
        deck_size--;

        curr = curr->next;

    }
    curr->next = NULL; //makes last node point to null

    cout << "><><>< Deck Shuffled ><><><\n";
} // end shuffle

ostream& operator<<(ostream& ostr, const deck& d)
// takes DECK instance as rhs input and appends every card to ostream
{
    node<card> *curr;
    curr = d.front;

    while (curr != NULL)
    {
        ostr << curr->nodeValue;
        curr = curr->next;
    }

    return ostr;
} // end operator overload