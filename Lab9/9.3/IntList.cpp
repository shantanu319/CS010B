#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

ostream & operator<<(ostream &out, IntNode *n)
{
   if (n == nullptr)
   {
      return out;
   }
   else
   {
      out << " ";
   }
   out << n->value;
   return operator<<(out, n->next);

}
ostream & operator<<(ostream &out, const IntList &arr)
{
   if (arr.head == nullptr)
   {
      return out;
   }
   out << arr.head->value;
   return operator<<(out, arr.head->next);
}

bool IntList::exists(int n) const
{
   return exists(head, n);
}

bool IntList::exists(IntNode *n, int val) const
{
   if (!n) 
   {
      return false;
   }

   if (n->value == val)
   {
      return true;
   }

   return exists(n->next, val);

}

