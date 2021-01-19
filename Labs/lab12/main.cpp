#include "hash.h"

int main()
{
    srand(time(NULL));

    int SIZE = 0;
    int COUNT = 0;
    int MAX = 0;
    int key = 0;
    int value = 0;

    cout << "please enter size ";
    cin >> SIZE;
    cout << "now enter count ";
    cin >> COUNT;
    cout << "enter max ";
    cin >> MAX;

    MAX = 1000;

    HashTable hash(40);

    for (int i = 0; i < COUNT; i++)
    {
        key = rand() % MAX;
        value = rand() % MAX;

        hash.Insert(key, value);
    }

    hash.Print();

    return 0;
}