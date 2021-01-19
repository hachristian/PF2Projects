#include <iostream>
#include "Magic.h"
#include "MagicDeck.h"
using namespace std;

int main()
{
    int quantity = 0;
    float value = 0;
    string valuable = " ";
    MagicDeck Deck;
    
    Deck.readDeck();
    Deck.print();
    
    quantity = Deck.mostNumerous();
    cout << "The card with the most duplicates has "<< quantity << " cards. ";
    cout << endl;
    
    value = Deck.totalValue();
    cout << "The total value of the deck is $" << value << "." <<  endl;
    
    valuable = Deck.mostValuable();
    cout << "The most valuable card in this deck is " << valuable << "." << endl;
    
    return 0;
}