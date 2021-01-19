#ifndef MAGIC_H
#define MAGIC_H

#include <iostream>
using namespace std;

class Magic {
public:
    Magic();
    ~Magic();
    
    string getCardName();
    string getManaCost();
    string getType();
    string getCardText();
    int getCardNumber();
    string getRarity();
    string getCondition();
    float getPurchasePrice();
    float getCurrentValue();
    int getQuantity();
    
    void print();
    void setCardName(string cardName);
    void setManaCost(string manaCost);
    void setType(string type);
    void setCardText(string cardText);
    void setCardNumber(int cardNumber);
    void setRarity(string rarity);
    void setCondition(string condition);
    void setPurchasePrice(float purchasePrice);
    void setCurrentValue(float currentValue);
    void setQuantity(int quantity);
     
private:
    string CardName;
    string ManaCost;
    string Type;
    string CardText;
    int CardNumber;
    string Rarity;
    string Condition;
    float PurchasePrice;
    float CurrentValue;
    int Quantity;
    
};

#endif 

