#include "Stack.h"

Stack::Stack()
{
    Count = 0;
    Top = 0;
}

Stack::~Stack()
{
    data.clear();
}

void Stack::push(int number)
{
    data.push_back(number);
    Top = number;
    Count++;
}

int Stack::pop()
{
    int temp = data.back();
    data.pop_back();
    Count--;
    return temp;
}

int Stack::top()
{
    return Top;
}

bool Stack::isFull()
{
    if (data.size() == data.max_size())
        return true;

    return false;
}

bool Stack::isEmpty()
{
    if (Count == 0)
        return true;

    return false;
}

int Stack::getCount()
{
    return Count;
}

void Stack::print()
{
    if (!isEmpty())
    {
        cout << "[";

        for (unsigned int i = 0; i < data.size(); i++)
        {
            cout << data[i] << "|";
        }

        cout << endl;
    }
    else
    {
        cout << "Stack is empty!\n";
    }
}