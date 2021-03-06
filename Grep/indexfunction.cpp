//
//  search.cpp
//  gerp
//
//  Created by Xiaofei Guo on 4/17/17.
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

using namespace std;
void indexfunction(std::vector<std::string> filePaths, hashTable &newTable, hashTable &newTable2 ,std::vector<vector<std::string>> &lines)
{

    for (int i = 0; i < (int) filePaths.size(); i++)
    {
      
        string fileName = filePaths[i];
        std::ifstream file;
        file.open(fileName); 
	  std::string line;
     
      if (file.is_open())
        { //record the found lines
	  int recorder = 0;

	  // Check each line and print results.
	  while (getline(file,line))
	    {
          lines[i].push_back(line);
          recorder ++ ;
	      // parse into word
	      istringstream s(line);
	      string tmp;
	      
	      while(s >> tmp)
		{
          //case sensitive
          HashedObj temp;
		  stripNonAlphaNum(tmp);
		  temp.keyword = tmp;
		  temp.filedata.push_back(i);
		  temp.linedata.push_back(recorder);
		  newTable.updatedata(temp);
            
            //case insensitive
            HashedObj temp2;
            std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
            temp2.keyword = tmp;
            temp2.filedata.push_back(i);
            temp2.linedata.push_back(recorder);
            newTable2.updatedata(temp2);
		}
	     
	     }
	  file.close();
	}
	else
              cerr << "Unable to open " <<  fileName << endl;
                   
    } 

}


 
