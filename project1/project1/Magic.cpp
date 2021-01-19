#include "Magic.h"


Magic::Magic()
{
    CardName = "blank";
    ManaCost = "blank";
    Type = "blank";
    CardText = "blank";
    CardNumber = 0;
    Rarity = "blank";
    Condition = "blank";
    PurchasePrice = 0.0;
    CurrentValue = 0.0;
    Quantity = 0;
}

Magic::~Magic() 
{
    
}
    
void Magic::print()
{
    cout << "Card name: " << CardName << endl 
         << "Mana Cost: " << ManaCost << endl
         << "Type: " << Type << endl
         << "Card text: " << CardText << endl
         << "Card number: " << CardNumber << endl
         << "Rarity: " << Rarity << endl
         << "Condition: " << Condition << endl
         << "Purchase price: " << PurchasePrice << endl
         << "Current value: " << CurrentValue << endl
         << "Quantity: " << Quantity << endl;
    cout << endl;
}
    
string Magic::getCardName()
{
    return CardName;
}

string Magic::getManaCost()
{
    return ManaCost;
}

string Magic::getType()
{
    return Type;
}

string Magic::getCardText()
{
    return CardText;
}

int Magic::getCardNumber()
{
    return CardNumber;
}

string Magic::getRarity()
{
    return Rarity;
}

string Magic::getCondition()
{
    return Condition;
}

float Magic::getPurchasePrice()
{
    return PurchasePrice;
}

float Magic::getCurrentValue()
{
    return CurrentValue;
}
int Magic::getQuantity()
{
    return Quantity;
}
    
void Magic::setCardName(string cardName)
{
    CardName = cardName;
}
    
void Magic::setManaCost(string manaCost)
{
    ManaCost = manaCost;
}
    
void Magic::setType(string type)
{
    Type = type;
}
    
void Magic::setCardText(string cardText)
{
    CardText = cardText;
}
    
void Magic::setCardNumber(int cardNumber)
{
    CardNumber = cardNumber;
}
    
void Magic::setRarity(string rarity)
{
    Rarity = rarity;
}
    
void Magic::setCondition(string condition)
{
    Condition = condition;
}
    
void Magic::setPurchasePrice(float purchasePrice)
{
    PurchasePrice = purchasePrice;
}
    
void Magic::setCurrentValue(float currentValue)
{
    CurrentValue = currentValue;
}
    
void Magic::setQuantity(int quantity)
{
    Quantity = quantity;
}

