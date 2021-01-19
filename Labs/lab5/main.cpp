//----------------------------------------------
// Purpose: Test student linked list 
// Author:  John Gauch
//----------------------------------------------

#include "StudentList.h"
#include <time.h>

//----------------------------------------------
int main()
{
   // Test the student list class
     // Get start time
   //clock_t time1=clock();
   StudentList list;
   
  
   list.insertHead("Chris", "Springdale, AR", 3.5);
   list.insertHead("Bob", "JohnsBorrow, AR", 2.5);
   list.insertHead("Leo", "Johnny, AR", 4.0);
   list.insertHead("Kathy", "Fort Smith, AR", 3.2);
   list.insertHead("Neo", "Neolithic , AR", 1.0);
   list.print();
   
   cout << "Looking for chris the last node in my list \n";
   list.searchName("Chris");
   
   cout << "Looking for a gpa >= 3.5 \n";
   list.searchGPA(3.5);
   
    //clock_t time2=clock();
   //double run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
  // cout << "Run time: " << run_time << " seconds\n";
}