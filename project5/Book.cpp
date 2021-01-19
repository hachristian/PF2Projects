#include "Book.h"

Book::Book()
{
    BookName = "";
}

Book::Book(string bookName)
{
    BookName = bookName;
}

Book::~Book()
{
}

string Book::getBookName()
{
    return BookName;
}

string Book::fixWord(string word)
{
    // Loop over characters to fix word
    string result = "";
    for (int i = 0; i < (int)word.length(); i++)
    {
        // Save lower case letters
        if ((word[i] >= 'a') && (word[i] <= 'z'))
            result += word[i];

        // Save upper case letters as lower case letters
        else if ((word[i] >= 'A') && (word[i] <= 'Z'))
            result += word[i] - 'A' + 'a';
    }
    return result;
}

void Book::setBookName(string bookName)
{
    BookName = bookName;
}

bool Book::read()
{
    ifstream din;
    din.open(BookName.c_str());
    if (din.fail())
    {
        cout << "Couldn't open the book!\n";
        return false;
    }

    string str = "";
    string result = "";

    while (din >> str)
    {
        result = fixWord(str);
        if (result != "")
        {
            book.push_back(result);
        }
    }
    return true;
}

void Book::sort()
{
    vector<string> alphabet[26];
    string temp = "";

    // organizes everything so their vectors
    for (unsigned int i = 0; i < book.size() - 1; i++)
    {
        temp = book[i];

        if (temp[0] == 'a')
            alphabet[0].push_back(book[i]);
        else if (temp[0] == 'b')
            alphabet[1].push_back(book[i]);
        else if (temp[0] == 'c')
            alphabet[2].push_back(book[i]);
        else if (temp[0] == 'd')
            alphabet[3].push_back(book[i]);
        else if (temp[0] == 'e')
            alphabet[4].push_back(book[i]);
        else if (temp[0] == 'f')
            alphabet[5].push_back(book[i]);
        else if (temp[0] == 'g')
            alphabet[6].push_back(book[i]);
        else if (temp[0] == 'h')
            alphabet[7].push_back(book[i]);
        else if (temp[0] == 'i')
            alphabet[8].push_back(book[i]);
        else if (temp[0] == 'j')
            alphabet[9].push_back(book[i]);
        else if (temp[0] == 'k')
            alphabet[10].push_back(book[i]);
        else if (temp[0] == 'l')
            alphabet[11].push_back(book[i]);
        else if (temp[0] == 'm')
            alphabet[12].push_back(book[i]);
        else if (temp[0] == 'n')
            alphabet[13].push_back(book[i]);
        else if (temp[0] == 'o')
            alphabet[14].push_back(book[i]);
        else if (temp[0] == 'p')
            alphabet[15].push_back(book[i]);
        else if (temp[0] == 'q')
            alphabet[16].push_back(book[i]);
        else if (temp[0] == 'r')
            alphabet[17].push_back(book[i]);
        else if (temp[0] == 's')
            alphabet[18].push_back(book[i]);
        else if (temp[0] == 't')
            alphabet[19].push_back(book[i]);
        else if (temp[0] == 'u')
            alphabet[20].push_back(book[i]);
        else if (temp[0] == 'v')
            alphabet[21].push_back(book[i]);
        else if (temp[0] == 'w')
            alphabet[22].push_back(book[i]);
        else if (temp[0] == 'x')
            alphabet[23].push_back(book[i]);
        else if (temp[0] == 'y')
            alphabet[24].push_back(book[i]);
        else if (temp[0] == 'z')
            alphabet[25].push_back(book[i]);
    }

    for (int i = 0; i < 26; i++)
    {
        mergeSort(alphabet[i], 0, alphabet[i].size() - 1);
    }

    int position = 0;
    for (int i = 0; i < 26; i++)
    {
        for (unsigned int j = 0; j < alphabet[i].size(); j++)
        {
            book[position] = alphabet[i][j];
            position++;
        }
    }
}

void Book::mergeSort(vector<string> &data, int low, int high)
{
    // Check terminating condition
    int range = high - low + 1;

    if (range > 1)
    {
        // Divide the array and sort both halves
        int mid = (low + high) / 2;
        mergeSort(data, low, mid);
        mergeSort(data, mid + 1, high);

        // Create temporary array for merged data
        vector<string> copy;
        copy.resize(data.size());

        // Initialize array indices
        int index1 = low;
        int index2 = mid + 1;
        int index = 0;

        // Merge smallest data elements into copy array
        while (index1 <= mid && index2 <= high)
        {
            if (data[index1] < data[index2])
                copy[index++] = data[index1++];
            else
                copy[index++] = data[index2++];
        }

        // Copy any remaining entries from the first half
        while (index1 <= mid)
            copy[index++] = data[index1++];

        // Copy any remaining entries from the second half
        while (index2 <= high)
            copy[index++] = data[index2++];

        // Copy data back from the temporary array
        for (index = 0; index < range; index++)
            data[low + index] = copy[index];
        copy.clear();
    }
}

void Book::frequency()
{
    ofstream dout;
    dout.open("book.count");

    string word = book[0];
    int count = 0;

    for (unsigned int i = 0; i < book.size(); i++)
    {
        if (word == book[i])
        {
            count++;
        }
        else
        {
            dout << word << " " << count << endl;
            word = book[i];
            count = 1;
        }
    }
    dout.close();
}

void Book::print()
{
    cout << "in print\n";
    for (int i = 0; i < 99; i++)
    {
        cout << book[i] << endl;
    }
    cout << "left print\n";
}