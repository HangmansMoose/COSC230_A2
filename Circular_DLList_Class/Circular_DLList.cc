#include "Circular_DLList.h"
#include <iostream>

int list_length;


Circular_DLList::~Circular_DLList() 
{ 
    DLLNode *p;
    
	for (int i = 0; i < list_length; i++ ) 
    {
		p = tail->next;
		delete [] tail;
		tail = p;
        std::cout << "deleting fuck you valgrind" << std::endl;
	}
}

bool Circular_DLList::is_empty()
{
    
     if(tail->next == tail)
     {
         return true;
     }
     else{
         return false;
     }
     
    
}

void Circular_DLList::add_to_tail(int input)
{ 
    
    DLLNode *new_node = new DLLNode();
    list_length++;
    new_node->info = input;
    //see if a tail already exists
    if(tail == NULL)
    {
        
        tail = new_node;
    }
    //see if the tail is the only node.
    else if (tail->prev == 0 || tail->next == 0)
    {
        
        new_node->prev = tail;
        new_node->next = tail;
        tail->prev = new_node;
        tail->next = new_node;
         
    }
    else
    {
        
        DLLNode *head = tail->next;   
        
        new_node->next = head;
        new_node->prev = tail;
        //now point the tail to the new node
        tail->next = new_node;
        head->prev = new_node;
    }
    //declare the new node and place it next to the tail
    
    
    
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