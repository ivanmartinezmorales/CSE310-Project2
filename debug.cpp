/*******************************************************************************
 * FILE NAME: degub.cpp
 * DATE: ${date}
 * AUTHOR: Zachary Priddy
 *              me@zpriddy.com
 *              zpriddy@asu.edu
 * 
 * DESC:
 * 
 * 
 * 
 * CHANGE LOG:
 *      ${date}: File Created
 *      
 * 
 * 
 ******************************************************************************/
#include <cstdlib>
#include <iostream>

using namespace std;

int DEBUG=0;



void debug(string out)
{
    if(DEBUG == 1)
    {
        cout << "DEBUG:\n";
        cout << out << "\n";
    }
}

void debug(int out)
{
    if(DEBUG == 1)
    {
        cout << "DEBUG:\n";
        cout << out << "\n";
    }
}

void debug(string desc, int out)
{
    if(DEBUG == 1)
    {
        cout << "DEBUG: " << desc << "\n";
        cout << out << "\n";
    }
    
    
}