#include <iostream>
using namespace std;

class reviews
{
public:
    reviews();
    ~reviews();

    string getName();
    string getRestaurant();
    string getDate();
    int getFood();
    int getService();
    int getValue();
    int getAtmosphere();
    string getComments();

    void setName(string name);
    void setRestaurant(string restaurant);
    void setDate(string date);
    void setFood(int food);
    void setService(int service);
    void setValue(int value);
    void setAtmosphere(int atmosphere);
    void setComments(string comments);
    void print();

private:
    string Name;
    string Restaurant;
    string Date;
    int Food;
    int Service;
    int Value;
    int Atmosphere;
    string Comments;
};