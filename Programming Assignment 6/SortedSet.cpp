#include <iostream>
using namespace std;
#include "SortedSet.h"
#include "IntList.h"

SortedSet::SortedSet() : IntList()
{
    //IntList();
    //head = tail = nullptr;
}

SortedSet::SortedSet(const SortedSet &newSet) : IntList(newSet)
{
    //IntList(newset);
}

SortedSet::SortedSet(const IntList &newSet) : IntList(newSet)
{
    //SortedSet copy = IntList(newSet);
    remove_duplicates();
    selection_sort();
}

SortedSet::~SortedSet() 
{
    this->IntList::~IntList();
}


bool SortedSet::in(int value) const
{
    for (IntNode* curr = head; curr != nullptr; curr = curr->next)
    {
        if (curr->value == value)
        {
            return true;
        }
    }
    return false;
}

void SortedSet::add(int value)
{
    //IntNode* toAdd = new IntNode(value);
    SortedSet::insert_ordered(value);
}

void SortedSet::insert_ordered(int value)
{
    if (!in(value))
    {
        IntList::insert_ordered(value);
    }
}

void SortedSet::push_front(int value)
{
    add(value);
}

void SortedSet::push_back(int value)
{
    add(value);
}

SortedSet SortedSet::operator|(SortedSet &rhs) //realized that naming these lhs was wrong lol
{
    SortedSet _union;
    for (IntNode* curr = head; curr != nullptr; curr = curr->next)
    {
        _union.add(curr->value);
    }
    for (IntNode* curr = rhs.head; curr != nullptr; curr = curr->next)
    {
        _union.add(curr->value);
    }

    return _union;
}

SortedSet SortedSet::operator&(SortedSet &rhs)
{
    SortedSet _intersection;
    for (IntNode* curr = rhs.head; curr != nullptr; curr = curr->next)
    {
        if (in(curr->value))
        {
            _intersection.add(curr->value);
        }
    }

    return _intersection;
}


const SortedSet SortedSet::operator&=(const SortedSet &rhs)
{
    SortedSet _intersection;
    for (IntNode* curr = rhs.head; curr != nullptr; curr = curr->next)
    {
        if (in(curr->value))
        {
            _intersection.add(curr->value);
        }
    }

    *this = _intersection;
    return *this;
}
const SortedSet SortedSet::operator|=(const SortedSet &rhs)
{
    SortedSet _union;
    for (IntNode* curr = head; curr != nullptr; curr = curr->next)
    {
        _union.add(curr->value);
    }
    for (IntNode* curr = rhs.head; curr != nullptr; curr = curr->next)
    {
        _union.add(curr->value);
    }

    *this = _union;
    return *this;
}



