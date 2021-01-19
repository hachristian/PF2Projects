/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   student.cpp
 * Author: jcsibria
 * 
 * Created on January 16, 2020, 4:15 PM
 */

#include "student.h"

student::student() 
{
    cout << "In constructor\n";
}

student::student(const student& orig) 
{
    cout << "In copy constructor\n";
}

student::~student() 
{
    cout << "In destructor\n";
}

