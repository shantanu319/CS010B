#include <iostream>
#include "IntList.h"
#include "SortedSet.h"

using namespace std;

int main()
{
    // testing constructors and destructors
    
    IntList lhs;
    for (unsigned i = 0; i < 10; i++)
    {
        lhs.push_front(i + 3);
    }

    cout << lhs << endl;


    //lhs.selection_sort();
    //cout << lhs << endl;


    //lhs.remove_duplicates();
    //cout << lhs << endl;
    
    SortedSet empty = lhs;
    cout << empty << endl;

    //empty.clear();
    /*
    empty.push_back(20);
    empty.push_back(30);
    empty.push_back(52);
    empty.push_back(70);

    empty.add(30);
    empty.add(51);

    empty.push_front(30);
    empty.push_front(53);
    cout << empty << endl;*/    

    SortedSet empty2;
    for (int i = 9; i < 23; i++)
    {
        empty2.add(i);
    }

    cout << empty2 << endl;


    SortedSet empty3 = empty & empty2;
    cout << empty3 << endl;

    SortedSet empty4 = empty | empty2;
    cout << empty4;

    return 0;
}