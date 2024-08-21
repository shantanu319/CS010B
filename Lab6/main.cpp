#include "IntVector.h"
#include <iostream>

using namespace std;

int main()
{
    unsigned int i = 0;

    //works
    // size works, capacity works
    IntVector test1 = IntVector(10, 5);
    cout << test1.size()<< endl;
    cout << test1.capacity() << endl;
    for (i = 0; i < test1.size(); ++i)
    {
        cout << test1.at(i) << endl;
    }
    
    
    // works
    IntVector test2 = IntVector();
    cout << test2.size()<< endl;
    cout << test2.capacity() << endl;
    for (i = 0; i < test2.size(); ++i)
    {
        cout << test2.at(i) << endl;
    }
    
    IntVector test3 = IntVector(223);
    cout << test3.size()<< endl;
    cout << test3.capacity() << endl;
    for (i = 0; i < test3.size(); ++i)
    {
        cout << test3.at(i) << endl;
    }



    //empty works
    cout << test2.empty() << endl;

    //cout << test2.at(0) << endl;
    cout << test1.at(3) << endl;


    return 0;
}