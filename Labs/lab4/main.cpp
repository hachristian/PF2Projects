//----------------------------------------------
// Purpose: Demonstrate student ADT
// Author:  John Gauch
//----------------------------------------------

#include "studentNode.h"

//----------------------------------------------
int main()
{
   StudentNode *ptr1 = new StudentNode("John", "Johnson, AR", 2.5);
   StudentNode *ptr2 = new StudentNode("Fred", "Fayetteville, AR", 3.5);
   StudentNode *ptr3 = new StudentNode("Sam", "Springdale, AR", 2.9);
   StudentNode *ptr4 = new StudentNode("Christian", "Dale, AR", 4.0);
   StudentNode *ptr5 = new StudentNode("Joe", "Arkansas, AR", 2.3);
   
   ptr3->setNext(ptr1);
   ptr1->setNext(ptr4);
   ptr4->setNext(ptr2);
   ptr2->setNext(ptr5);
   ptr3->print();
   
   
   string name;
   string address;
   float gpa;
   StudentNode *head = NULL;
   StudentNode *temp = NULL;
   StudentNode *other = NULL;
   for (int i=0; i<5; i++)
   {
      cout << "Enter name: ";
      cin >> name;
      cout << "Enter address: ";
      cin >> address;
      cout << "Enter GPA: ";
      cin >> gpa;
      other = new StudentNode(name, address, gpa);
      
      if(head == NULL)
      {
          head = other;
      }
      else
      {
          temp->setNext(other);
      }
      temp = other;
   }
   head->print();

   return 0;
}