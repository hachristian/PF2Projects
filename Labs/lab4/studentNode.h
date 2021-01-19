/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   student.h
 * Author: jcsibria
 *
 * Created on February 6, 2020, 4:05 PM
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class StudentNode
{
 public:
   // Constructors 
   StudentNode();
   StudentNode(string name, string address, float gpa);
   StudentNode(const StudentNode & studentNode);
   ~StudentNode();

   // Methods
   string getName() const;
   string getAddress() const;
   float getGPA() const;
   void setName(string name);
   void setAddress(string address);
   void setGPA(float gpa);
   void print() const;
   void setNext(StudentNode *next);
   StudentNode getNext();
   

 private:
   string Name;
   string Address;
   float GPA;
   StudentNode *Next;
};


#endif /* STUDENT_H */

