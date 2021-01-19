#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

void print(vector<int> values)
{
    for (unsigned int i = 0; i < values.size(); i++)
    {
        cout << values[i] << " ";
    }

    cout << endl;
}

void randomize(vector<int> &values)
{
    srand(time(NULL));
    int temp = 0;

    if (values.size() == 0)
        values.resize(20);

    for (unsigned int i = 0; i < values.size(); i++)
    {
        temp = rand() % values.size();
        values[i] = temp;
    }
}

void addValue(vector<int> &values, int num)
{
    if (values.size() == 0)
        values.resize(20);

    for (unsigned int i = 0; i < values.size(); i++)
    {
        values[i] = num;
    }
}

void zero(vector<int> &values, int start, int end)
{
    if (start > end)
        return;
    else if (start < 0)
        return;

    for (int i = start; i <= end; i++)
    {
        if ((unsigned int)i < values.size())
            values[i] = 0;
        else
            break;
    }
}

void reverse(vector<int> &values)
{
    int temp = 0;
    int front = 0;
    int back = values.size() - 1;

    while (front < back)
    {
        temp = values[front];

        values[front] = values[back];
        values[back] = temp;

        front++;
        back--;
    }
}

float average(vector<int> values)
{
    int size = values.size();
    float total = 0;
    float average = 0.0;

    if (size == 0)
        return 0;

    for (int i = 0; i < size; i++)
    {
        total += values[i];
    }

    average = total / size;

    return average;
}

void magic(vector<int> &values)
{
    for (unsigned int i = 0; i < values.size(); i++)
    {
        if ((values[i] % 2) == 0)
        {
            values[i] += 1;
        }
        else
        {
            values[i] -= 1;
        }
    }
}

void repeat(vector<int> &values)
{
    int size = values.size();
    values.resize(size * 2);

    for (int i = 0; i < size; i++)
    {
        values[i + size] = values[i];
    }
}

void chop(vector<int> &values)
{
    int size = values.size();
    values.resize(size / 2);
}

void john(vector<int> &values)
{
    int size = values.size();
    int temp = values[(size / 2) - 1];

    values.push_back(0);

    for (int i = size; i > (size / 2) - 1; i--)
    {
        temp = values[i];
        values[i + 1] = temp;
    }

    temp = values[(size / 2) - 1];
    values[(size / 2) - 1] = 42;
    values[size / 2] = temp;
}

int main()
{
    vector<int> array;

    cout << "calling randomize\n";
    randomize(array);
    cout << "vector = ";
    print(array);

    cout << "calling addValue\n";
    addValue(array, 6);
    cout << "vector = ";
    print(array);

    cout << "calling zero\n";
    zero(array, 5, 18);
    cout << "vector = ";
    print(array);

    cout << "calling reverse\n";
    // setting the vector in acending order
    for (unsigned int i = 0; i < array.size(); i++)
        array[i] = i + 1;

    reverse(array);
    cout << "vector = ";
    print(array);

    cout << "calling average\n";
    cout << "average = " << average(array) << endl;

    cout << "calling magic\n";
    cout << "vector before = ";
    print(array);
    cout << "vector after = ";
    magic(array);
    print(array);
    cout << "calling magic one more time\n";
    cout << "vector = ";
    magic(array);
    print(array);

    cout << "calling repeat\n";
    repeat(array);
    cout << "vector = ";
    print(array);

    cout << "calling chop\n";
    chop(array);
    cout << "vector = ";
    print(array);

    cout << "calling john\n";
    john(array);
    cout << "vector = ";
    print(array);

    return 0;
}