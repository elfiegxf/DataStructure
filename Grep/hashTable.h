//
//  hashTable.h
//  gerp
//
//  Created by Xiaofei Guo on 4/17/17.
//  Copyright © 2017 Xiaofei Guo. All rights reserved.
//

#ifndef hashTable_h
#define hashTable_h

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <cstdlib>
#include <string.h>
#include <sstream>
#include <unordered_map>

struct HashedObj
{
    std::string keyword;
    std::vector <int> filedata;
    std::vector <int> linedata;
     bool operator==( const HashedObj& rhs ) const
        { return keyword == rhs.keyword;}
    
    bool operator !=( const HashedObj& rhs ) const
        { return !(*this == rhs);}

};
class hashTable
{
public:
    /*constructors*/
    hashTable();
    ~hashTable();
    bool contains(const HashedObj &x) const;
    void makeEmpty();
    
    /*add a new key*/
    bool insert( const HashedObj &x);
    bool insert( HashedObj && x );
    
    /*remove a key*/
    bool remove( HashedObj &x);
    
    /*add data to a key, if the key already exists, return 1, or create one and return 0 */
    bool updatedata( const HashedObj &x);
    
    /**/
    /*get the data of a specific key*/
    void get_data(const std::string x, std::vector<int> &f, std::vector<int> &l);
    
    
private:
    
    std::vector<std::vector<HashedObj>> theLists; //the array of lists
    static const int INIT_CAPA = 10000000;
    int currentsize;
    size_t myhash(const HashedObj &x) const;
};

#endif /* hashTable_h */
