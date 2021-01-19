#ifndef USERNODE_H
#define USERNODE_H

#include <iostream>

using namespace std;

class UserNode
{
public:
	//Constructors and destructor
	UserNode();
	UserNode(string firstName, string lastName, string handle, unsigned long long int phoneNum, int messageCount);
	~UserNode();

	//Methods
	string getFirstName();
	string getLastName();
	string getHandle();
	unsigned long long int getPhoneNum();
	int getMessageCount();
	UserNode* getNext();

	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setHandle(string handle);
	void setPhoneNum(unsigned long long int phoneNum);
	void setMessageCount(int messageCount);
	void setNext(UserNode* next);
	void print();

private:
	string FirstName;
	string LastName;
	string Handle;
	unsigned long long int PhoneNum;
	int MessageCount;
	UserNode* Next;
};

#endif