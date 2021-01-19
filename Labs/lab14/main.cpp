#include "Heap.h"

int main()
{

    int num = 0;

    cout << "Please enter a number\n";
    cin >> num;

    Heap heap(num);

    int temp = 0;
    srand(time(NULL));

    for (int i = 0; i < num; i++)
    {
        temp = rand() % num;
        heap.Insert(temp);
    }

    heap.Print();

    int i = 0;
    while(!heap.IsEmpty())
    {
        heap.Remove(i);
        cout << i << " was removed.\n";
        heap.Print();
    }

    return 0;
}