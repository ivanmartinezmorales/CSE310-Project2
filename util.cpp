/*******************************************************************************
 * File:   util.cpp
 * Author: Zachary Priddy <zpriddy@asu.edu>
 * Class: CSE310 - Fall 2013 - M W 3:00pm
 *
 * Created on October 19, 2013
 *******************************************************************************/

#include "util.h"
#include <iostream>

 using namespace std;

//=============================================================================
int nextCommand(int& i, int& v)
{
  char c;
  while(1)
  {
    scanf("%c", &c);
    if(c == ' ' || c == '\t' || c == '\n')
    {
		continue; 
	}
    if(c == 'S' || c == 'R' || c == 'W' || c == 'D' )
    {
        break;
    }
    if(c == 's' || c == 'r' || c == 'w' || c == 'd' )
    {
		break; 
	}
    if(c == 'K' || c == 'k')
    {
        scanf("%d", &i); 
        scanf("%d", &v);
        break;
	}
	if (c == 'C' || c == 'c')
	{
		scanf("%d", &i);
		break;
	}
	if(c == 'I' || c == 'i')
	{
		scanf("%d", &i);
		break;
	}
    printf("Invalid Command\n");
  }
return c; 
}