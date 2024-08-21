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
    if (empty())
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        for(IntNode* curr = original.head; curr != nullptr; curr = curr->next)
        {
            push_back(curr->value);
        }
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
    IntNode* newNode = new IntNode(value);
    if (empty() || value >= tail->value)
    {
        push_back(value);
    }
    else
    {
        IntNode* prev = nullptr;
        IntNode* next = head;
        //should return position of node right before newNode
        for(IntNode* curr = head; curr != nullptr; curr = curr->next)
        {
            if (value > curr->value)
            {
                prev = curr;
                next = curr->next;
            }

        }
        
        if (prev == nullptr)
        {
            push_front(value);
        }
        else
        {
            prev->next = newNode;
            newNode->next = next;
        }
        
    }
}

void IntList::remove_duplicates()
{
    if (empty())
    {
    }
    else
    {
        for(IntNode* curr = head; curr != nullptr; curr = curr->next)
        {
            IntNode* prev = curr;
            for(IntNode* currN = head->next; currN != nullptr; currN = prev->next)
            {
                if (curr->value == currN->value)
                {
                    if (currN->next == nullptr)
                    {
                        delete currN;
                        tail = prev;
                        tail->next = nullptr;
                    }
                    else
                    {
                        prev = currN->next;
                        delete currN;
                        currN = prev->next;
                    }
                }
                else
                {
                    prev = prev->next;  
                }
            }
        }
    }   
}