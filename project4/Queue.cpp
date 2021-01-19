#include "Queue.h"

Queue::Queue()
{
    //starting size i want
    Size = 1000;
    Count = 0;
    Front = 0;
    Back = -1;
    data.resize(Size);
}

Queue::~Queue()
{
    //vector method to clear queue
    data.clear();
}

void Queue::insert(int number)
{
    if (!isFull())
    {
        Back = (Back + 1) % Size;
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
        Front = (Front + 1) % Size;
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
    if (size <= 0)
    {
        cout << "we recieved a negative input so we increased the size by 100.\n";
        size = 100;
    }

    Size += size;
    data.resize(Size);

    // checking if the queue needs shifting
    if (((Back + 1) % Size) == Front || ((Back - 1) % Size) == Front)
    {
        if (Front != 0)
        {
            // number of spaces to move
            int offset = Size - Count;
            int temp = 0;
            int oldPos = Front;
            int newPos = Front + offset;
            // a flag to stop inputting 0
            int stop = newPos - 1;

            // shifts values
            for (int i = Front; i < (offset + Front); i++)
            {
                cout << "newPos = " << newPos << endl;
                cout << "i = " << i << endl;
                temp = data[oldPos];
                cout << "Moving " << temp << endl;
                cout << "oldPos = " << oldPos << endl;
                if (oldPos != stop)
                {
                    cout << "added the 0 at the oldPos\n";
                    data[oldPos] = 0;
                }
                if (newPos < Size)
                {
                    cout << "inerted into newPos\n";
                    data[newPos] = temp;
                }
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