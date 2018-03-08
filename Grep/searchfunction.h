//
//  searchfunction.h
//  gerp
//
//  Created by Xiaofei Guo on 4/18/17.
//  Copyright © 2017 Xiaofei Guo. All rights reserved.
//

#ifndef searchfunction_h
#define searchfunction_h
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <string.h>
#include <sstream>
#include <vector>
#include "hashTable.h"
#include "indexfunction.h"
#include "search.h"
#include "stringProcessing.h"

void searchfunction(std::string keyword, hashTable &myTable, std::vector<std::string> &filepaths, std::vector<std::vector<std::string>> &lines);
void insearchfunction(std::string keyword, hashTable &myTable, std::vector<std::string> &filepaths, std::vector<std::vector<std::string>> &lines);

#endif /* searchfunction_h */
