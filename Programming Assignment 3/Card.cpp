#include <iostream>
#include <vector>

using namespace std;

#include "Card.h"

Card::Card()
{
    suit = 'c';
    rank = 2;
}

Card::Card(char initSuit, int initRank)
{
    initSuit = tolower(initSuit);
    if (initSuit == 'c')
    {
        suit = 'c';
    }
    else if (initSuit == 'd')
    {
        suit = 'd';
    }
    else if (initSuit == 'h')
    {
        suit = 'h';
    }
    else if (initSuit == 's')
    {
        suit = 's';
    }
    else
    {
        suit = 'c';
    }

    if (initRank > 13 || initRank < 1)
    {
        rank = 2;
    }
    else
    {
        rank = initRank;
    }

}


  
char Card::getSuit() const
{
    return suit;
}
    

int Card::getRank() const
{
    return rank;
}
    
   
ostream & operator<<(ostream &out, const Card &oneCard)
{
    vector<string> faceCards = {"Ace", "Jack", "Queen", "King"};

    if (oneCard.rank == 1)
    {
        out << faceCards.at(0);
    }
    else if (oneCard.rank > 10)
    {
        unsigned check = oneCard.rank - 10;
        string output;
        for (unsigned int i = 1; i < 4; ++i)
        {
            if (i == check)
            {
                output = faceCards.at(i);
            }
        }
        out << output;
    }
    else
    {
        out << oneCard.rank;
    }

    out << " of ";

    if (oneCard.suit == 'c') {out << "Clubs";}
    if (oneCard.suit == 'd') {out << "Diamonds";}
    if (oneCard.suit == 'h') {out << "Hearts";}
    if (oneCard.suit == 's') {out << "Spades";}

    return out;
}