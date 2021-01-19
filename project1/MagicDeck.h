#ifndef MAGICDECK_H
#define MAGICDECK_H

#include "Magic.h"
#include <fstream>
#include <cstdlib>
#include <string>

const int SIZE = 1000;

class MagicDeck {
public:
    MagicDeck();
    ~MagicDeck();   
    
    float totalValue();
    int mostNumerous();
    string mostValuable();
    
    void print();
    void readDeck();
    
private:
    Magic Deck[SIZE];
    int count;

};

#endif 

