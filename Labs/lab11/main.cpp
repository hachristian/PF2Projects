#include <iostream>
using namespace std;

int compare_counter = 0;
int move_counter = 0;

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

//----------------------------------------------------------------
// Insertion sort algorithm
//----------------------------------------------------------------
void insertion_sort(int data[], int low, int high)
{
   // Insert each element of unsorted list into sorted list
   for (int unsorted = low+1; unsorted <= high; unsorted++)
   {
      // Select unsorted value to be inserted
      int value = data[unsorted];
      int posn = unsorted;

      // Make room for new data value
      while ((posn > 0) && (data[posn - 1] > value))
      {
         compare_counter++;
	      data[posn] = data[posn - 1];
         move_counter++;
	      posn--;
      }

      // Put new value into array
      data[posn] = value;
      move_counter++;;
   }
}

//----------------------------------------------------------------
// Partition function used by Quicksort.
//----------------------------------------------------------------
void partition(int data[], int low, int high, int &mid)
{
   // Select pivot value
   int pivot = data[high];
   int left = low;
   int right = high;

   // Partition array into two parts
   while (left < right)
   {
      // Scan left to right
      while ((left < right) && (data[left] < pivot)) 
      {
         compare_counter++;
         left++;
      }
      // Scan right to left
      while ((left < right) && (data[right] >= pivot)) 
      {
         compare_counter++;
         right--;
      }
      // Swap data values
      int temp = data[left];
      data[left] = data[right];
      move_counter++;
      data[right] = temp;
      move_counter++;
   }

   // Swap pivot to mid
   mid = left;
   data[high] = data[mid];
   move_counter++;
   data[mid] = pivot;
   move_counter++;
}

//----------------------------------------------------------------
// Recursive Quicksort algorithm using basic partition function.
//----------------------------------------------------------------
void quick_sort(int data[], int low, int high)
{
   if (high <= 10)
   {
      insertion_sort(data, low, high);
   }
   else
   {
      // Check terminating condition
      if (low < high)
      {
         // Partition data into two parts
         int mid = 0;
         partition(data, low, high, mid);

         // Recursive calls to sort array
         quick_sort(data, low, mid - 1);
         quick_sort(data, mid + 1, high);
      }
   }
}

//----------------------------------------------------------------
// Mergesort using secondary storage for data merging.
//----------------------------------------------------------------
void merge_sort(int data[], int low, int high)
{
   // Check terminating condition
   int range = high - low + 1;
   if (range > 1)
   {
      // Divide the array and sort both halves
      int mid = (low + high) / 2;
      merge_sort(data, low, mid);
      merge_sort(data, mid + 1, high);

      // Create temporary array for merged data
      int *copy = new int[range];

      // Initialize array indices
      int index1 = low;
      int index2 = mid + 1;
      int index = 0;

      // Merge smallest data elements into copy array
      while (index1 <= mid && index2 <= high)
      {
	       if (data[index1] < data[index2])
          {
            compare_counter++;
	         copy[index++] = data[index1++];
            move_counter++;
          }
	       else
          {
            compare_counter++;
	         copy[index++] = data[index2++];
            move_counter++;
          }
      }

      // Copy any remaining entries from the first half
      while (index1 <= mid)
      { 
	      copy[index++] = data[index1++];
         move_counter++;
      }

      // Copy any remaining entries from the second half
      while (index2 <= high)
      {
	      copy[index++] = data[index2++];
         move_counter++;
      }
      // Copy data back from the temporary array
      for (index = 0; index < range; index++)
      {
	      data[low + index] = copy[index];
         move_counter++;
      }
      delete []copy;
   }
}

