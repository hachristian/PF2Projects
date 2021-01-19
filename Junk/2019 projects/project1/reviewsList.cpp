#include "reviewsList.h"

reviewList::reviewList()
{
    count = 0;
}

reviewList::~reviewList()
{

}

void reviewList::insert(string name, string restaurant, string date, int food, int service, int value, int atmosphere, string comments)
{
    list[count].setName(name);
    list[count].setRestaurant(restaurant);
    list[count].setDate(date);
    list[count].setFood(food);
    list[count].setService(service);
    list[count].setAtmosphere(atmosphere);
    list[count].setComments(comments);
    count++;
}

void reviewList::printList(string restaurant)
{
    for (int i = 0; i < count; i++)
    {
        if (list[count].getRestaurant() == restaurant)
            list[count].print();
    }
}