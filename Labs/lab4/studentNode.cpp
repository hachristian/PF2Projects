//----------------------------------------------
// Purpose: Demonstrate studentNode ADT
// Author:  John Gauch
//----------------------------------------------

#include "studentNode.h"

//----------------------------------------------
StudentNode::StudentNode()
{
   Name = "";
   Address = "";
   GPA = 0;
   Next = NULL;
}

//----------------------------------------------
StudentNode::StudentNode(string name, string address, float gpa)
{
   Name = name;
   Address = address;
   GPA = gpa;
   Next = NULL;
}

//----------------------------------------------
StudentNode::StudentNode(const StudentNode & studentNode)
{
   Name = studentNode.Name;
   Address = studentNode.Address;
   GPA = studentNode.GPA;
   Next = studentNode.Next;
}

//----------------------------------------------
StudentNode::~StudentNode()
{
}

//----------------------------------------------
string StudentNode::getName() const
{
   return Name;
}

//----------------------------------------------
string StudentNode::getAddress() const
{
   return Address;
}

//----------------------------------------------
float StudentNode::getGPA() const
{
   return GPA;
}

//----------------------------------------------
void StudentNode::setName(string name)
{
   Name = name;
}

//----------------------------------------------
void StudentNode::setAddress(string address)
{
   Address = address;
}

//----------------------------------------------
void StudentNode::setGPA(float gpa)
{
   GPA = gpa;
}

void StudentNode::setNext(StudentNode * next)
{
    Next = next;
}

StudentNode StudentNode::getNext()
{
    return *Next;
}

//----------------------------------------------
void StudentNode::print() const
{
    
   cout << "Name: " << Name << "\n"
      << "Address: " << Address << "\n" << "GPA: " << GPA << "\n";
     if (Next != NULL)
      Next->print();
}
