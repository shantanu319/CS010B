#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
   
  string inputFile;
  string outputFile;

  if (argc == 0)
  {
   return 1;
  }

  // Assign to inputFile value of 2nd command line argument
  inputFile = argv[1];
  //inputFile = "data1.csv";
  // Assign to outputFile value of 3rd command line argument
  outputFile = argv[2];
  //outputFile = "data1o.csv";
  // Create input stream and open input csv file.
  ifstream inFS;
  inFS.open(inputFile);
  // Verify file opened correctly.
  // Output error message and return 1 if file stream did not open correctly.
  if (inFS.fail())
  {
   cout << "Error opening " << inputFile << endl;
   return 1;
  }
  // Read in integers from input file to vector.
  vector<int> nums;
  int element;
  string line;
  while (getline(inFS, line, ','))
  {
    element = stoi(line, nullptr, 10);
    nums.push_back(element);
  }
   
  // Close input stream.
  inFS.close();
  // Get integer average of all values read in.
  int average = 0;
  for (unsigned int i = 0; i < nums.size(); ++i)
  {
   average += nums.at(i);
  }
  average = (average / nums.size());
  
  // Convert each value within vector to be the difference between the original value and the average.
  for (unsigned int i = 0; i < nums.size(); ++i)
  {
   nums.at(i) = nums.at(i) - average;
  }
   
  // Create output stream and open/create output csv file.
  ofstream outFS;
  outFS.open(outputFile);

  // Verify file opened or was created correctly.
  // Output error message and return 1 if file stream did not open correctly.
  if (outFS.fail())
  {
   cout << "Error opening " << outputFile << endl;
   return 1;
  }
   
  // Write converted values into ouptut csv file, each integer separated by a comma.
  for (unsigned int i = 0; i < nums.size(); ++i)
  {
   outFS << nums[i];
   if (i < nums.size() - 1)
   {
    outFS << ",";
   }
  }

  // Close output stream.
  outFS.close();
  return 0;
}