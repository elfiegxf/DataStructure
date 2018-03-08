//
//  processtime.hpp
//  Nozamas
//
//  Created by Xiaofei Guo on 3/1/17.
//  Copyright © 2017 Xiaofei Guo. All rights reserved.
//

#ifndef processtime_hpp
#define processtime_hpp

#include <stdio.h>
#include <iostream>
#include "Order.h"
class processtime
{
    
public:
    
    /*constructors*/
    processtime();
   
    /*copy function*/
    processtime(const processtime &source);
    processtime &operator=(const processtime &source);
    
    /*destructor*/
    ~processtime();
    
    /*print whole queue*/
    void print();
    
    /*if queue is empty return 1, or return 0*/
    bool isEmpty();
    
    /*return the sum number of elements in the queue*/
    int size();
    
    /*enqueue */
    int *enqueue(int element);
    
    /*dequeue*/
    int *dequeue();
    
    /*get the fitst element in the queue*/
private:
    
    const int INIT_CAPACITY =5;
    int *alist;
    int capacity;
    int number;
    void expand();
    
};
#endif /* processtime_hpp */
