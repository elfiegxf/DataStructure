//
//  PackageQueue.h
//  Nozamas
//
//  Created by Xiaofei Guo on 2/24/17.
//  Copyright © 2017 Xiaofei Guo. All rights reserved.
//

#ifndef PackageQueue_h
#define PackageQueue_h

#include <stdio.h>
#include <iostream>
#include "ProcessQueue.h"

 struct PackOrder{
    ProcessOrder anOrder;
    int totalTime;
    PackOrder &operator=(const PackOrder &source);
 };

class PackageQueue
{
 public:
  /*constructors*/
  PackageQueue();
  PackageQueue(ProcessQueue newqueue,std::string mode,int unit);
  
  /*copy constructor*/
  PackageQueue(const PackageQueue &source);
  PackageQueue &operator=(const PackageQueue &source);
    
  /*deconstructor*/
  ~PackageQueue();

 /*print the queue*/
  void print();
    
    /*to see if the queue is empty*/
  bool isEmpty();

    /*get the size of the queue*/
  int size();

    /*enqueue an order*/
  PackOrder *enqueue(ProcessOrder element, std::string mode, int unit);

    /*dequeue an order*/
  PackOrder *dequeue();

    /*get specific element's packaging time in the queue*/   
  PackOrder getElem (int num);

    /*mode 1 shortest time*/
  void shortest(int unit);
    
    /*mode2 round robin*/
  void round(int unit);


    
 private:
 
  const int INIT_CAPACITY = 5;
  PackOrder *alist;
  int capacity;
  int number;
 
  /*two different mode process*/
  void Shortest_Time(int units);
  void Round_Robin(int units);
  void expand();

    /*return the max totaltime*/
    int max();
    
    /*return the min totaltime*/
    int min();
    
    /*return the mean totaltime*/
    int mean();
};


#endif /* PackageQueue_h */
