#include "tree.h"
#include <fstream>

int main()
{
    BinaryTree Tree;
    ifstream din;

    string Name = "";
    unsigned long Count = 0;
    double Percentage = 0.0;
    int Rank = 0;

    din.open("last.txt");

    //getting information from a file and inserting it into the tree
    while (!din.fail())
    {
        din >> Name >> Count >> Percentage >> Rank;

        Tree.Insert(Name, Count, Percentage, Rank);
    }

    bool exit = false;
    bool found = false;
    string answer = "";

    while (!exit)
    {
        cout << "Please enter a last name to search or type \"Quit\"\n";
        cin >> answer;

        //making sure the first letter is capitalized.
        answer[0] = toupper(answer[0]);

        if (answer == "Quit" || answer == "QUIT")
        {
            exit = true;
        }
        else
        {
            found = Tree.Search(answer);
            if (found == false)
                cout << answer << " was not found\n";
        }
    }

    Tree.Print();

    return 0;
}