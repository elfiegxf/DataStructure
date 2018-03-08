//
//  search.h
//  gerp
//
//  Created by Xiaofei Guo on 4/17/17.
//  Copyright © 2017 Xiaofei Guo. All rights reserved.
//

#ifndef search_h
#define search_h
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "hashTable.h"


/*one tanle for case sensitve, another for case insensitive */
void indexfunction(std::vector<std::string> filePaths, hashTable &newTable, hashTable &newTable2 , std::vector<std::vector<std::string>> &lines);
//void issindexfunction(std::vector<std::string> filePaths, hashTable &newTable);

#endif /* search_h */
