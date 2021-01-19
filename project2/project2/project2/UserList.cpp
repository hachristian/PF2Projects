#include "UserList.h"

UserList::UserList()
{
	UserCount = 0;
	TotalMessageCount = 0;
	MessageCount = 0;
	Head = NULL;
}

UserList::~UserList()
{
	// deleting nodes in list
	while (Head != NULL)
	{
		UserNode* ptr = Head;
		Head = Head->getNext();
		delete ptr;
	}
}

int UserList::getTotalMessageCount()
{
	return TotalMessageCount;
}

void UserList::findNode()
{
	UserNode* ptr = Head;
	UserNode* most = ptr;
	int temp = 0;
	int target = 0;

	while (ptr != NULL)
	{
		temp = ptr->getMessageCount();
		target = most->getMessageCount();

		if (temp > target)
			most = ptr;

		ptr = ptr->getNext();
	}

	cout << "User with the most messages is \n";
	most->print();
}

void UserList::updateMsg(string handle)
{
	UserNode* ptr = Head;
	string name = "";
	int messages = 0;
	bool found = false;

	while (ptr != NULL || name == handle)
	{
		name = ptr->getHandle();

		if (name == handle)
		{
			messages = ptr->getMessageCount();
			cout << "User " << handle << " has been found! \n";
			cout << handle << " has " << messages << " messages. \n";
			messages++;
			cout << "User " << "now has " << messages << " messages \n";
			ptr->setMessageCount(messages);
			TotalMessageCount++;
			cout << "group message count now has " << TotalMessageCount << " messages.\n";
			found = true;
		}
		ptr = ptr->getNext();
	}
	// only if user is not fount
	if (found != true)
		cout << "User " << handle << " could not be found.\n";

}

void UserList::addNode(string firstName, string lastName, string handle, unsigned long long int phoneNum, int messageCount)
{
	UserNode* ptr = Head;
	UserNode* temp = NULL;

	while (ptr != NULL && ptr->getNext() != NULL)
		ptr = ptr->getNext();
	// inserting to end of list
	if (ptr != NULL)
	{
		temp = new UserNode(firstName, lastName, handle, phoneNum, messageCount);
		ptr->setNext(temp);
		temp->setNext(NULL);
	}
	else
	{
		Head = new UserNode(firstName, lastName, handle, phoneNum, messageCount);
		Head->setNext(NULL);
	}
	// incrementing user count and adding user messages to total message count
	UserCount++;
	TotalMessageCount += messageCount;
}

void UserList::printList()
{
	UserNode* ptr = Head;
	cout << "There are " << UserCount << " users in this group. \n";
	while (ptr != NULL)
	{
		ptr->print();
		ptr = ptr->getNext();
		cout << endl;
	}
	
}
