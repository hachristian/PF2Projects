#include "tree.h"

//-----------------------------------------------------------
// Constructor function.
//-----------------------------------------------------------
BinaryTree::BinaryTree()
{
    Root = NULL;
}

//-----------------------------------------------------------
// Destructor function.
//-----------------------------------------------------------
BinaryTree::~BinaryTree()
{
}

//-----------------------------------------------------------
// Search helper function.
//-----------------------------------------------------------
bool BinaryTree::SearchHelper(int Value, Node *Tree)
{
    // Data value not found
    if (Tree == NULL)
        return false;

    // Data value found
    else if (Tree->Value == Value)
        return true;

    // Recursively search for data value
    else if (Tree->Value > Value)
        return (SearchHelper(Value, Tree->Left));
    else if (Tree->Value < Value)
        return (SearchHelper(Value, Tree->Right));
}

//-----------------------------------------------------------
// Search for data in the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Search(int Value)
{
    // Call tree searching function
    return (SearchHelper(Value, Root));
}

//-----------------------------------------------------------
// Insert helper function.
//-----------------------------------------------------------
bool BinaryTree::InsertHelper(int Value, Node *&Tree)
{
    // Insert data into the tree
    if (Tree == NULL)
    {
        Tree = new Node;
        Tree->Value = Value;
        Tree->Left = NULL;
        Tree->Right = NULL;
        return true;
    }

    // Data value already inserted
    else if (Tree->Value == Value)
        return false;

    // Recursively search for insertion position
    else if (Tree->Value > Value)
        return (InsertHelper(Value, Tree->Left));
    else if (Tree->Value < Value)
        return (InsertHelper(Value, Tree->Right));
}

//-----------------------------------------------------------
// Insert data into the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Insert(int Value)
{
    // Call tree insertion function
    return (InsertHelper(Value, Root));
}

//-----------------------------------------------------------
// Print helper function.
//-----------------------------------------------------------
void BinaryTree::PrintHelper(Node *Tree)
{
    // Check terminating condition
    if (Tree != NULL)
    {
        // Print left subtree
        cout << "(";
        PrintHelper(Tree->Left);

        // Print node value
        cout << " " << Tree->Value << " ";

        // Print right subtree
        PrintHelper(Tree->Right);
        cout << ")";
    }
}

int BinaryTree::count()
{
    return (countHelper(Root));
}

int BinaryTree::countHelper(Node *ptr)
{
    if (ptr == NULL)
        return 0;

    return 1 + countHelper(ptr->Left) + countHelper(ptr->Right);
}

int BinaryTree::height()
{
    return (heightHelper(Root));
}

int BinaryTree::heightHelper(Node *ptr)
{
    if (ptr == NULL)
        return 0;

    int left = heightHelper(ptr->Left);
    int right = heightHelper(ptr->Right);

    if (left > right)
        return (left + 1);
    else
        return (right + 1);
}
//-----------------------------------------------------------
// Print all records in the binary tree.
//-----------------------------------------------------------
void BinaryTree::Print()
{
    // Call tree printing function
    PrintHelper(Root);
    cout << endl;
}