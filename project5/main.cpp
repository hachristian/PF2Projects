#include "Book.h"

int main()
{
    string bookName = "";
    string answer = "";
    bool entry = true;
    cout << "Welcome to the book sorter\n";
    cout << "Please enter a book name. ";
    cin >> bookName;

    Book book(bookName);

    entry = book.read();
    while (entry != true)
    {
        cout << "Would you like to enter another book name? ";
        cin >> answer;

        if (answer == "Yes" || answer == "yes" || answer == "Y" || answer == "y")
        {
            cout << "enter book name. ";
            cin >> bookName;
            book.setBookName(bookName);
            entry = book.read();
        }
        else if (answer == "No" || answer == "no" || answer == "N" || answer == "n")
        {
            cout << "GoodBye!\n";
            entry = true;
        }
        else
        {
            cout << "sorry couldn't understand please enter (y/n)\n";
        }
        }

    book.sort();
    book.frequency();
    return 0;
}
