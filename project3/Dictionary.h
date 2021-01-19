#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Dictionary
{
public:
	Dictionary();
	Dictionary(string bookName);
	~Dictionary();

	float getReadingLvl();
	int binarySearch(string data[], string target, int low, int high);
	
	void read();
	
	void setBookName(string bookName);
	void setReadingLvl(float readingLvl);
	

private:
	void setWordList();
	string BookName;
	string Word[1000];
	float ReadingLvl;
	int Rank[1000];

};

#endif

