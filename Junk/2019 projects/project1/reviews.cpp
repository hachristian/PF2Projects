#include "reviews.h"

reviews::reviews()
{
    Name = "";
    Restaurant = "";
    Date = "";
    Food = 0;
    Service = 0;
    Value = 0;
    Atmosphere = 0;
    Comments = "";
}

reviews::~reviews()
{
}

string reviews::getName()
{
    return Name;
}

string reviews::getRestaurant()
{
    return Restaurant;
}

string reviews::getDate()
{
    return Date;
}

int reviews::getFood()
{
    return Food;
}

int reviews::getService()
{
    return Service;
}

int reviews::getValue()
{
    return Value;
}

int reviews::getAtmosphere()
{
    return Atmosphere;
}

string reviews::getComments()
{
    return Comments;
}

void reviews::setName(string name)
{
    Name = name;
}

void reviews::setRestaurant(string restaurant)
{
    Restaurant = restaurant;
}

void reviews::setFood(int food)
{
    Food = food;
}

void reviews::setService(int service)
{
    Service = service;
}

void reviews::setValue(int value)
{
    Value = value;
}

void reviews::setAtmosphere(int atmosphere)
{
    Atmosphere = atmosphere;
}

void reviews::setComments(string comments)
{
    Comments = comments;
}