//
//  processtime.cpp
//  Nozamas
//
//  Created by Xiaofei Guo on 3/1/17.
//  Copyright © 2017 Xiaofei Guo. All rights reserved.
//


#include <iostream>
#include <stdexcept>
#include "processtime.h"
using namespace std;

/*constructor*/
processtime::processtime()
{
    alist = new int[INIT_CAPACITY];
    capacity = INIT_CAPACITY;
    number = 0;
}

/*destructor*/
processtime::~processtime()
{
    if (alist != NULL)
        delete [] alist;
}

/*copy constructor*/
processtime::processtime(const processtime &source)
{
    number = source.number;
    capacity = source.number;
    alist = new int[capacity];
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
processtime &processtime::operator=(const processtime &source)
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
void processtime::print()
{
    if (alist != NULL | number != 0)
    {
        for(int i = 0; i< number; i++){
            cout << "Order " << i << " time stamp = "<<alist[i] <<endl;
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
bool processtime::isEmpty()
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
int processtime::size()
{
    return number;
}


/*
 *enqueue
 *paramiter: Order
 *return: Order array
 */
int *processtime::enqueue(int element)
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
int *processtime::dequeue()
{
    if (number == 0 |alist==NULL)
    {
        throw runtime_error("empty_stack");
    }
    else
    {
        alist[number] = NULL;
        return alist;
    }
}

/*
 *getFirstElem
 *paramiter: none
 *return: Order
 *return the first element in the queue
 */
void processtime::expand()
{
    if(alist == NULL)
    {
        capacity = 5;
        alist = new int[capacity];
    }
    else
    {
        capacity = 2*capacity;
        int *temp =new int[capacity];
        for(int i=0; i<number; i++)
        {
            temp[i] = alist[i];
        }
        delete [] alist;
        alist = temp;
        }
}
