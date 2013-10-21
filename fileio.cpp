/*******************************************************************************
 * File:   fileio.cpp
 * Author: Zachary Priddy <zpriddy@asu.edu>
 * Class: CSE310 - Fall 2013 - M W 3:00pm
 *
 * Created on October 19, 2013
 *******************************************************************************/

 #include "heap.h"
 #include "util.h"
 #include "fileio.h"
 #include <fstream>
 #include <iostream>


 using namespace std;

 string filename = "HEAPinput.txt";

 int ReadInputFile()
 {
 	int size;
 	string line;

 	ifstream inputfile(filename.c_str());
 	if(inputfile.is_open())
 	{
 		inputfile >> line;
 		size = atoi(line.c_str());
 		if(!size || size < 1)
 		{
 			errorOut(7);
 			return 0;
 		}

 	}
 	else
 		errorOut(6);

 	inputfile.close();
 	return size;

 }

 void ReadInputFile(HEAP &i_heap, Element a[], int size)
 {
 	int read_number;
 	int count = 0;
 	string line;

 	ifstream inputfile(filename.c_str());
 	if(inputfile.is_open())
 	{
 		inputfile >> line;

 		while(inputfile >> line)
 		{	
 			read_number = atoi(line.c_str());
 			if(!read_number)
 			{
 				warningOut(2);
 			}
 			count ++;
 			if(count <= size && count + i_heap.get_size() <= i_heap.get_capacity() )
 			{
 				Element temp;
 				temp.key = read_number;
 				a[count-1] = temp;
 			}
 			if(i_heap.get_capacity() < count + i_heap.get_size())
 				warningOut(3);

 		}
 		if(count > size)
 			warningOut(1);
 	}
 	else
 		errorOut(6);
 	inputfile.close();
 }
