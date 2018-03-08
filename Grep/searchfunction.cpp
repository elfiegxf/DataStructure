//
//  searchfunction.cpp
//  gerp
//
//  Created by Xiaofei Guo on 4/18/17.
//  Copyright © 2017 Xiaofei Guo. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <string.h>
#include <sstream>
#include <vector>
#include <algorithm>
#include "hashTable.h"
#include "indexfunction.h"
#include "search.h"
#include "stringProcessing.h"
#include "searchfunction.h"

using namespace std;
/*sensitive seaching*/
void searchfunction(std::string keyword, hashTable &myTable, std::vector<std::string> &filepaths,std::vector<std::vector<std::string>> &lines )
{
     vector<int> filedata, linedata;
     myTable.get_data(keyword,filedata,linedata);

     size_t howManyfiles = filedata.size();
     size_t howManyLoc = linedata.size();

    if( howManyfiles != 0 )
    {
        string fileLocation = " ";
        
        for (int i =0; i< howManyLoc; i++)
        {
            int m=0,n=0;
            m = filedata[i];
            n = linedata[i];
            
            fileLocation = filepaths[m];
            std::string line;
            line = lines[m][n-1];// Check each line and print results.
            
            fileLocation = fileLocation+":"+ to_string(n) +": "+line;
            cout << fileLocation<<endl;
           
        }
    }
    else  
      cout<<"Not Found. Try with @insensitive or @i."<<endl;
}

/*insensitive search*/
void insearchfunction(std::string keyword, hashTable &myTable, std::vector<std::string> &filepaths, std::vector<std::vector<std::string>> &lines)
{     
    std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);
     vector<int> filedata, linedata;
     myTable.get_data(keyword,filedata,linedata);

     size_t howManyfiles = filedata.size();
     size_t howManyLoc = linedata.size();

    if( howManyfiles != 0 )
    {
        string fileLocation = " ";
        
        for (int i =0; i< howManyLoc; i++)
        {
            int m=0,n=0;
            m = filedata[i];
            n = linedata[i];
            
            fileLocation = filepaths[m];
            std::string line;
            line = lines[m][n-1];// Check each line and print results.
            
            fileLocation = fileLocation+":"+ to_string(n) +": "+line;
            cout << fileLocation<<endl;
           
        }
    }
    else
        cout<<"Not Found. "<<endl;
}
