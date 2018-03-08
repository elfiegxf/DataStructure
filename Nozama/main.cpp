//
//  main.cpp
//  Nozamas
//
//  Created by Xiaofei Guo on 3/2/17.
//  Copyright © 2017 Xiaofei Guo. All rights reserved.
//

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include "Parser.h"
#include "PackageQueue.h"

using namespace std;

int main( int argc, char *argv[] )
{
    if( argc != 4 )
        cout<<"usage: "<< argv[0] << "<filename> <num_packaging_units> <packer_mode>\n";
    
    else
    {
        ifstream the_file(argv[1]);
        if( !the_file.is_open() )
            cout << "couldn't open file\n";
        else
        {
            
            string filename = argv[1];
            istringstream buffer(argv[2]);
            int unit;
            buffer >> unit;
            string mode = argv[3];
            
            Parser aparser(filename);
            Orderqueue aqueue;
            while (!aparser.is_done())
            {
                aqueue.enqueue(aparser.read_order());
            }
            
            ProcessQueue anotherqueue(aqueue);
            PackageQueue againqueue(aqueue,mode,unit);
            againqueue.print();
        }
    }
    
    
}
