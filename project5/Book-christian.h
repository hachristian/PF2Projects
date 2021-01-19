#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Book
{
public:
    Book();
    Book(string bookName);
    ~Book();

    string getBookName();
    string fixWord(string word);

    void setBookName(string bookName);
    void read();
    void sort();
    void mergeSort(vector<string> &data, int low, int high);
    void frequency();
    void print();

private:
    string BookName;
    int Count;

    vector<string> book;
};

#endif
