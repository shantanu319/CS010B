//include any standard libraries needed
#include <fstream>
#include <iostream>

using namespace std;


//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize);

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index);


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize);


const int ARR_CAP = 100;

int main(int argc, char *argv[]) {
   
   // verify file name provided on command line
   if (argc != 2)
   {
      cout << "File not provided";
      exit(1);
   }


   // open file and verify it opened
   string fileName = argv[1];
   ifstream inFS;
   inFS.open(fileName);

   if (!inFS.is_open())
   {
      cout << "Error opening " << fileName << endl;
      exit(1);
   }

   // Declare an array of doubles of size ARR_CAP.
   double arr[ARR_CAP];
    
   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.
   int size = 0;
   double temp = 0.0;
   while (inFS >> temp && size < ARR_CAP)
   {
      arr[size] = temp;
      size++;
   }
    
   // Call the mean function passing it this array and output the 
   // value returned.
   cout << "Mean: " << mean(arr, size) << endl; 
   // Ask the user for the index (0 to size - 1) of the value they want to remove.
   int index = 0;
   cout << "Enter index of value to be removed (0 to " << size - 1 << "): ";
   cin >> index;
	cout << endl;
   // Call the display function to output the array.
   cout << "Before removing value: ";
   display(arr, size);
   cout << endl;
   
   // Call the remove function to remove the value at the index
   // provided by the user.
   remove(arr, size, index);
    
   // Call the display function again to output the array
   // with the value removed.
   cout << "After removing value: ";
   display(arr, size);
   cout << endl;
   
   // Call the mean function again to get the new mean
   cout << "Mean: " << mean(arr, size) << endl;
   
	return 0;
}

double mean(const double array[], int arraySize)
{
   double average = 0.0;
   int i = 0;
   for (i = 0; i < arraySize; ++i)
   {
      average += array[i];
   }

   average = average / arraySize;

   return average;
}


void remove(double array[], int &arraySize, int index)
{
   if (index > (arraySize - 1) || index < 0)
   {

   }
   else
   {
      int i = 0;
      for (i = index; i < arraySize - 1; ++i)
      {
         array[i] = array[i + 1];
      }

      arraySize--;

   }
   
}


void display(const double array[], int arraySize)
{
   int i = 0;
   for (i = 0; i < arraySize - 1; ++i)
   {
      cout << array[i] << ", ";
   }
   cout << array[arraySize - 1];
}