/*******************************************************************************
 * File:   main.cpp
 * Author: Zachary Priddy <zpriddy@asu.edu>
 * Class: CSE310 - Fall 2013 - M W 3:00pm
 *
 * Created on October 14, 2013, 5:25 PM
 *******************************************************************************/

#include <cstdlib>
#include <iostream>
#include <cmath>
 #include <stdio.h>

#include "heap.h"
#include "debug.h"
#include "util.h"
#include "fileio.h"

bool display_command = false;

using namespace std;
Element *a;

void MakeElementArray(int size)
{
    a = new Element[size];
}

int main(int argc, char** argv) {

    int i, v;
    HEAP heap;
    
    bool heap_created = false;
    char command;
    char exit_command = 's';

    while( command != exit_command)
    {
        if(display_command){cout << "Waiting for next command\n";}
        command = nextCommand(i, v);
        
        switch (command)
        {
            case 'k':
            case 'K':
                if(display_command){printf("COMMAND: %c %d %d\n", command, i, v);}
                if(heap_created)
                {
                    if(i > heap.get_size())
                    {
                        errorOut(8);
                    }
                    //CHECK IF VALUE IS LARGER THAN EXISTING VALUE
                    if(v > heap.get_element(i).key)
                        IncreaseKeyHeap(heap, i, v);
                    else
                        errorOut(4);
                }
                else
                    errorOut(1);

                break;
            case 'r':
            case 'R':
                if(display_command){printf("COMMAND: %c\n", command);}
                if(heap_created)
                {
                    int size;
                    size = ReadInputFile();
                    if(size == 0)
                        break;
                    MakeElementArray(size);
                    ReadInputFile(heap, a, size);
                    BuildHeap(heap, a, size);
                }
                else
                    errorOut(1);
                break;

            case 'w':
            case 'W':
                if(display_command){printf("COMMAND: %c\n", command);}
                if(heap_created)
                    PrintHeap(heap);
                else
                    errorOut(1);
                break;

            case 'i':
            case 'I':
                if(display_command){printf("COMMAND %c %d \n", command, i);}
                if(heap_created)
                {
                    if(heap.get_size() < heap.get_capacity())
                        InsertHeap(heap, i);
                    else
                        errorOut(3);
                }
                else
                    errorOut(1);
                break;

            case 'd':
            case 'D':
                if(display_command){printf("COMMAND: %c\n", command);}
                if(heap_created)
                {
                    if(heap.get_size() <= 0)
                    {
                        errorOut(9);
                        break;
                    }
                    else
                        cout <<  DeleteMaxHeap(heap) << "\n";
                }
                else
                    errorOut(1);
                break;

            case 'c':
            case 'C':
                if(display_command){printf("COMMAND: %c %d\n", command, i);}
                if(!heap_created)
                {
                    if(i > 0)
                    {
                        heap = InitializeHeap(i);
                        heap_created = true;
                    }
                    else
                        errorOut(5);
                }
                else
                    errorOut(2);
                break;


            case 's':
            case 'S':
                if(display_command)
                {
                    cout << "COMMAND: " << command << "\n";
                    cout << "\nExiting.. Goodbye!\n";
                }
                command = 's';
                break;

            default: break;
        }
    }   
    return 0;   
}



