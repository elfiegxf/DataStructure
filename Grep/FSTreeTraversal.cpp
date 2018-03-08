//
//  FSTreeTraversal.cpp
//  gerp
//
//  Created by Xiaofei Guo on 4/13/17.
//  Copyright © 2017 Xiaofei Guo. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <cstdlib>
#include <string.h>
#include <sstream>
#include <dirent.h>
#include "FSTree.h"
using namespace std;

int main(int argc, char *argv[] )
{
    //declare helper function.
    void traverseTree(DirNode *given, queue<string> &filepaths);
    
    //pass parameter
    char *directory = argv[1];
    
    DIR *dir;

    // Check if directory is a directory.
    if ((dir = opendir(directory)) != NULL)
    {
        FSTree fulldir(directory);
        queue<string> filepaths;
        //traverse the tree;
        DirNode * temp = fulldir.getRoot();
	//cout<<"debug:valid"<<endl;
        traverseTree(temp,filepaths);
        unsigned long asize = (int)filepaths.size();
        for(int i=0; i < asize; i++)
	  {
	    cout<<filepaths.front()<<endl;
            filepaths.pop();
	  }
    }
    else
      cerr<<"usage: gerp directory "<< endl<< "where directory is a valid directory"<<endl;

}


/*
 *input a given node and record all the files in a filePath queue
 *try to make it recursively
 */
void traverseTree(DirNode *given, queue<string> &filePaths)
{
    //base case: get files.
    if(given -> hasFiles())
      {   //cout<<"debug:files"<<endl;
        int numfile = given -> numFiles();
        string path = given -> getName();
        int k=0;
        for(int i=0; i< numfile; i++)
	  {  cout << "times:"<<k++<<endl;
            path = path + '/' + given -> getFile(i);
            filePaths.push(path);
	    
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
	    cout<<"testsub:"<<sub -> getName()<<endl;
            traverseTree(sub,filePaths);
            numsub--;
        }
    }
}
