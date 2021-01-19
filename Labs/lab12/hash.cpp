#include "hash.h"

int foo = 0;
//-----------------------------------------------------------
// Constructor
//-----------------------------------------------------------
HashTable::HashTable(int size)
{
    Size = size;
    Count = 0;
    Value = new int[Size];
    Key = new int[Size];

    for (int index = 0; index < Size; index++)
    {
        Value[index] = NONE;
        Key[index] = EMPTY;
    }
}

//-----------------------------------------------------------
// Copy constructor
//-----------------------------------------------------------
HashTable::HashTable(const HashTable &ht)
{
    Size = ht.Size;
    Count = ht.Count;
    Value = new int[Size];
    Key = new int[Size];

    for (int index = 0; index < Size; index++)
    {
        Value[index] = ht.Value[index];
        Key[index] = ht.Key[index];
    }
}

//-----------------------------------------------------------
// Destructor
//-----------------------------------------------------------
HashTable::~HashTable()
{
    delete[] Value;
    delete[] Key;
}

//-----------------------------------------------------------
// Insert method
//-----------------------------------------------------------
bool HashTable::Insert(int key, int value)
{
    // Find desired key
    int index = Hash(key);
    if (Count > Size)
        return false;
    while ((Key[index] != key) && (Key[index] != EMPTY))
        index = Hash2(index);

    // Insert value into hash table
    Value[index] = value;
    Key[index] = key;
    Count++;
    return true;
}

//-----------------------------------------------------------
// Search method
//-----------------------------------------------------------
bool HashTable::Search(int key, int &value)
{
    // Find desired key
    int index = Hash(key);
    while ((Key[index] != key) && (Key[index] != EMPTY))
        index = Hash2(index);

    // Return value from hash table
    if (Key[index] == key)
        value = Value[index];
    return (Key[index] == key);
}

//-----------------------------------------------------------
// Delete method
//-----------------------------------------------------------
bool HashTable::Delete(int key)
{
    // Find desired key
    int index = Hash(key);
    while ((Key[index] != key) && (Key[index] != EMPTY))
        index = Hash2(index);

    // Delete value from hash table
    if (Key[index] == key)
    {
        Value[index] = NONE;
        Key[index] = DELETED;
        return true;
    }
    return false;
}

//-----------------------------------------------------------
// Primary hash function
//-----------------------------------------------------------
int HashTable::Hash(int key)
{
    return key % Size;
}

//-----------------------------------------------------------
// Secondary hash function
//-----------------------------------------------------------
int HashTable::Hash2(int index)
{
    foo++;
    cout << "COLLISION " << foo << endl;
    return (index + 1) % Size;
}

//-----------------------------------------------------------
// Print function for debugging
//-----------------------------------------------------------
void HashTable::Print()
{
    cout << "Index\t"
         << "Value\t"
         << "Key\n";
    for (int index = 0; index < Size; index++)
        cout << index << "\t"
             << Value[index] << "\t"
             << Key[index] << "\n";
}