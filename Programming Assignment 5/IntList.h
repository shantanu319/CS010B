#ifndef __INTLIST_H__
#define __INTLIST_H__

#include <iostream>
using namespace std;

struct IntNode 
{
    int value;
    IntNode *next;
    IntNode(int value) : value(value), next(nullptr) {} 
};

class IntList
{
    IntNode* head;
    IntNode* tail;
    public:
        IntList();
        void push_front(int value);
        bool empty() const;
        const int & front() const;
        const int & back() const;
        void pop_front();
        void clear();
        ~IntList();
        friend ostream & operator<<(ostream &out, const IntList &List);

        // program 6 functions
        IntList(const IntList& original);
        IntList & operator=(const IntList &rhs);
        void push_back(int value);
        void selection_sort();
        void insert_ordered(int value);
        void remove_duplicates();

};
#endif