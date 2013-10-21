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

#include "heap.h"
#include "debug.h"
#include "util.h"


using namespace std;

/*
 * 
 */


int main(int argc, char** argv) {

    int i, v;
    HEAP heap;
    bool heap_created = false;
    char command;
    char exit_command = 's';

    while( command != exit_command)
    {
        command = nextCommand(i, v);

        switch (command)
        {
            case 'k':
            case 'K':
                printf("COMMAND: %c %d %d\n", command, i, v);
                if(heap_created)
                {
                    //CHECK IF VALUE IS LARGER THAN EXISTING VALUE
                    IncreaseKeyHeap(heap, i, v);
                }
                else
                    printf("ERROR: NO HEAP CREATED!\n");

                break;
            case 'r':
            case 'R':
                printf("COMMAND: %c\n", command);

                break;

            case 'w':
            case 'W':
                printf("COMMAND: %c\n", command);
                if(heap_created)
                    PrintHeap(heap);
                else
                    printf("ERROR: NO HEAP CREATED!\n");
                break;

            case 'i':
            case 'I':
                printf("COMMAND %c %d \n", command, i);
                if(heap_created)
                    InsertHeap(heap, i);
                else
                    printf("ERROR: NO HEAP CREATED!\n");
                break;

            case 'd':
            case 'D':
                printf("COMMAND: %c\n", command);
                if(heap_created)
                    DeleteMaxHeap(heap);
                else
                    printf("ERROR: NO HEAP CREATED!\n");
                break;

            case 'c':
            case 'C':
                printf("COMMAND: %c %d\n", command, i);
                if(!heap_created)
                {
                    heap = InitializeHeap(i);
                    heap_created = true;
                }
                else
                    printf("Heap has already been \n");
                break;


            case 's':
            case 'S':
                cout << "COMMAND: " << command << "\n";
                cout << "\nExiting.. Goodbye!\n";
                command = 's';
                break;

            default: break;
        }
    }

/*
    
    //HEAP test_heap(20, 0);
    HEAP test_heap = InitializeHeap(10);
    Element b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q;
    b.key = 2;
    c.key = 2;
    d.key = 4;
    e.key = 7;
    f.key = 6;
    g.key = 8;
    h.key = 1;
    i.key = 40;
    j.key = 78;
    k.key = 56;
    l.key = 44;
    m.key = 34;
    n.key = 109;
    o.key = 33;
    p.key = 12;
    q.key = 24;
    Element a[6];
    //a = new Element[5];
    //a[0]  = b;
    a[0]  = c;
    a[1]  = d;
    a[2]  = e;
    a[3]  = f;
    a[4]  = g;
    a[5]  = h;
    
    a[6]  = i;
    a[7]  = j;
    a[8]  = k;
    a[9] =  l;
    a[10] = m;
    a[11] = n;
    a[12] = o;
    a[13] = p;
    a[14] = q;
    
    
   
    
    BuildHeap(test_heap, a, 6);
    //cout << test_heap.get_capacity();
    PrintHeap(test_heap);
    InsertHeap(test_heap, 5);
    PrintHeap(test_heap);
    DeleteMaxHeap(test_heap);
    PrintHeap(test_heap);
    IncreaseKeyHeap(test_heap, 2, 8);
    PrintHeap(test_heap);
    //InsertHeap(test_heap, 78);
    */
    /*
    InsertToHeap(test_heap, q);
    PrintHeap(test_heap);
    IncreaseKeyHeap(test_heap, 2, 102);
    PrintHeap(test_heap);
    */
   
    return 0;

    
    
}



