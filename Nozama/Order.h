//
//  Order.h
//  Nozamas
//
//  Created by Xiaofei Guo on 2/24/17.
//  Copyright © 2017 Xiaofei Guo. All rights reserved.
//

#ifndef Order_h
#define Order_h

#include <stdio.h>
#include <iostream>
#ifndef ORDER_H
#define ORDER_H

struct Order {
    int id;
    int a_t;  /* aka "arrival time" */
    int f_d;     /* aka "fetch time"   */
    int p_d;      /* aka "pack time"    */
    Order &operator=(const Order &source);
};

#endif
#endif /* Order_h */
