#include "IntList.h"
#include <iostream>

using namespace std;

IntList::IntList()
{
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList()
{
    clear();
}


void IntList::push_front(int value)
{
    IntNode* newNode = new IntNode(value);
    if (empty())
    {
        //newNode->next = nullptr;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
    }
    head = newNode;
    /*
    newNode->next = head;
    head = newNode;
    if (tail == nullptr)
    {
        tail = newNode
    }*/
}

bool IntList::empty() const
{
    if (head == nullptr /*&& tail == nullptr*/)
    {
        return true;
    }
    return false;
}

const int & IntList::front() const
{
    /*if (empty())
    {
        return nullptr;
    }*/
    
    return head->value;
}

const int & IntList::back() const
{
    return tail->value;
}

void IntList::pop_front()
{
    if (!empty())
    {
        //for list w/ 1 element
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            IntNode* temp = head->next; 
            delete head;
            head = temp;
        }
    }
}
void IntList::clear()
{
    if (!empty())
    {
        //IntNode* current = head;
        while (head) {
            
            pop_front();
            
        }
    }

    head = nullptr;
    tail = nullptr;
    
}

ostream & operator<<(ostream &out, const IntList &List)
{
    IntNode* temp = List.head;
    while (temp)
    {
        if (temp->next == nullptr)
        {
            out << temp->value;
        }
        else
        {
            out << temp->value << " ";
        }
        temp = temp->next;
    }

    return out;
}

// program 6 functions

IntList::IntList(const IntList& original)
{
    //IntNode* copyHead;
    //IntNode* copyTail;
    //IntNode* curr = head;
    head = nullptr;
    tail = nullptr;
    
    for(IntNode* curr = original.head; curr != nullptr; curr = curr->next)
    {
        push_back(curr->value);
    }
     
}

IntList & IntList::operator=(const IntList &rhs)
{
    if (this != &rhs)
    {
        if (rhs.empty())
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            clear();
            for(IntNode* curr = rhs.head; curr != nullptr; curr = curr->next)
            {
                push_back(curr->value);
            }
        }

    }
    return *this;
}

void IntList::push_back(int value)
{
    IntNode* newNode = new IntNode(value);
    if(empty())
    {
        head = newNode;
        tail = newNode;
        
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    //newNode->next = nullptr;
}

void IntList::selection_sort()
{
    if (empty())
    {}
    else
    {
        for(IntNode* curr = head; curr != nullptr; curr = curr->next)
        {
            IntNode* min = curr;
            for(IntNode* currN = curr->next; currN != nullptr; currN = currN->next)
            {
                if (currN->value < min->value)
                {
                    min = currN;
                }
            }

            int temp = curr->value;
            curr->value = min->value;
            min->value = temp;
        }
    }
}

void IntList::insert_ordered(int value)
{
    if(empty())
    {
        push_front(value);
    }
    else if(tail->value <= value)
    {
        push_back(value);
    }
    else if(head->value >= value)
    {
        push_front(value);
    }
    else
    {
        IntNode* previous = head;
        IntNode* currNext = head->next;
        // if the value is is not in the middle of prev and next, move on
        for(IntNode* curr = head; !((previous->value <= value) && (value <= currNext->value)); curr = curr->next)
        {
            previous = curr->next;
            currNext = curr ->next->next;
        }
        IntNode* newNode = new IntNode(value);
        newNode->next = currNext;
        previous->next = newNode;
    }
}

void IntList::remove_duplicates()
{
    if (!empty())
    {
        for (IntNode* i = head; i != nullptr; i = i->next)
        {
            IntNode* prev = i;
            for (IntNode* current = i->next; current != nullptr; current = prev->next)
            {
                if (current->value == i->value && current->next != nullptr)
                {
                    //general case
                    prev->next = current->next;

                    delete current;
                    //current = prev->next;
                
                }
                // last node
                else if (current->value == i->value && current->next == nullptr)
                {
                    prev->next = nullptr;
                    delete tail;
                    tail = prev;
                    //current = prev->next;
                }
                //if no match at current node
                else
                {
                    prev = prev->next;
                    //current = prev->next;
                      
                }

            }
        }
    }   
}


IntNode * IntList::min(IntNode *n)
{
    return n;
}

void IntList::copy(const IntList &)
{
    cout << "void";
}