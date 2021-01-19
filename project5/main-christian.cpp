#include "Book.h"

int main()
{
    Book book("AnneGables.txt");
    book.read();
    // checking to see how it looks
    book.sort();
    cout << "finished program\n";
    return 0;
}
