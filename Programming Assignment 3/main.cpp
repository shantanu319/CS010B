#include <iostream>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

#include "Deck.h"
#include "Card.h"

// Returns true if vector of Cards passed in contains at least 2 Cards with the same rank.
bool hasPair(const vector<Card> &hand);

// Sends to output stream a hand of Cards on a single line, 
// each Card separated by a comma.
// If the vector is empty, do not output anything.
// Example (vector size of 3): Ace of Spades, Two of Hearts, King of Clubs 
ostream & operator<<(ostream &ofs, const vector<Card> &hand);

int main() {
    srand(2222);
    string wantFile; 

    unsigned cardsPerHand;
    unsigned numSimulations;
    int numPairs;

    string fileName;
    ofstream outFS;

    Deck theDeck;
    vector<Card> tempHand;

    cout << "Do you want to output all hands to a file?(Yes/No) ";
    cin >> wantFile;
    cout << endl;

    if (wantFile == "Yes")
    {
        cout << "Enter name of output file:";
        cin >> fileName;
        cout << endl;

        outFS.open(fileName);
        if (!outFS.is_open())
        {
            cout << "Error opening " << fileName << endl;
            exit(1);
        }

    }

    cout << "Enter number of cards per hand: ";
    cin >> cardsPerHand;
    cout << endl;

    cout << "Enter number of deals (simulations): ";
    cin >> numSimulations;
    cout << endl;
    
    //simulation step
    for (unsigned int i = 0; i < numSimulations; i++)
    {
        theDeck.shuffleDeck();
        tempHand.clear();
        //deal card step
        for (unsigned int j = 0; j < cardsPerHand; j++)
        {
            tempHand.push_back(theDeck.dealCard());
        }

        if (hasPair(tempHand))
        {
            numPairs++;
            if (wantFile == "Yes")
            {
                outFS << "Found Pair!! ";
            }
            
        }
        else if (wantFile == "Yes") { outFS << "             "; }

        if (wantFile == "Yes") {outFS << tempHand;}

    }

    cout << "Chances of receiving a pair in a hand of " << cardsPerHand << " cards is: " << 100 * ((double) numPairs / numSimulations) << "%" << endl; 

    return 0;
}

bool hasPair(const vector<Card> &hand)
{
    for (unsigned int i = 0; i < hand.size(); i++)
    {
        int temp = hand.at(i).getRank();
        for (unsigned int j = i + 1; j < hand.size(); j++)
        {
            if (temp == hand.at(j).getRank())
            {
                return true;
            }
        }
    }

    return false;
}

ostream & operator<<(ostream &ofs, const vector<Card> &hand)
{
    for (unsigned int i = 1; i < hand.size(); i++)
    {
        ofs << hand.at(i) << ", ";
    }

    ofs << hand.at(hand.size() - 1) << endl;

    return ofs;
}