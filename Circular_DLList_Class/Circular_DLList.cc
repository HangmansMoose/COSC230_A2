#include "Circular_DLList.h"
#include <iostream>


Circular_DLList::~Circular_DLList() 
{ 
    
	for (DLLNode *p; !is_empty(); ) {
		p = tail->next;
		delete tail;
		tail = p;
	}
}

bool Circular_DLList::is_empty()
{
    bool result = false;
       DLLNode *p;
       for(p = tail->next; p->next != tail;p = p->next)
       {
           if(sizeof(p->info) == 0)
           {
               result = true;
               return result;
           }
           else
           {
               result = false;
           }
       }
    return result;
}

void Circular_DLList::add_to_tail(int input)
{ 
    //declare the new node and place it next to the tail
    DLLNode *new_node = new DLLNode(input, tail, tail->next);
    //now point the tail to the new node
    tail->next = new_node;
}

int Circular_DLList::delete_from_tail()
{
    DLLNode *new_tail = tail->prev;
    delete tail;
    tail = new_tail;

    return tail->info;

}

bool Circular_DLList::is_in_list(int search)
{
    bool result = false;
     DLLNode *p;
       for(p = tail->next; p->next != tail;p = p->next)
       {
           if (p->info == search)
           {
               result = true;
           }
       }
    
    return result;
}

void Circular_DLList::print_list()
{
    DLLNode *p;
       for(p = tail->next; p->next != tail;p = p->next)
       {
           std::cout << p->info << std::endl;
       }
}