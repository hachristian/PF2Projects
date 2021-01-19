//----------------------------------------------
// Purpose: Numbers class with basic operations
// Author:  John Gauch
//----------------------------------------------

#include "numbers.cpp"

//----------------------------------------------
int main()
{
   string filename;
   cout << "Enter filename:";
   cin >> filename;

   // Process int numbers
   Numbers <int> num;
   num.readFile(filename);
   cout << "min = " << num.findMin() << endl;
   cout << "max = " << num.findMax() << endl;
   cout << "mean = " << num.findMean() << endl;

   // Process float numbers
   Numbers <float> num2;
   num2.readFile(filename);
   cout << "min = " << num2.findMin() << endl;
   cout << "max = " << num2.findMax() << endl;
   cout << "mean = " << num2.findMean() << endl;
   
   // Process short numbers
   Numbers <short> num3;
   num3.readFile(filename);
   cout << "min = " << num3.findMin() << endl;
   cout << "max = " << num3.findMax() << endl;
   cout << "mean = " << num3.findMean() << endl;
   
     // Process long numbers
   Numbers <long> num4;
   num4.readFile(filename);
   cout << "min = " << num4.findMin() << endl;
   cout << "max = " << num4.findMax() << endl;
   cout << "mean = " << num4.findMean() << endl;
   
      // Process float numbers
   Numbers <double> num5;
   num5.readFile(filename);
   cout << "min = " << num5.findMin() << endl;
   cout << "max = " << num5.findMax() << endl;
   cout << "mean = " << num5.findMean() << endl;
   
   // Process char numbers
   Numbers <char> num6;
   num6.readFile(filename);
   cout << "min = " << num6.findMin() << endl;
   cout << "max = " << num6.findMax() << endl;
   cout << "mean = " << num6.findMean() << endl;
   
  
   

   
   return 0;
}