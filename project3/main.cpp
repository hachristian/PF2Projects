#include <iostream>
#include <fstream>
#include "Dictionary.h"
using namespace std;

int main()
{
	string bookName = "";
	string response = "";
	float readingLvl = 0.0;
	bool exit = false;

	cout << "Welcome! Please enter input file name ";
	cin >> bookName;

	Dictionary Book(bookName);
	Book.read();
	readingLvl = Book.getReadingLvl();
	if (readingLvl > 0)
		cout << bookName << " reading level is: " << readingLvl << endl;

	while (exit != true)
	{
		cout << "Would you like to try another file? y/n ";
		cin >> response;

		if (response == "Yes" || response == "yes" || response == "y")
		{
			cout << "Please enter the input file name ";
			cin >> bookName;
			Book.setBookName(bookName);
			Book.setReadingLvl(0.0);
			Book.read();
			readingLvl = Book.getReadingLvl();
			//looks cleaner when the file cant be opened
			if (readingLvl > 0)
				cout << bookName << " reading level is: " << readingLvl << endl;
		}
		else if (response == "No" || response == "no" || response == "n")
		{
			cout << "Good bye!\n";
			exit = true;
		}
		else
			cout << "Please enter yes or no\n";
		

	}

	return 0;
}