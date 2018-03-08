//
//  OrderQueue.cpp
//  Nozamas
//
//  Created by Xiaofei Guo on 2/24/17.
//  Copyright © 2017 Xiaofei Guo. All rights reserved.
//


#include <iostream>
#include <stdexcept>
#include "Orderqueue.h"
using namespace std;
/*
 *constructor
 *initiate the number of the queue and capacity of the queue
 */
Orderqueue::Orderqueue()
{
   alist = new Order[INIT_CAPACITY];
   capacity = INIT_CAPACITY;
   number = 0;
}

/*
 *constructor
 *initiate the number of the queue and capacity of the queue
 */
Orderqueue::Orderqueue(Order *newarray, int length)
{
   alist = new Order[length];
   capacity = length;
   number = length;
   for(int i= 0; i<number;i++)
     { 
        alist[i] = newarray[i];
        // alist[i].a_t = newarray[i].a_t;
        // alist[i].f_d = newarray[i].f_d;
        // alist[i].p_d = newarray[i].p_d;
     }
}

/*
 *destructor
 */
Orderqueue::~Orderqueue()
{
   if (alist != NULL) 
    delete [] alist;
}

/*
 *copy constructor
 *paramiter: an Orderqueue
 *return: an Orderqueue
 */
Orderqueue::Orderqueue(const Orderqueue &source)
{
    number = source.number;
    capacity = source.number;
    alist = new Order[capacity];
    for(int i = 0; i< number; i++)
    {
        alist [i] = source.alist[i];
    }
    
}

/*
 *equal function
 *paramiter: an Orderqueue
 *return: an Orderqueue
 */
Orderqueue &Orderqueue::operator=(const Orderqueue &source)
{
    if (this == &source)
        return *this;
    else
    {
        capacity = source.capacity;
        number = source.number;
        for (int i = 0;i<number;i++)
        {
            alist[i] = source.alist[i];
        }
        return *this;
    }
}


/*
 *print function
 *paramiter: none
 *return: void
 *to print the whole queue. especially useful for debugging
 */
void Orderqueue::print()
{ 
   if (alist != NULL | number != 0)
     { 
       for(int i = 0; i< number; i++){
         cout << "Order " << alist[i].id<< " arrival_timestamp = "<<alist[i].a_t <<endl;
         cout <<" fetch_duration = "<<alist[i].f_d<<" pack_duration = "<<alist[i].p_d<<" minutes"<<endl;
}
     }
   else
      {
	throw runtime_error("empty_stack");
       }
}

/*
 *isEmpty
 *paramiter: none
 *return: bool
 *check if the queue is empty
 */
bool Orderqueue::isEmpty()
{
   if (alist == NULL |number == 0)
    { 
       return 1;
    }
   else
    {
       return 0;
    }
}

/*
 *size
 *paramiter: none
 *return: int
 *check how many elements are in the queue
 */
int Orderqueue::size()
{
   return number;
}

/*
 *enqueue
 *paramiter: Order
 *return: Order array
 */
Order *Orderqueue::enqueue(Order element)
{
  if (number == capacity)
    {
      expand();
    }
  
      alist[number] = element;
      number++;
      return alist;
}

/*
 *dequeue
 *paramiter: Order
 *return: Order array
 */
Order *Orderqueue::dequeue()
{
  if (number == 0 |alist==NULL)
    {
      throw runtime_error("empty_stack");
    }
  else
    { 
        alist[number].id = NULL;
        alist[number].a_t = NULL;
        alist[number].f_d = NULL;
        alist[number].p_d = NULL;
        number--;
        return alist;
    } 
}

/*
 *getFirstElem
 *paramiter: none
 *return: Order 
 *return the first element in the queue
 */
Order Orderqueue::getFirstElem()
{
   if (number == 0 |alist== NULL)
    {
      throw runtime_error("empty_stack");
    }
   else
    {
      return alist[number];
    }
}

/*
 *getElem
 *paramiter:int num
 *return: Order
 *return the specific element in the queue
 */
Order Orderqueue::getElem(int num)
{
    if (number == 0 |alist== NULL)
    {
        throw runtime_error("empty_stack");
    }
    else
    {
        return alist[num];
    }
}


/*
 *expand
 *paramiter: none
 *return: void
 *expand the queue's capacity
 */
void Orderqueue::expand()
{
    if(alist == NULL)
    {
        capacity = 5;
        alist = new Order[capacity];
    }
    else
    {
        capacity = 2*capacity;
        Order *temp =new Order[capacity];
        for(int i=0; i<number; i++)
        {
            temp[i] = alist[i];
        }
        delete [] alist;
        alist = temp;
    }
}
