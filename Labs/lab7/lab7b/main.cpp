//----------------------------------------------
// Purpose: Demonstrate recursive grammars
// Author:  John Gauch
//----------------------------------------------
#include <iostream>
using namespace std;

//----------------------------------------------
string ParseInt(const string Input, const int pos)
{
   if ((pos < 0) || (pos >= Input.length()))
      return "";
   else if ((Input[pos] < '0') || (Input[pos] > '9'))
      return "";
   else
      return (Input[pos] + ParseInt(Input, pos+1));
}

//----------------------------------------------
string ParseFloat(const string Input, const int pos)
{
    string result = ParseInt(Input, pos);
    int index = result.length();
    
    if (Input[index] == '.')
        return (result + '.' + ParseInt(Input, index + 1));
    else 
        return "";
    
}

//----------------------------------------------
int main()
{
   string input = "123.111abc";
   cout << "Input = " << input << endl;
   cout << "ParseInt = " << ParseInt(input, 0) << endl;
   cout << "ParseFloat = " << ParseFloat(input, 0) << endl;
}