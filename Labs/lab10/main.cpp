#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//------------------------------------------------------------------
// Initialize data array with random values
//------------------------------------------------------------------
void create_random_data(int data[], int count, int range)
{
   // Put specified count of random numbers into data array
   for (int index = 0; index < count; index++)
      data[index] = rand() % range;
}

//------------------------------------------------------------------
// Initialize data array with mostly sorted values
//------------------------------------------------------------------
void create_mostly_sorted_data(int data[], int count, int swaps)
{
   // Put sorted data values into array
   for (int index = 0; index < count; index++)
      data[index] = index;

   // Shuffle data by swapping random pairs of values
   for (int index = 0; index < swaps; index++)
   {
      int pos1 = rand() % count;
      int pos2 = rand() % count;
      int temp = data[pos1];
      data[pos1] = data[pos2];
      data[pos2] = temp;
   }
}

//------------------------------------------------------------------
// Write data array to output file
//------------------------------------------------------------------
void write_data(string name, int data[], int count)
{
   // Open output file
   ofstream dout;
   dout.open(name.c_str());
   if (dout.fail())
      cout << "Error: could not open output file\n";

   // Write the data
   dout << count;
   for (int i = 0; i < count; i++)
   {
      if (i % 20 == 0)
	 dout << endl;
      dout << data[i] << " ";
   }

   // Close the file
   dout.close();
}

//-----------------------------------------------------------------
// Bubble sort algorithm
//-----------------------------------------------------------------
void bubble_sort(int data[], int count)
{
   int pass = 1;
   int exchange = 1;

   // Bubble largest value to the right N times
   while ((pass < count) && (exchange > 0))
   {
      // Scan unsorted part of data array
      exchange = 0;
      for (int index = 0; index < (count - pass); index++)
      {
         // Swap two data values if out of order
	      if (data[index] > data[index + 1])
	      {
            int temp = data[index];
	         data[index] = data[index + 1];
	         data[index + 1] = temp;
	         exchange++;
	      }
      }
      pass++;
   }
}

//---------------------------------------------------------------
// Selection sort algorithm
//---------------------------------------------------------------
void selection_sort(int data[], int low, int high)
{
   // Put largest unsorted value at end of sorted list
   for (int last = high; last > low; last--)
   {
      // Find index of largest value in unsorted array
      int largest = low;
      for (int index = low + 1; index <= last; index++)
         if (data[index] > data[largest])
            largest = index;

      // Swap with last element in unsorted array
      int temp = data[last];
      data[last] = data[largest];
      data[largest] = temp;
   }
}

int main()
{
   int count = 25000;
   int range = 25000;
   int swaps = 2500;
   int low = 0;
   int high = range;
   int data[count];
   srand(time(NULL));

   create_random_data(data, count, range);
   write_data("random.txt", data, count);

   // Get start time
   clock_t time1=clock();

   bubble_sort(data, count);

   // Get end time
   clock_t time2=clock();
   double run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
   cout << "Bubble sort unsorted data.\n";
   cout << "Run time: " << run_time << " seconds\n";

   //starting the experiment again but with mostly sorted data
   create_random_data(data, count, range);
   write_data("random.txt", data, count);

   create_mostly_sorted_data(data, count, swaps);
   write_data("mostly_sorted.txt", data, count);

   // Get start time
   time1=clock();

   bubble_sort(data, count);

   // Get end time
   time2=clock();
   run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
   cout << "Bubble sort mostly sorted data.\n";
   cout << "Run time: " << run_time << " seconds\n";

   // starting experiment with sorted data.
   time1=clock();

   bubble_sort(data, count);

   // Get end time
   time2=clock();
   run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
   cout << "Bubble sort sorted data.\n";
   cout << "Run time: " << run_time << " seconds\n";

   // starting selection sort experiments.
   create_random_data(data, count, range);
   write_data("random.txt", data, count);

   time1=clock();

   selection_sort(data, low, high);

   // Get end time
   time2=clock();
   run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
   cout << "selection sort random data.\n";
   cout << "Run time: " << run_time << " seconds\n";

   // starting experiment with mostly sorted data
   create_random_data(data, count, range);
   write_data("random.txt", data, count);

   create_mostly_sorted_data(data, count, swaps);
   write_data("mostly_sorted.txt", data, count);

   time1=clock();

   selection_sort(data, low, high);

   // Get end time
   time2=clock();
   run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
   cout << "selection sort mostly sorted data.\n";
   cout << "Run time: " << run_time << " seconds\n";

   // starting experiment with sorted data
   time1=clock();

   selection_sort(data, low, high);

   // Get end time
   time2=clock();
   run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
   cout << "selection sort sorted data.\n";
   cout << "Run time: " << run_time << " seconds\n";

   return 0;
}
