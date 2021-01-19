#include "Queue.h"

Queue::Queue()
{
    Size = 5;
    Count = 0;
    Front = 0;
    Back = -1;
    data.resize(Size);
}

Queue::~Queue()
{
    data.clear();
}

void Queue::insert(int number)
{
    if (!isFull())
    {
        Back = (Back + 1) % Size;

        cout << "Front = " << Front << endl;
        cout << "Back = " << Back << endl;
        data[Back] = number;
        Count++;
    }
    else
        cout << "Queue overflow!\n";
}

int Queue::remove()
{
    if (!isEmpty())
    {
        int temp = 0;
        temp = data[Front];
        data[Front] = -1;
        cout << "Front before = " << Front << endl;
        Front = (Front + 1) % Size;
        cout << "Front = " << Front << endl;
        cout << "Back = " << Back << endl;
        Count--;
        return temp;
    }
    else
        cout << "Queue underflow!\n";

    return -1;
}

bool Queue::isFull()
{
    if (Count >= Size)
        return true;

    return false;
}

bool Queue::isEmpty()
{
    if (Count <= 0)
        return true;

    return false;
}

int Queue::getCount()
{
    return Count;
}

int Queue::getSize()
{
    return Size;
}

void Queue::setSize(int size)
{
    
    Size += size;
    data.resize(Size);
    cout << "back if +1 " << ((Back + 1) % Size) << endl;
    cout << "back if -1 " << ((Back - 1) % Size) << endl;
    
    if (((Back + 1) % Size) == Front || ((Back - 1) % Size) == Front)
    {
        cout << "In if\n";
        if (Front != 0)
        {
            // number of spaces to move
            int offset = Size - Count;
            cout << "offset = " << offset << endl;
            int temp = 0;
            cout << "Front = " << Front << endl;
            cout << "Size = " << Size << endl;
            int oldPos = Front;
            int newPos = Front + offset;
            // shifts values
            for (int i = 0; i < size; i++)
            {
                cout << "newPos = " << newPos << endl;
                temp = data[oldPos];
                data[oldPos] = 0;
                data[newPos] = temp;
                oldPos++;
                newPos++;
            }
            // updates the front
            Front += offset;
        }
    }
}

void Queue::print()
{
    cout << "Count = " << Count << endl;
    if (Count != 0)
    {
        for (int i = 0; i < Size; i++)
        {
            cout << data[i] << "|";
        }
        cout << endl;
    }
    else
    {
        cout << "Queue is empty!\n";
    }
}