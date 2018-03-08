//
//  Nozama.cpp
//  Nozamas
//
//  Created by Xiaofei Guo on 2/24/17.
//  Copyright © 2017 Xiaofei Guo. All rights reserved.
//


#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include "Nozama.h"

using namespace std;


Nozama::Nozama() //leave it blank
{
}

Nozama::~Nozama()//leave it blank
{
}

void Nozama::run(std::string filename, int unit, std::string mode)
{
    Parser aparser(filename);
    Orderqueue myOrderqueue;
    while (!aparser.is_done())
    {
        myOrderqueue.enqueue(aparser.read_order());
    }
    
    ProcessQueue myFetchQueue(myOrderqueue);
    PackageQueue myPackageQueue (myFetchQueue,mode,unit);
    myPackageQueue.print();
    
}
