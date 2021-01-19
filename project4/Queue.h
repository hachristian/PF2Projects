#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Queue
{
public:
    Queue();
    ~Queue();

    void insert(int number);
    int remove();

    bool isFull();
    bool isEmpty();
    int getCount();
    int getSize();
    void setSize(int size);
    void print();

private:
    int Size;
    int Count;
    int Front;
    int Back;
    vector<int> data;
};
#endif