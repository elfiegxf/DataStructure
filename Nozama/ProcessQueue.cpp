//
//  FetchQueue.cpp
//  Nozamas
//
//  Created by Xiaofei Guo on 2/24/17.
//  Copyright © 2017 Xiaofei Guo. All rights reserved.
//

#include "ProcessQueue.h"
#include <iostream>

using namespace std;

/*constructors*/
ProcessQueue::ProcessQueue()
{
    alist = new ProcessOrder[INIT_CAPACITY];
    capacity = INIT_CAPACITY;
    number = 0;
}


ProcessQueue::ProcessQueue(Orderqueue newqueue)
{
    capacity = newqueue.size();
    number = 0;
    alist = new ProcessOrder[capacity];
    Process(newqueue);
}


ProcessQueue::~ProcessQueue()
{
    if (alist != NULL)
        delete [] alist;
}

/*copy constructors*/
ProcessQueue::ProcessQueue(const ProcessQueue &source)
{
    number = source.number;
    capacity = source.number;
    alist = new ProcessOrder[capacity];
    for(int i = 0; i< number; i++)
    {
        alist [i] = source.alist[i];
    }
    
}


ProcessQueue &ProcessQueue::operator=(const ProcessQueue &source)
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
void ProcessQueue::print()
{
    if (alist != NULL | number != 0)
    {
        for(int i = 0; i< number; i++){
            cout << "Order " << alist[i].anOrder.id<< " arrival_timestamp = "<<alist[i].anOrder.a_t <<endl;
            cout <<" fetch_duration = "<<alist[i].anOrder.f_d<<" pack_duration = "<<alist[i].anOrder.p_d<<" fetching_timestamp = "<<alist[i].TimeStamp<<endl;
        }
    }
    else
    {
        throw runtime_error("empty_stack");
    }
}

/*processes the order,make it enqueue*/
int ProcessQueue::Process(Order element)
{
    
    if ( number >= capacity)
    {
        expand();
    }
    
    if (number == 0)
    {
        alist[number].anOrder = element;
        alist[number].TimeStamp =element.a_t + element.f_d ;
        number++;
        return alist[number].TimeStamp;
    }
    else
    {
        alist[number].anOrder = element;
        if (element.a_t<alist[number-1].TimeStamp)
        {
            alist[number].TimeStamp = alist[number-1].TimeStamp + element.f_d ;
            number++;
        }
        else //alist[number].anOrder.a_t>=alist[number-1].FetchTime
        {
            alist[number].TimeStamp = element.a_t + element.f_d ;
            number++;
        }
        return alist[number].TimeStamp;
    }
}


/*process the order queue at one time and return void*/
void ProcessQueue::Process(Orderqueue aQueue)
{
    int length = aQueue.size();
    
    if ( number >= capacity)
    {
        expand(number);
    }
    
    for( int i = 0; i < length; i++)
    {
        Process(aQueue.getElem(i));
    }
}

/*
 *enqueue
 *paramiter: Order
 *return: ProcessOrder array
 */
ProcessOrder *ProcessQueue::enqueue(Order element)
{
    if ( number >= capacity)
    {
        expand();
    }
    Process(element);
    return alist;
}

/*
 *dequeue
 *paramiter: Order
 *return: ProcessOrder array
 */
ProcessOrder *ProcessQueue::dequeue()
{
    if (number == 0 |alist==NULL)
    {
        throw runtime_error("empty_stack");
    }
    else
    {
        alist[number].anOrder.id = NULL;
        alist[number].anOrder.a_t = NULL;
        alist[number].anOrder.f_d = NULL;
        alist[number].anOrder.p_d = NULL;
        alist[number].TimeStamp = NULL;
        number--;
        return alist;
    }
}


/*
 *getlastElem
 *paramiter: none
 *return: Order
 *return the last element in the queue
 */
ProcessOrder ProcessQueue::getlastElem()
{
    if (number==0|alist==NULL)
    {
        throw runtime_error("empty_stack");
    }
    else
    {
        return alist[number-1];
    }
}

/*get the element at special place*/
ProcessOrder ProcessQueue::getElem(int num)
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
 *isEmpty
 *paramiter: none
 *return: bool
 *check if the queue is empty
 */
bool ProcessQueue::isEmpty()
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
int ProcessQueue::size()
{
    return number;
}


/*ProcessOrder overload operation*/
ProcessOrder &ProcessOrder::operator=(const ProcessOrder &source)
{
    if (this == &source)
        return *this;
    else
    {
        anOrder = source.anOrder;
        TimeStamp = source.TimeStamp;
        return *this;
    }
}


void ProcessQueue::expand()
{
    if(alist == NULL)
    {
        capacity = 5;
        alist = new ProcessOrder[capacity];
    }
    else
    {
        capacity = 2*capacity;
        ProcessOrder *temp =new ProcessOrder[capacity];
        for(int i=0; i<number; i++)
        {
            temp[i] = alist[i];
        }
        delete [] alist;
        alist = temp;
    }
}


void ProcessQueue::expand(int length)
{
    if(alist == NULL)
    {
        capacity = length;
        alist = new ProcessOrder[capacity];
    }
    else
    {
        capacity = length;
        ProcessOrder *temp =new ProcessOrder[capacity];
        for(int i=0; i<number; i++)
        {
            temp[i] = alist[i];
        }
        delete [] alist;
        alist = temp;
    }
}
