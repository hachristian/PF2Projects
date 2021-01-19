/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StudentNode.h
 * Author: jcsibria
 *
 * Created on February 13, 2020, 3:48 PM
 */

#ifndef STUDENTNODE_H
#define STUDENTNODE_H

//-----------------------------------------------------------
//  Purpose:    Header file for the StudentNode class.
//  Author:     John Gauch
//-----------------------------------------------------------

#include <iostream>
using namespace std;

//-----------------------------------------------------------
// Define the StudentNode class interface 
//-----------------------------------------------------------
class StudentNode
{
 public:
   // Constructors 
   StudentNode();
   StudentNode(string name, string address, float gpa);
     StudentNode(const StudentNode & node);
    ~StudentNode();

   // Get methods
   string getName() const;
   string getAddress() const;
   float getGPA() const;
   StudentNode *getNext() const;

   // Set methods
   void setName(string name);
   void setAddress(string address);
   void setGPA(float gpa);
   void setNext(StudentNode * next);

   // Other methods
   void print() const;

 private:
   string Name;
   string Address;
   float GPA;
   StudentNode *Next;
};
#endif

