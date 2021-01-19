#ifndef STACK_H
#define STACK_H

//-----------------------------------------------------------
//  Purpose:    Header file for the Stack class.
//  Author:     John Gauch
//-----------------------------------------------------------
#include <iostream>
using namespace std;

// Stack data node definition
class SNode
{
   public:
   int Number;
   SNode *Next;
};

class Stack
{
   public:
      // constructor functions
      Stack();
      ~Stack();

      // general stack operations
      void Push(int Number);
      void Pop(int &Number);
      void Top(int &Number);
      bool IsFull();
      bool IsEmpty();
      void Print();

   private:
      SNode *Head;
      int Length;
};



#endif /* STACK_H */

