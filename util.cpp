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

void errorOut(int error_code)
{
	cout << "ERROR: ";
	switch(error_code)
	{
	case 1:
		cout << "HEAP HAS NOT BEEN CREATED\n";
		break;
	case 2:
		cout << "HEAP HAS ALREADY BEEN CREATED\n";
		break;
	case 3:
		cout << "THE HEAP HAS HIT IS COMPACITY\n";
		break;
	case 4:
		cout << "PLEASE ENTER A VALUE THAT IS LARGER THAN THE EXISTING VALUE\n";
		break;
	case 5:
		cout << "COMPACITY MUST BE LARGER THAN 0\n";
		break;
	case 6:
		cout << "CANT OPEN INPUT FILE\n";
		break;
	case 7:
		cout << "SIZE MUST BE LARGER THAN 0\n";
		break;
	case 8:
		cout << "REQUESTED ELEMENT IS OUTSIDE OF THE SIZE OF THE HEAP\n";
		break;
	case 9:
		cout << "HEAP SIZE IS ALREADY AT 0, CAN NOT DELETE ANY MORE\n";
		break;

	default:
		cout << "UNKNOWN ERROR... QUITING";
		exit(0);
		break;
	}
}

void warningOut(int warning_code)
{
	cout << "WARNING: ";
	switch(warning_code)
	{
		case 1:
			cout << "MORE LINES IN THE THE INPUT FILE THAN LISTED AT THE TOP - ONLY READING THE NUMBER OF LINES LISTED AT THE TOP\n";
			break;
		case 2:
			cout << "NUMBER FROM FILE DOSENT APPARE TO BE A NUMBER (OR IS 0)\n";
			break;
		case 3:
			cout << "REQUESTED TO READ MORE LINES THE THE CAPACITY IS SET TO - WILL ONLY READ UPTO THE CAPACITY\n";
			break;

		default:
			cout << "UNKNOWN WARRNING... CONTINUING PROGRAM\n";
			break;
	}
}