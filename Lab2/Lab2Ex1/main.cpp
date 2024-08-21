#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
int fileSum(string fileName);

int main() {

   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   
   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;
   
   return 0;
}

// Place fileSum implementation here
int fileSum(string fileName)
{
   int sum = 0;
   ifstream fileFS;
   fileFS.open(fileName);

   if(!fileFS.is_open())
   {
      cout << "Error opening " << fileName << endl;
      exit(EXIT_FAILURE);
   }
   int num;
   while(fileFS >> num)
   {
      sum += num;
   }

   fileFS.close();

   return sum;

}