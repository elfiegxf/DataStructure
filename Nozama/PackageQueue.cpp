//
//  PackageQueue.cpp
//  Nozamas
//
//  Created by Xiaofei Guo on 2/24/17.
//  Copyright © 2017 Xiaofei Guo. All rights reserved.
//
#include <iostream>
#include <stdexcept>
#include "PackageQueue.h"

using namespace std;

/*PackOrder struct overload*/
PackOrder  &PackOrder::operator=(const PackOrder &source)
{
    if (this == &source)
        return *this;
    else
    {
        anOrder = source.anOrder;
        totalTime = source.totalTime;
        return *this;
    }
}

/*constructors*/
PackageQueue::PackageQueue()
{
    alist = new PackOrder[INIT_CAPACITY];
    capacity = INIT_CAPACITY;
    number = 0;
}


PackageQueue::PackageQueue(ProcessQueue newqueue,std::string mode,int unit)
{
    capacity = newqueue.size();
    number = 0;
    alist = new PackOrder[capacity];
    
    for(int i = 0; i<capacity; i++)
    {
        alist[i].anOrder= newqueue.getElem(i);
        number++;
    }
    
    if (mode == "SHORTEST_TIME")
    {
        shortest(unit);
    }
    if (mode == "ROUND_ROBBIN")
    {
        round(unit);
    }
}


/*destructor*/
PackageQueue::~PackageQueue()
{
    if (alist != NULL)
        delete [] alist;
}

/*copy constructor*/
PackageQueue &PackageQueue::operator=(const PackageQueue &source)
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


/*print function*/
void PackageQueue::print()
{
    if (alist != NULL | number != 0)
    {
        for(int i = 0; i< number; i++){
            cout << "<Order(" << alist[i].anOrder.anOrder.id<< ") arrival_timestamp = "<<alist[i].anOrder.anOrder.a_t <<" fetch_duration = "<<alist[i].anOrder.anOrder.f_d<<" pack_duration = "<<alist[i].anOrder.anOrder.p_d<<" total time = "<< alist[i].totalTime <<">"<< endl;
            cout<<"min elapsed time "<< min()<<" minutes"<<endl;
            cout<<"max elapsed time "<< max()<<" minutes"<<endl;
            cout<<"mean elapsed time "<< mean()<<" minutes"<<endl;
            cout<< number <<" orders processed"<<endl;
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
bool PackageQueue::isEmpty()
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
int PackageQueue::size()
{
    return number;
}

/*
 *enqueue
 *paramiter: Order
 *return: PackOrder array
 */
PackOrder *PackageQueue::enqueue(ProcessOrder element, std::string mode, int unit)
{
    if ( number >= capacity)
    {
        expand();
    }
    alist[number].anOrder= element;
    number++;
    
    if (mode == "SHORTEST_TIME")
    {
        shortest(unit);
    }
    
    if (mode == "ROUND_ROBBIN")
    {
        round(unit);
    }
    return alist;
}

/*
 *dequeue
 *paramiter: Order
 *return: PackOrder array
 */
PackOrder *PackageQueue::dequeue()
{
    if (number == 0 |alist==NULL)
    {
        throw runtime_error("empty_stack");
    }
    else
    {
        alist[number].anOrder.anOrder.id = NULL;
        alist[number].anOrder.anOrder.a_t = NULL;
        alist[number].anOrder.anOrder.f_d = NULL;
        alist[number].anOrder.anOrder.p_d = NULL;
        alist[number].anOrder.TimeStamp = NULL;
        alist[number].totalTime = NULL;
        number--;
        return alist;
    }
}


/*get the specific element of the queue*/
PackOrder PackageQueue::getElem(int num)
{
    if (number == 0 |alist==NULL)
    {
        throw runtime_error("empty_stack");
    }
    else
    {
        return alist[num];
    }
}

/*
 *round
 *parameter: int unit
 *return :void
 *this function is the packaging process of "ROUND_ROBBIN" mode
 */
void PackageQueue::round(int unit)
{
    ProcessQueue *packing = new ProcessQueue[unit];
    
    Order packOrder;
    int index;
    
    for (int i = 0; i<number; i++)
    {
        packOrder.id = alist[i].anOrder.anOrder.id;
        packOrder.a_t = alist[i].anOrder.TimeStamp;
        packOrder.f_d = alist[i].anOrder.anOrder.p_d;

        index = (alist[i].anOrder.anOrder.id)%unit;
        packing[index].enqueue(packOrder);
        alist[i].totalTime=packing[index].getlastElem().TimeStamp- alist[i].anOrder.anOrder.a_t;
    }
    
}

/*
 *shortest
 *parameter: int unit
 *return :void
 *this function is the packaging process of "SHORTEST_TIME" mode
 */
void PackageQueue::shortest(int unit)
{
    ProcessQueue *packing = new ProcessQueue[unit];
    Order packOrder;
    int index = 0;
    int comparation = 0;
    int diff =0;
    for (int i = 0; i<number; i++)
    {
        packOrder.id = alist[i].anOrder.anOrder.id;
        packOrder.a_t = alist[i].anOrder.TimeStamp;
        packOrder.f_d = alist[i].anOrder.anOrder.p_d;
        
        
        for(int j = 0; j<unit; j++)
        {
            if(packing[j].isEmpty())
            {
                index = j;
                break;
            }
            else
            {
                diff =packing[j].getlastElem().TimeStamp - comparation ;
                if (diff <=0)
                {
                    index = j;
                }
                comparation =  packing[j].getlastElem().TimeStamp;
            }
        }
        
         packing[index].enqueue(packOrder);
        alist[i].totalTime=packing[index].getlastElem().TimeStamp- alist[i].anOrder.anOrder.a_t;
       
    }

}

void PackageQueue::expand()
{
    if(alist == NULL)
    {
        capacity = 5;
        alist = new PackOrder[capacity];
    }
    else
    {
        capacity = 2*capacity;
        PackOrder *temp =new PackOrder[capacity];
        for(int i=0; i<number; i++)
        {
            temp[i] = alist[i];
        }
        delete [] alist;
        alist = temp;
    }
}

int PackageQueue::min()
{
    int temp =0;
    for (int i=0;i<number;i++)
    {
        if (i == 0)
            temp = alist[0].totalTime;
        else
        {
            if (alist[i].totalTime - temp <= 0)
                temp = alist[i].totalTime;
        }
    }
    return temp;
}

int PackageQueue::max()
{
    int temp =0;
    for (int i=0;i<number;i++)
    {
        if (i == 0)
            temp = alist[0].totalTime;
        else
        {
            if (alist[i].totalTime - temp >= 0)
                temp = alist[i].totalTime;
        }
    }
    return temp;
}

int PackageQueue::mean()
{
    int temp =0;
    for (int i=0;i<number;i++)
    {
        temp = temp +alist[i].totalTime;
        
    }
    return temp/number;
}
