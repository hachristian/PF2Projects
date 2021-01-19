#include "MagicDeck.h"

MagicDeck::MagicDeck() 
{
    int count = 0;
}

MagicDeck::~MagicDeck() 
{
    
}

void MagicDeck::print()
{
    cout << "You have " << count << " unique cards. " << endl;
    for(int i = 0; i < count; i++)
    {
        Deck[i].print();
    }
}

void MagicDeck::readDeck()
{
    //open file
    ifstream din;
    din.open("MagicDeck.txt");
    if(din.fail())
        cout << "Couldn't open file." << endl;
    
    //counts the lines
    string str;
    getline(din, str);
    count = atoi(str.c_str());
    
    //loops through document
    for(int i = 0; i < count && !din.eof(); i++)
    {
        getline(din, str);
        Deck[i].setCardName(str);
        getline(din, str);
        Deck[i].setManaCost(str);
        getline(din, str);
        Deck[i].setType(str);
        getline(din, str);
        Deck[i].setCardText(str);
        getline(din, str);
        Deck[i].setCardNumber(atoi(str.c_str()));
        getline(din, str);
        Deck[i].setRarity(str);
        getline(din, str);
        Deck[i].setCondition(str);
        getline(din, str);
        Deck[i].setPurchasePrice(atof(str.c_str()));
        getline(din, str);
        Deck[i].setCurrentValue(atof(str.c_str()));
        getline(din, str);
        Deck[i].setQuantity(atoi(str.c_str()));
    }   
}

int MagicDeck::mostNumerous()
{
    int quantity = 0;
    int temp = 0;
    for(int i = 0; i < count; i++)
    {
        temp = Deck[i].getQuantity();
        if(temp > quantity)
            quantity = temp;
    }
    
    return quantity;
}

float MagicDeck::totalValue()
{
    float totalValue = 0.0;
    float value = 0.0;
    int quantity = 0;
    float temp = 0.0;
    
    for(int i = 0; i < count; i++)
    {
        quantity = Deck[i].getQuantity();
        value = Deck[i].getCurrentValue();
        temp = quantity * value;
        totalValue += temp;
    }
    
    return totalValue;
}

string MagicDeck::mostValuable()
{
    float temp = 0.0;
    float value = 0.0;
    string card;
    
    for(int i = 0; i < count; i++)
    {
        temp = Deck[i].getCurrentValue();
        if(temp > value)
        {
            value = temp;
            card = Deck[i].getCardName();
        }
    }
    
    return card;
}

