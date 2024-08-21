#ifndef __SORTEDSET_H__
#define __SORTEDSET_H__

using namespace std;

#include "IntList.h"

class SortedSet : public IntList
{

    public:
        SortedSet();
        SortedSet(const SortedSet &newSet);
        SortedSet(const IntList &newSet);
        ~SortedSet();

        bool in(int value) const;
        SortedSet operator|(SortedSet &);
        SortedSet operator&(SortedSet &);

        void add(int value);
        void push_front(int value);
        void push_back(int value);
        void insert_ordered(int value);
        const SortedSet operator|=(const SortedSet &);
        const SortedSet operator&=(const SortedSet &);

};

#endif