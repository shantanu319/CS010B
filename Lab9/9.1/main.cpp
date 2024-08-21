#include <iostream>
#include <string>

using namespace std;


void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

//Implement the flipString function here

void flipString(string &s)
{
   if (s.empty())
   {
      return;  
   }
   string exclFirst = s.substr(1);
   flipString(exclFirst);
   s = exclFirst + s.front();
}
