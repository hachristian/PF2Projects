#include "UserNode.h"

UserNode::UserNode()
{
	FirstName = "";
	LastName = "";
	Handle = "";
	PhoneNum = 0;
	MessageCount = 0;
	Next = NULL;
}

UserNode::UserNode(string firstName, string lastName, string handle, unsigned long long int phoneNum, int messageCount)
{
	FirstName = firstName;
	LastName = lastName;
	Handle = handle;
	PhoneNum = phoneNum;
	MessageCount = messageCount;
	Next = NULL;
}

UserNode::~UserNode()
{
}

string UserNode::getFirstName()
{
	return FirstName;
}

string UserNode::getLastName()
{
	return LastName;
}

string UserNode::getHandle()
{
	return Handle;
}

unsigned long long int UserNode::getPhoneNum()
{
	return PhoneNum;
}

int UserNode::getMessageCount()
{
	return MessageCount;
}

UserNode* UserNode::getNext()
{
	return Next;
}

void UserNode::setFirstName(string firstName)
{
	FirstName = firstName;
}

void UserNode::setLastName(string lastName)
{
	LastName = lastName;
}

void UserNode::setHandle(string handle)
{
	Handle = handle;
}

void UserNode::setPhoneNum(unsigned long long int phoneNum)
{
	PhoneNum = phoneNum;
}

void UserNode::setMessageCount(int messageCount)
{
	MessageCount = messageCount;
}

void UserNode::setNext(UserNode* next)
{
	Next = next;
}

void UserNode::print()
{
	cout << "First Name: " << FirstName << endl
		<< "Last Name: " << LastName << endl
		<< "Handle: " << Handle << endl
		<< "Phone number: " << PhoneNum << endl
		<< "Message count: " << MessageCount << endl;
}