#include "Stack.h"

int main()
{
    Stack stack; 
    int a, b, c, d, e, f;
    
    a = 3;
    b = 1;
    c = 4;
    d = 1;
    e = 5;
    f = 9;
    
    stack.Push(a);
    stack.Print();
    stack.Push(b);
    stack.Print();
    stack.Push(c);
    stack.Print();
    stack.Push(d);
    stack.Print();
    stack.Push(e);
    stack.Print();
    stack.Push(f);
    stack.Print();
    
    int top = 0;
    stack.Top(top);
    cout << "Top = " << top << endl;
    
    
    cout << "Popping stuff now " << endl;
    stack.Pop(f);
    stack.Print();
    stack.Pop(e);
    stack.Print();
    stack.Pop(d);
    stack.Print();
    stack.Pop(c);
    stack.Print();
    stack.Pop(b);
    stack.Print();
    stack.Pop(a);
    stack.Print();
    
    return 0;
}