int main()
{
 
   int array[1000];

   create_random_data(array, 10, 10);
   insertion_sort(array, 0, 10);

   cout << "The following is with random data!\n";

   cout << "insertion sort n = 10\n";
   cout << "compare counter = " << compare_counter << endl;
   cout << "move counter = " << move_counter << endl;
   
   compare_counter = 0;
   move_counter = 0;
   
   create_random_data(array, 100, 100);
   insertion_sort(array, 0, 100);

   cout << "insertion sort n = 100\n";
   cout << "compare counter = " << compare_counter << endl;
   cout << "move counter = " << move_counter << endl;

   compare_counter = 0;
   move_counter = 0;
   
   create_random_data(array, 1000, 1000);
   insertion_sort(array, 0, 1000);

   cout << "insertion sort n = 1000\n";
   cout << "compare counter = " << compare_counter << endl;
   cout << "move counter = " << move_counter << endl << endl;
   
   cout << "The following is with mostly sorted data!\n";

   compare_counter = 0;
   move_counter = 0;
   
   create_mostly_sorted_data(array, 10, 1);
   insertion_sort(array, 0, 10);

   cout << "insertion sort n = 10\n";
   cout << "compare counter = " << compare_counter << endl;
   cout << "move counter = " << move_counter << endl;

   compare_counter = 0;
   move_counter = 0;
   
   create_mostly_sorted_data(array, 100, 10);
   insertion_sort(array, 0, 100);

   cout << "insertion sort n = 100\n";
   cout << "compare counter = " << compare_counter << endl;
   cout << "move counter = " << move_counter << endl;

   compare_counter = 0;
   move_counter = 0;
   
   create_mostly_sorted_data(array, 1000, 100);
   insertion_sort(array, 0, 1000);

   cout << "insertion sort n = 1000\n";
   cout << "compare counter = " << compare_counter << endl;
   cout << "move counter = " << move_counter << endl << endl;
   
   cout << "The following is with sorted data!\n";
   for (int i = 0; i < 1000; i++)
      array[i] = i;

   compare_counter = 0;
   move_counter = 0;
   
   insertion_sort(array, 0, 10);

   cout << "insertion sort n = 10\n";
   cout << "compare counter = " << compare_counter << endl;
   cout << "move counter = " << move_counter << endl;

   compare_counter = 0;
   move_counter = 0;
   
   insertion_sort(array, 0, 100);

   cout << "insertion sort n = 100\n";
   cout << "compare counter = " << compare_counter << endl;
   cout << "move counter = " << move_counter << endl;

   compare_counter = 0;
   move_counter = 0;
   
   insertion_sort(array, 0, 1000);

   cout << "insertion sort n = 1000\n";
   cout << "compare counter = " << compare_counter << endl;
   cout << "move counter = " << move_counter << endl;

   // starting merge sort.

   compare_counter = 0;
   move_counter = 0;

   create_random_data(array, 10, 10);
   merge_sort(array, 0, 10);

   cout << "The following is with random data!\n";

   cout << "merge sort n = 10\n";
   cout << "compare counter = " << compare_counter << endl;
   cout << "move counter = " << move_counter << endl;
   
   compare_counter = 0;
   move_counter = 0;
   
   create_random_data(array, 100, 100);
   merge_sort(array, 0, 100);

   cout << "merge sort n = 100\n";
   cout << "compare counter = " << compare_counter << endl;
   cout << "move counter = " << move_counter << endl;

   compare_counter = 0;
   move_counter = 0;
   
   create_random_data(array, 1000, 1000);
   merge_sort(array, 0, 1000);

   cout << "merge sort n = 1000\n";
   cout << "compare counter = " << compare_counter << endl;
   cout << "move counter = " << move_counter << endl << endl;
   
   cout << "The following is with mostly sorted data!\n";

   compare_counter = 0;
   move_counter = 0;
   
   create_mostly_sorted_data(array, 10, 1);
   merge_sort(array, 0, 10);

   cout << "merge sort n = 10\n";
   cout << "compare counter = " << compare_counter << endl;
   cout << "move counter = " << move_counter << endl;

   compare_counter = 0;
   move_counter = 0;
   
   create_mostly_sorted_data(array, 100, 10);
   merge_sort(array, 0, 100);

   cout << "merge sort n = 100\n";
   cout << "compare counter = " << compare_counter << endl;
   cout << "move counter = " << move_counter << endl;

   compare_counter = 0;
   move_counter = 0;
   
   create_mostly_sorted_data(array, 1000, 100);
   merge_sort(array, 0, 1000);

   cout << "merge sort n = 1000\n";
   cout << "compare counter = " << compare_counter << endl;
   cout << "move counter = " << move_counter << endl << endl;
   
   cout << "The following is with sorted data!\n";
   for (int i = 0; i < 1000; i++)
      array[i] = i;

   compare_counter = 0;
   move_counter = 0;
   
   merge_sort(array, 0, 10);

   cout << "merge sort n = 10\n";
   cout << "compare counter = " << compare_counter << endl;
   cout << "move counter = " << move_counter << endl;

   compare_counter = 0;
   move_counter = 0;
   
   merge_sort(array, 0, 100);

   cout << "merge sort n = 100\n";
   cout << "compare counter = " << compare_counter << endl;
   cout << "move counter = " << move_counter << endl;

   compare_counter = 0;
   move_counter = 0;
   
   merge_sort(array, 0, 1000);

   cout << "merge sort n = 1000\n";
   cout << "compare counter = " << compare_counter << endl;
   cout << "move counter = " << move_counter << endl << endl;

   // starting quick sort.

   compare_counter = 0;
   move_counter = 0;

   create_random_data(array, 10, 10);
   quick_sort(array, 0, 10);

   cout << "The following is with random data!\n";

   cout << "quick sort n = 10\n";
   cout << "compare counter = " << compare_counter << endl;
   cout << "move counter = " << move_counter << endl;
   
   compare_counter = 0;
   move_counter = 0;
   
   create_random_data(array, 100, 100);
   quick_sort(array, 0, 100);

   cout << "quick sort n = 100\n";
   cout << "compare counter = " << compare_counter << endl;
   cout << "move counter = " << move_counter << endl;

   compare_counter = 0;
   move_counter = 0;
   
   create_random_data(array, 1000, 1000);
   quick_sort(array, 0, 1000);

   cout << "quick sort n = 1000\n";
   cout << "compare counter = " << compare_counter << endl;
   cout << "move counter = " << move_counter << endl << endl;
   
   cout << "The following is with mostly sorted data!\n";

   compare_counter = 0;
   move_counter = 0;
   
   create_mostly_sorted_data(array, 10, 1);
   quick_sort(array, 0, 10);

   cout << "quick sort n = 10\n";
   cout << "compare counter = " << compare_counter << endl;
   cout << "move counter = " << move_counter << endl;

   compare_counter = 0;
   move_counter = 0;
   
   create_mostly_sorted_data(array, 100, 10);
   quick_sort(array, 0, 100);

   cout << "quick sort n = 100\n";
   cout << "compare counter = " << compare_counter << endl;
   cout << "move counter = " << move_counter << endl;

   compare_counter = 0;
   move_counter = 0;
   
   create_mostly_sorted_data(array, 1000, 100);
   quick_sort(array, 0, 1000);

   cout << "quick sort n = 1000\n";
   cout << "compare counter = " << compare_counter << endl;
   cout << "move counter = " << move_counter << endl << endl;
   
   cout << "The following is with sorted data!\n";
   for (int i = 0; i < 1000; i++)
      array[i] = i;

   compare_counter = 0;
   move_counter = 0;
   
   quick_sort(array, 0, 10);

   cout << "quck sort n = 10\n";
   cout << "compare counter = " << compare_counter << endl;
   cout << "move counter = " << move_counter << endl;

   compare_counter = 0;
   move_counter = 0;
   
   quick_sort(array, 0, 100);

   cout << "quick sort n = 100\n";
   cout << "compare counter = " << compare_counter << endl;
   cout << "move counter = " << move_counter << endl;

   compare_counter = 0;
   move_counter = 0;
   
   quick_sort(array, 0, 1000);

   cout << "quick sort n = 1000\n";
   cout << "compare counter = " << compare_counter << endl;
   cout << "move counter = " << move_counter << endl;

   return 0;
}