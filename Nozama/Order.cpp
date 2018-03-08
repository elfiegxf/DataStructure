//
//  Order.cpp
//  Nozamas
//
//  Created by Xiaofei Guo on 2/25/17.
//  Copyright © 2017 Xiaofei Guo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Order.h"

using namespace std;

Order &Order::operator=(const Order &source)
{
    if (this == &source)
        return *this;
    else
    {
        id = source.id;
        a_t = source.a_t;
        f_d = source.f_d;
        p_d = source.p_d;
        return *this;
    }
}
