//
//  testOrderqueue.cpp
//  Nozamas
//
//  Created by Xiaofei Guo on 2/25/17.
//  Copyright © 2017 Xiaofei Guo. All rights reserved.
//

#include <iostream>
#include "Orderqueue.h"
#include "ProcessQueue.h"
#include "PackageQueue.h"
#include "Nozama.h"
using namespace std;

int main()
{
    Order atest[4];
    atest[0].id = 0;
    atest[0].a_t = 0;
    atest[0].f_d = 1;
    atest[0].p_d = 3;
    
    atest[1].id = 1;
    atest[1].a_t = 2;
    atest[1].f_d = 4;
    atest[1].p_d = 4;
    
    atest[2].id = 2;
    atest[2].a_t = 3;
    atest[2].f_d = 5;
    atest[2].p_d = 4;
    
    atest[3].id = 3;
    atest[3].a_t = 4;
    atest[3].f_d = 5;
    atest[3].p_d = 4;
    
    Orderqueue test1(atest,4);
    
    test1.print();
    cout << "size:"<<test1.size()<<endl;
    cout << "empty?"<<test1.isEmpty()<<endl;
    test1.dequeue();
    test1.print();
    
    Order test2;
    test2.id = 2;
    test2.a_t = 6;
    test2.f_d = 4;
    test2.p_d = 3;
    
    Order *test3;
    test3 = test1.enqueue(test2);
    Orderqueue test4(test3,2);
    cout<<"test4 will be:"<<endl;
    test4.print();
    Order test5;
    test5 = test4.getFirstElem();
    cout<<test4.size()<<endl;
    
    ProcessQueue test6(test1);
    cout<<"test6 will be:"<<endl;
    test6.print();
    
    PackageQueue test7(test6,"ROUND_ROBBIN",2);
    test7.print();
    
    Parser aparse;
    
}
