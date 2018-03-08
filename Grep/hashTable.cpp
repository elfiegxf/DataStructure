//
//  hashTable.cpp
//  gerp
//
//  Created by Xiaofei Guo on 4/17/17.
//  Copyright © 2017 Xiaofei Guo. All rights reserved.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <cstdlib>
#include <string.h>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include "hashTable.h"

using namespace std;
/*constructors*/
hashTable::hashTable()
{
    currentsize = INIT_CAPA ;
    theLists.resize(currentsize) ; //the array of lists
    
}
hashTable::~hashTable()
{
    makeEmpty();
}

void hashTable::makeEmpty()
{
    for(auto & thisList : theLists )
        thisList.clear();
}

bool hashTable::contains(const HashedObj &x) const
{
    auto &whichList = theLists[(int)myhash(x)];
    return find(begin(whichList), end(whichList),x) != end(whichList);
}

bool hashTable::remove( HashedObj &x)
{
    auto & whichList = theLists[ myhash(x)];
    auto itr = find(begin(whichList), end(whichList),x);
    if(itr == end(whichList))
        return false;
    
    whichList.erase(itr);
    --currentsize;
    return true;
}

bool hashTable::insert(const HashedObj &x)
{
    auto & whichList = theLists[ myhash(x)];
    if (find( begin(whichList),end(whichList),x) != end( whichList))
        return false;
    whichList.push_back(x);
    return true;
    
}

bool hashTable::insert( HashedObj && x )
{
    auto & whichList = theLists[ myhash(x)];
    if (find( begin(whichList),end(whichList),x) != end( whichList))
        return false;
    
    whichList.push_back(x);
    return true;
}

bool hashTable::updatedata(const HashedObj &x)
{
    auto &whichList = theLists[myhash(x)];
    if (insert(x))
        return false;
    else
    {
        int loc = 0;
        for (int i = 0; i<(int) whichList.size(); i++)
        {
            if (whichList[i] == x)
            {
                loc = i;
                break;
            }
        }
        if( whichList[loc].filedata.back()!= x.filedata.front() || whichList[loc].linedata.back()!= x.linedata.front())
         {   
           whichList[loc].filedata.push_back(x.filedata.front());
	    whichList[loc].linedata.push_back(x.linedata.front());
	    }
	    return true;
    }
}

/*get the data of a specific key*/
void hashTable::get_data(const std::string x, std::vector<int> &f, std::vector<int> &l) 
{
  HashedObj searching;
  searching.keyword = x;
     auto &whichList = theLists[myhash(searching)];
        int loc = 0;
 
        for (int i = 0; i<(int) whichList.size(); i++)
        {
            if (whichList[i].keyword == x)
            {
      
                loc = i;
                f = whichList[loc].filedata;
                l = whichList[loc].linedata;
                break;
            }
        
        }
    
}


size_t hashTable::myhash(const HashedObj &x) const
{
    hash<string> hash_function;
    return hash_function(x.keyword)%currentsize;
}
