/*******************************************************************************
 * File:   main.cpp
 * Author: Zachary Priddy <zpriddy@asu.edu>
 * Class: CSE310 - Fall 2013 - M W 3:00pm
 *
 * Created on October 14, 2013, 5:25 PM
 *******************************************************************************/

#include <cstdlib>
#include <iostream>

#include "heap.h"
#include "debug.h"


using namespace std;

/*
 * 
 */





int main(int argc, char** argv) {


    
    //HEAP test_heap(20, 0);
    HEAP test_heap = InitializeHeap(20);
    Element b, c, d, e, f, g, h, i, j, k, l, m, n, o, p,q;
    b.key = 1;
    c.key = 9;
    d.key = 2;
    e.key = 4;
    f.key = 10;
    g.key = 5;
    h.key = 7;
    i.key = 3;
    j.key = 17;
    k.key = 92;
    l.key = 67;
    m.key = 79;
    n.key = 62;
    o.key = 52;
    p.key = 32;
    q.key = 100;
    Element a[8];
    //a = new Element[5];
    a[0]  = b;
    a[1]  = c;
    a[2]  = d;
    a[3]  = e;
    a[4]  = f;
    a[5]  = g;
    a[6]  = h;
    a[7]  = i;
    /*
    a[8]  = j;
    a[9]  = k;
    a[10] = l;
    a[11] = m;
    a[12] = n;
    a[13] = o;
    a[14] = p;
    */
    
    
    
    BuildHeap(test_heap, a, 8);
    //cout << test_heap.get_capacity();
    PrintHeap(test_heap);
    /*
    DeleteMaxHeap(test_heap);
    PrintHeap(test_heap);
    InsertToHeap(test_heap, q);
    PrintHeap(test_heap);
    IncreaseKeyHeap(test_heap, 2, 102);
    PrintHeap(test_heap);
    */
    return 0;
    
    
}



