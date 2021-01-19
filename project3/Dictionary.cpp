#include "Dictionary.h"

Dictionary::Dictionary()
{
	ReadingLvl = 0.0;
	Rank[0] = 0;
	Word[0] = "";
	BookName = "";
}

Dictionary::Dictionary(string bookName)
{
	ReadingLvl = 0.0;
	Rank[0] = 0;
	Word[0] = "";
	BookName = bookName;
}

Dictionary::~Dictionary()
{
}

int Dictionary::binarySearch(string data[], string word, int low, int high)
{
	int mid = (high + low) / 2;

	if (low > high)
		return -1;
	else if (data[mid] == word)
		return mid;
	else if (data[mid] > word)
		return binarySearch(data, word, low, mid - 1);
	else if (data[mid] < word)
		return binarySearch(data, word, mid + 1, high);

	return -1;
}

float Dictionary::getReadingLvl()
{
	return ReadingLvl;
}


void Dictionary::read()
{
	ifstream din;
	int Count = 0;
	setWordList();

	din.open(BookName.c_str());

	if (din.fail())
	{
		cout << "File failed to open!\n";
		return;
	}

	string str = "";
	int wordLvl = 0;
	int location = 0;

	//getting array size
	while (!din.eof())
	{
		din >> str;

		int length = str.length();

		//deletes punctuation and sets every letter to lowercase
		for (int i = 0; i < length; i++)
		{
			if (ispunct(str[i]))
			{
				str.erase(i, 1);
				length--;
				// checking if another punctuation took its place.
				if (ispunct(str[i]))
				{
					str.erase(i, 1);
					length--;
				}
				//making sure the letter that takes its place is lowercase
				str[i] = (char)tolower(str[i]);
			}
			str[i] = (char)tolower(str[i]);
		}

		location = binarySearch(Word, str, 0, 1000);

		// if location isnt found lvl is 1001
		if (location == -1)
			wordLvl = 1001;
		else
			wordLvl = Rank[location];
		ReadingLvl += wordLvl;
		Count++;
	}
	din.close();

	float average = ReadingLvl / Count;
	ReadingLvl = average;
}

void Dictionary::setWordList()
{
	ifstream din;
	string file = "";
	int i = 0;

	din.open("words.txt");

	while (!din.eof())
	{
		din >> Rank[i] >> Word[i];
		i++;
	}

	din.close();
}

void Dictionary::setBookName(string bookName)
{
	BookName = bookName;
}

void Dictionary::setReadingLvl(float readingLvl)
{
	ReadingLvl = readingLvl;
}
