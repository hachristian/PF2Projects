\
#ifndef NUMBERS_H
#define NUMBERS_H

//----------------------------------------------
// Purpose: Numbers class with basic operations
// Author:  John Gauch
//----------------------------------------------

#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;

template <class DataType>
class Numbers
{
 public:
   // Constructors
   Numbers();
   ~Numbers();

   // Methods
   void readFile(string filename);
   int getCount();
   DataType  getValue(int index);
   DataType findMin();
   DataType findMax();
   DataType findMean();
   DataType findVariance();
   DataType findStandardDeviation();

 private:
   static const int SIZE = 100;
   int Count;
   DataType Data[SIZE];
};

#endif 

