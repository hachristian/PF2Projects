#include "Stack.h"
#include "Queue.h"
#include <time.h>

int main()
{
    string answer = "";
    int count = 0;
    int limit = 10;
    bool exit = false;

    cout << "Hello! Choose from the following.\n";
    cout << "(A) Stack\n(B) Queue\n(C) Exit\n";
    cin >> answer;

    //creating a random number seed
    srand(time(NULL));

    while (!exit)
    {
        if (answer == "Stack" || answer == "stack" || answer == "A" || answer == "a")
        {
            Stack stack;
            for (int i = 0; i < limit; i++)
            {
                int temp = rand() % 100;

                if (temp >= 49)
                {
                    temp = rand() % 100;
                    cout << "Pushing " << temp << endl;
                    stack.push(temp);
                    stack.print();
                    count++;
                }
                else
                {
                    if (!stack.isEmpty())
                    {
                        temp = stack.pop();
                        cout << "Popped " << temp << endl;
                        stack.print();
                    }
                }
            }
            exit = true;
        }
        else if (answer == "Queue" || answer == "queue" || answer == "B" || answer == "b")
        {
            Queue queue;
            int size = queue.getSize();
            string response = "";
            for (int i = 0; i < 1000000; i++)
            {
                int temp = rand() % 100;

                string answer = "";
                cin >> answer;
                if (answer == "1")
                {
                    if (!queue.isFull())
                    {
                        //temp = rand() % 100;
                        temp = count;
                        queue.insert(temp);
                        cout << "Inserted " << temp << endl;
                        queue.print();
                        count++;
                    }
                    else
                    {
                        size = queue.getSize();
                        cout << "The Queue is full!\n";
                        cout << "Your current size is " << size << endl;
                        cout << "Would you like to add space? (y/n) ";
                        cin >> response;
                        if (response == "Yes" || response == "yes" || response == "Y" || response == "y")
                        {
                            string temp = "";
                            cout << "How much would space would you like to add? ";
                            cin >> temp;
                            size = atoi(temp.c_str());
                            cout << "Finished atoi\n";
                            queue.setSize(size);
                            cout << "Added " << temp << " more spaces!\n";
                            queue.print();
                        }
                        else if (response == "No" || response == "no" || response == "N" || response == "n")
                        {
                            cout << "GoodBye!\n";
                            break;
                        }
                        else
                        {
                            cout << "Please enter yes or no\n";
                        }
                    }
                }
                else
                {
                    if (!queue.isEmpty())
                    {
                        temp = queue.remove();
                        cout << "Removed " << temp << endl;
                        queue.print();
                    }
                }
            }
            exit = true;
        }
        else if (answer == "Exit" || answer == "exit" || answer == "C" || answer == "c")
        {
            cout << "GoodBye!\n";
            exit = true;
        }
        else
        {
            cout << "Please enter a valid response! (A, B, or C)\n";
            cin >> answer;
        }
    }

    return 0;
}