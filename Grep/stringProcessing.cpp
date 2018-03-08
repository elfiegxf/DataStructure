
//
//  stringProcessing.cpp
//  gerp
//
//  Created by Xiaofei Guo on 4/13/17.
//  Copyright © 2017 Xiaofei Guo. All rights reserved.
//

#include "stringProcessing.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;


void  stripNonAlphaNum(std::string &input)
{
 size_t  i=0;
 size_t  len = input.length();
  while(i<len)
    {
      if(!isalnum(input[i]))
	{
	  input.erase(i,1);
	  len--;
	}
      else
	i++;
    }

}
