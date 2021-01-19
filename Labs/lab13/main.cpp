#include "tree.h"

int main()
{
    BinaryTree tree;
    int size = 1024;
    int temp = 0;

    for (int i = 0; i < size; i++)
    {
        tree.Insert(i);
    }
    cout << "tree height = " << tree.height() << endl;

    srand(time(NULL));

    BinaryTree tree2;
    for (int i = 0; i < size; i++)
    {
        temp = rand() % size;
        tree2.Insert(temp);
    }
    cout << "tree2 height = " << tree2.height() << endl;

    return 0;
}