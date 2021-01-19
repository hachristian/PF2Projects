//----------------------------------------------
// Purpose: Implement student linked list 
// Author:  John Gauch
//----------------------------------------------

#include "StudentList.h"

//----------------------------------------------
StudentList::StudentList()
{
   Head = NULL;
}

//----------------------------------------------
StudentList::StudentList(const StudentList & list)
{
   // Create first node
   StudentNode *copy = new StudentNode();
   Head = copy;

   // Walk list to copy nodes
   StudentNode *ptr = list.Head;
   while (ptr != NULL)
   {
      copy->setNext(new StudentNode());
      copy = copy->getNext();
      copy->setName(ptr->getName());
      copy->setAddress(ptr->getAddress());
      copy->setGPA(ptr->getGPA());
      copy->setNext(NULL);
      ptr = ptr->getNext();
   }

   // Tidy first node
   copy = Head;
   Head = copy->getNext();
   delete copy;
}

//----------------------------------------------
StudentList::~StudentList()
{
}

//----------------------------------------------
void StudentList::insertHead(string name, string address, float gpa)
{
   // Insert new node
   StudentNode *ptr = new StudentNode(name, address, gpa);
   ptr->setNext(Head);
   Head = ptr;
}

//----------------------------------------------
void StudentList::insertTail(string name, string address, float gpa)
{
   // Find tail node
   StudentNode *ptr = Head;
   while ((ptr != NULL) && (ptr->getNext() != NULL))
      ptr = ptr->getNext();

   // Insert new node
   if (ptr != NULL)
      ptr->setNext(new StudentNode(name, address, gpa));
   else
      Head = new StudentNode(name, address, gpa);

}

StudentNode* StudentList::searchName(string name)
{
    StudentNode* temp = Head;
    string foo = "";
   
    while ((temp != NULL))
    {
        foo = temp->getName();
        if (foo == name)
        {
            temp->print();
            return temp;
        }
        temp = temp->getNext();
    }

    
    cout << "Could not find that name! \n";
    
    return NULL;    
}

StudentNode* StudentList::searchGPA(float gpa)
{
    StudentNode* temp = Head;
    float foo = 0;
   
    while ((temp != NULL))
    {
        foo = temp->getGPA();
        if (foo >= gpa)
        {
            temp->print();
            return temp;
        }
        temp = temp->getNext();
    }
    foo = temp->getGPA();
    if (foo >= gpa)
    {
        temp->print();
        return temp;
    }
    
    cout << "Could not find that GPA! \n";
    
    return NULL;  
}

//----------------------------------------------
void StudentList::print() const
{
   StudentNode *ptr = Head;
   while (ptr != NULL)
   {
      ptr->print();
      ptr = ptr->getNext();
   }
}