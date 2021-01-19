#ifndef USERLIST_H
#define USERLIST_H

#include "UserNode.h"

class UserList
{
public:
	UserList();
	~UserList();

	int getTotalMessageCount();

	void findNode();
	void updateMsg(string handle);
	void addNode(string firstName, string lastName, string handle, unsigned long long int phoneNum, int messageCount);
	void printList();

private:
	int UserCount;
	int TotalMessageCount;
	int MessageCount;
	UserNode* Head;
};



#endif 