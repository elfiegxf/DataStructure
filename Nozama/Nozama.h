//
//  Nozama.hpp
//  Nozamas
//
//  Created by Xiaofei Guo on 2/24/17.
//  Copyright © 2017 Xiaofei Guo. All rights reserved.
//

#ifndef Nozama_h
#define Nozama_h

#include <stdio.h>
#include <iostream>
#include "ProcessQueue.h"
#include "Order.h"
#include "PackageQueue.h"
#include "Parser.h"

class Nozama
{
 public:
     Nozama();
     ~Nozama();
    void run(std::string filename, int unit, std::string mode);
 private:
    
};


#endif /* Nozama_h */
