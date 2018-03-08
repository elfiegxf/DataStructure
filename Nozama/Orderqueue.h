//
//  OrderQueue.h
//  Nozamas
//
//  Created by Xiaofei Guo on 2/24/17.
//  Copyright © 2017 Xiaofei Guo. All rights reserved.
//

#ifndef Orderqueue_h
#define Orderqueue_h

#include <stdio.h>
#include <iostream>
#include "Order.h"  

class Orderqueue
{
    public:
    
        /*constructors*/
        Orderqueue();
        Orderqueue(Order *newarray, int length);
    
        /*copy function*/
        Orderqueue(const Orderqueue &source);
        Orderqueue &operator=(const Orderqueue &source);
    
	    /*destructor*/
        ~Orderqueue();
 
        /*print whole queue*/
        void print();
        
        /*if queue is empty return 1, or return 0*/
        bool isEmpty();
        
        /*return the sum number of elements in the queue*/
        int size();
        
        /*enqueue */
        Order *enqueue(Order element);
        
        /*dequeue*/
	    Order *dequeue();
        
	    /*get the fitst element in the queue*/
        Order getFirstElem();

        /*return the element at specified place*/
        Order getElem(int num);
    
private:

    const int INIT_CAPACITY =5;
    Order *alist;
    int capacity;
    int number;
     
    /*try expand the capacity of the list*/
    void expand();
    
    
};
#endif /* Orderqueue_h */
