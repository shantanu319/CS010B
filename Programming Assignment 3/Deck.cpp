#include <vector>
#include <algorithm>

using namespace std;

#include "Deck.h"
#include "Card.h"


Deck::Deck()
{
    vector<char> suitChars = {'s', 'h', 'd', 'c'};
    for (unsigned int i = 0; i < 4; ++i)
    {
        for (unsigned int j = 13; j >= 1; j--)
        {
            theDeck.push_back(Card(suitChars.at(i), j));
            //cout << suitChars.at(i) << " " << j << endl;
        }
    }
}


Card Deck::dealCard()
{
    Card backOfDeck = theDeck.at(theDeck.size() - 1);
    dealtCards.push_back(backOfDeck);
    theDeck.pop_back();

    return backOfDeck;
}


void Deck::shuffleDeck()
{
    for (unsigned int i = 0; i < dealtCards.size(); ++i)
    {
        theDeck.push_back(dealtCards.at(i));
    }

    dealtCards.clear();
    random_shuffle(theDeck.begin(), theDeck.end());
}


unsigned Deck::deckSize() const
{
    return theDeck.size();
}