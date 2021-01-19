#include "Stack.h"
#include "Queue.h"
#include <time.h>

int main()
{
    string answer = "";
    int count = 0;
    int pushed = 0;
    int popped = 0;
    int inserted = 0;
    int removed = 0;
    int limit = 1000;
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
            //	Get	start	time
            clock_t time1 = clock();
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
                    pushed++;
                }
                else
                {
                    if (!stack.isEmpty())
                    {
                        temp = stack.pop();
                        cout << "Popped " << temp << endl;
                        popped++;
                        stack.print();
                    }
                }
            }
            //	Get	end	time
            clock_t time2 = clock();
            double run_time = (time2 - time1) / (double)CLOCKS_PER_SEC;
            cout << "Run time: " << run_time << " seconds\n";
            cout << "Pushed " << pushed << " times\n";
            cout << "Popped " << popped << " times\n";
            exit = true;
        }
        else if (answer == "Queue" || answer == "queue" || answer == "B" || answer == "b")
        {
            Queue queue;
            //	Get	start	time
            clock_t time1 = clock();
            int size = queue.getSize();
            string response = "";
            for (int i = 0; i < limit; i++)
            {
                int temp = rand() % 100;

                if (temp >= 49)
                {
                    if (!queue.isFull())
                    {
                        temp = rand() % 100;
                        queue.insert(temp);
                        cout << "Inserted " << temp << endl;
                        queue.print();
                        inserted++;
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
                        removed++;
                        queue.print();
                    }
                }
            }
            //	Get	end	time
            clock_t time2 = clock();
            double run_time = (time2 - time1) / (double)CLOCKS_PER_SEC;
            cout << "Run time: " << run_time << " seconds\n";
            cout << "Removed " << removed << " times\n";
            cout << "inserted " << inserted << " times\n";
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