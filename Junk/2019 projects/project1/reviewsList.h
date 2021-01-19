#include "reviews.h"

class reviewList
{
public:
    reviewList();
    ~reviewList();

    void insert(string name, string restaurant, string date, int food, int service, int value, int atmosphere, string comments);
    void printList(string restaurant);

private:
    reviews list[100];
    int count;
};