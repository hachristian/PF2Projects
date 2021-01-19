
#include "Queue.h"


int main()
{
   int NumLines = 4;
   int NumCustomers = 27;
   int CurrentTime = 0;
   Queue *Vendor = new Queue[NumLines];

   // Add customers to different queues
   for (int Customer = 0; Customer < NumCustomers; Customer++)
   {
      // Generate customer data
      CurrentTime += 5 + rand() % 20;
      int NumItems = 1 + rand() % 5;

      //check if customer is done & leaving
      // loop through every line
      for (int Line = 0; Line < NumLines; Line++)
      {
         // generate random number 0 - 99
         int finished = rand() % 99;
         // if is 0-19, is "20%"
         if (finished <= 19) {
               Vendor[Line].Remove();
               cout << finished << ", done!" << endl;
         }
         else { cout << "not done .. " << endl;}
         Vendor[Line].Print();
      }
      cout << endl;

      // Search for shortest queue
      int ShortLine = 0;
      int ShortLength = Vendor[0].GetLength();
      for (int Line = 1; Line < NumLines; Line++)
      {
      int Length = Vendor[Line].GetLength();
      if (Length < ShortLength)
      {
         ShortLine = Line;
         ShortLength = Length;
      }
      }

      // Add customer to shortest line
      Vendor[ShortLine].Insert(NumItems);
      for (int Line = 0; Line < NumLines; Line++)
        {
            cout << "Line " << Line << " ";
            Vendor[Line].Print();
        }
        cout << endl;
   }

    cout << "*** finished adding customers, now finishing up queue ...!!! *** " << endl;

   // introduce a boolean "flag" var; false means line is NOT empty
   bool flag = false;
   // so while lines are not empty
   while (!flag) {
      // loop thru each line
      for (int Line = 0; Line < NumLines; Line++)
         {
            // check at beginning if line is empty, set flag to true
            if (Vendor[Line].IsEmpty()) {
               flag = true;
            }
            // only continues to remove ppl from line if NOT empty
            if (!flag) {
               int finished = rand() % 99;
               if (finished <= 19) {
                  Vendor[Line].Remove();
                  cout << finished << ", done!" << endl;
               }
               else { cout << "not done .. " << endl;}
               Vendor[Line].Print();
            }

            for (int Line = 0; Line < NumLines; Line++)
            {
               if (Vendor[Line].IsEmpty()) {
                  continue;
               }
               // RESET FLAG TO FALSE so while loop is re-entered!!! 
               // to continue emptying lines!
               flag = false;
            }
        }
   }

   // Print all customer lines
   for (int Line = 0; Line < NumLines; Line++)
   {
      cout << "Line " << Line << " ";
      Vendor[Line].Print();
   }
   



   return 0;
}

