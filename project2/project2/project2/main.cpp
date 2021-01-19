#include "UserList.h"

void getInfo(string& firstName, string& lastName, string& handle, unsigned long long int& phoneNum, int& messageCount)
{
	cout << "Please enter first name: ";
	cin >> firstName;
	cout << "Please enter last name: ";
	cin >> lastName;
	cout << "Please enter handle: ";
	cin >> handle;
	cout << "Please enter phone number: ";
	cin >> phoneNum;
	//checking if number is within desired range.
	while (phoneNum < 1000000000 || phoneNum > 9999999999)
	{
		cout << "Please enter a 9 digit phone number! ";
		cin >> phoneNum;
	}
	cout << "Please enter message count: ";
	cin >> messageCount;
	while (messageCount < 0)
	{
		cout << "Please enter a postive number! ";
		cin >> messageCount;
	}
}

string menu()
{
	string answer = "";

	cout << "Type out the word or number for each these choices. \n";
	cout << "(1) Insert\n(2) Update\n(3) Find\n(4) Print\n(5) Exit\n";

	cin >> answer;

	if (answer == "Insert" || answer == "insert" || answer == "1")
		return "Insert";
	else if (answer == "Update" || answer == "update" || answer == "2")
		return "Update";
	else if (answer == "Find" || answer == "find" || answer == "3")
		return "Find";
	else if (answer == "Print" || answer == "print" || answer == "4")
		return "Print";
	else if (answer == "Exit" || answer == "exit" || answer == "5")
		return "Exit";
	else
	{
		cout << "Please type the supported words or number! \n";
		answer = menu();
	}

	return answer;
}

int main()
{
	//initializing local variables
	UserList list;
	string firstName = "";
	string lastName = "";
	string handle = "";
	string answer = "";
	unsigned long long int phoneNum = 0;
	int messageCount = 0;
	int totalMessageCount = 0;
	bool exit = false;

	cout << "Welcome to the user list! \n";
	while (exit != true)
	{
		// menu function
		cout << "What would you like to do? \n";
		answer = menu();
		if (answer == "Insert")
		{
			// info function
			cout << "begining of insert \n";
			getInfo(firstName, lastName, handle, phoneNum, messageCount);
			list.addNode(firstName, lastName, handle, phoneNum, messageCount);
			cout << "end of insert \n";
		}
		else if (answer == "Update")
		{
			cout << "What is the users handle? ";
			cin >> handle;
			list.updateMsg(handle);
		}
		else if (answer == "Find")
			list.findNode();
		else if (answer == "Print")
		{
			list.printList();
		}
		else
		{
			cout << "GoodBye! \n";
			exit = true;
		}
	}
	

	return 0;
}