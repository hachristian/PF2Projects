/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StudentList.h
 * Author: jcsibria
 *
 * Created on February 13, 2020, 3:48 PM
 */

#ifndef STUDENTLIST_H
#define STUDENTLIST_H

//-----------------------------------------------------------
//  Purpose:    Header file for the StudentList class.
//  Author:     John Gauch
//-----------------------------------------------------------

#include "StudentNode.h"
#include <time.h>
#include <iostream>
using namespace std;

//-----------------------------------------------------------
// Define the StudentList class interface 
//-----------------------------------------------------------
class StudentList
{
 public:
   // Constructors 
   StudentList();
   StudentList(const StudentList & list);
    ~StudentList();

   // Methods
   void insertHead(string name, string address, float gpa);
   void insertTail(string name, string address, float gpa);
   StudentNode* searchName(string name);
   StudentNode* searchGPA(float gpa);
   void print() const;

 private:
     StudentNode * Head;
};

#endif /* STUDENTLIST_H */

