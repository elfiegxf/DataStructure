//
//  gerp.cpp
//  gerp
//
//  Created by Xiaofei Guo on 4/19/17.
//  Copyright © 2017 Xiaofei Guo. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <string.h>
#include <sstream>
#include <dirent.h>
#include <vector>
#include "hashTable.h"
#include "indexfunction.h"
#include "search.h"
#include "stringProcessing.h"
#include "FSTree.h"
#include "searchfunction.h"

using namespace std;

int main(int argc, char *argv[] )
{
    //declare helper function.
    void traverseTree(DirNode *given, vector<string> &filepaths);
    
    //pass parameter
    char *directory = argv[1];
    
    DIR *dir;
    
    
    // Check if directory is a directory.
    if ((dir = opendir(directory)) != NULL)
    {
        FSTree fulldir(directory);
        
        //create a vector to save the paths;
        vector<string> filepaths;
        vector<vector<string>> linedata;
        //traverse the tree;
        DirNode * temp = fulldir.getRoot();
        traverseTree(temp,filepaths);
        linedata.resize(filepaths.size());
        
        //index the whole directory.
        hashTable myTable;
        hashTable myissTable;
        
        indexfunction(filepaths, myTable, myissTable, linedata);
        
        // here we start the program.
	string s;
        while(1)
	  {
        cout << "Query? ";
	    cin >> s;
	    if(!cin.eof())
	    {
	      if(s == "@quit" || s == "@q" )
          {
              cout<< "Goodbye! Thank you and have a nice day."<<endl;
              exit(0);
          }
	      else
		{
            if(s == "@i" || s == "@insensitie")
		    {
		      string s2;
		      cin >> s2;
              stripNonAlphaNum(s2);
		      insearchfunction(s2, myissTable, filepaths, linedata);
		    }
		  else //s == "@i"
		    {
              stripNonAlphaNum(s) ;
		      searchfunction(s, myTable, filepaths, linedata);
		    }
		}

            }
	    else
            exit(0);
	  }
        
    }
    
    else
        cerr<<"usage: gerp directory "<< endl<< "where directory is a valid directory"<<endl;
    
}


/*
 *input a given node and record all the files in a filePath queue
 *try to make it recursively
 */
void traverseTree(DirNode *given, vector<string> &filePaths)
{
    //base case: get files.
    if(given -> hasFiles())
    {   //cout<<"debug:files"<<endl;
        int numfile = given -> numFiles();
        string path = given -> getName();
       // int k=0;
        DirNode *WholeNode = given;
        
        while (WholeNode -> getParent())
        {
            WholeNode = WholeNode -> getParent();
            path = WholeNode -> getName() +'/'+ path;
        }
        
        for(int i=0; i< numfile; i++)
        { 
            string filepath = path + '/' + given -> getFile(i);
            filePaths.push_back(filepath);
            
            //cout<<"debug:valid"<<endl; cout << path <<endl;
        }
    }
    
    //recursive: subdir
    if(given -> hasSubDir())
    {
        int numsub = given -> numSubDirs();
        //cout<<"debug:subs"<<endl;
        while( numsub )
        {// cout<<"debug:"<<numsub<<"subs"<<endl;
            DirNode *sub;
            sub = given -> getSubDir(numsub-1);
            traverseTree(sub,filePaths);
            numsub--;
        }
    }
}

