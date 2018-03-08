//
//  FetchQueue.h
//  Nozamas
//
//  Created by Xiaofei Guo on 2/24/17.
//  Copyright © 2017 Xiaofei Guo. All rights reserved.
//
 
#ifndef ProcessQueue_h
#define ProcessQueue_h

#include <stdio.h>
#include <iostream>
#include "Orderqueue.h"

/*
 *this class simulates the process of both fetching and packing units
 *since they share a lot of common
 */
struct ProcessOrder{
 Order anOrder;
 int TimeStamp;
 ProcessOrder &operator=(const ProcessOrder &source);
};

class ProcessQueue
{

public:
    /*constructors*/
    ProcessQueue();
    ProcessQueue(Orderqueue newqueue);
    
    /*copy function*/
    ProcessQueue (const ProcessQueue &source);
    ProcessQueue &operator=(const ProcessQueue &source);
    
    /*destructor*/
    ~ProcessQueue();
    
    /*print the queue*/
    void print();
   
    /*processes the order,make it enqueue, return the processing time */
    int Process(Order element);
    
    /*process the order,make it enqueue queue at one time and return void*/
    void Process(Orderqueue aQueue);

    /*enqueue an order*/
    ProcessOrder *enqueue(Order element);

    /*dequeue an order*/
    ProcessOrder *dequeue();
      
     /*get the last element of the queue*/
    ProcessOrder getlastElem();
 
    /*return element at specific place*/
    ProcessOrder getElem(int place);
    
    /*to see if the queue is empty*/
    bool isEmpty();

    /*get the size of the queue*/
    int size();
  

 
private:
      const int INIT_CAPACITY = 5;

     
      ProcessOrder *alist;
      int capacity ;
      int number ;
 
    void expand();
    void expand(int length);
};

#endif /* FetchQueue_h */
