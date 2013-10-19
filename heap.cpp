/*******************************************************************************
 * FILE NAME: heap.cpp
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
#include <iostream>
#include <cstdlib>


using namespace std;

#include "heap.h"
#include "debug.h"


//##############################################################################
//              HEAP CONSTRUCTORS 
//##############################################################################
HEAP::HEAP(int h_capacity, int h_size, Element h_element[])
{
    capacity = h_capacity;
    size = h_size;
    element = new Element[h_capacity];
    
    for(int i = 0 ; i < h_size ; i ++ )
    {
        element[i] = h_element[i];
    }
}

HEAP::HEAP()
{
    
}

HEAP::HEAP(int h_capacity, int h_size)
{
    capacity = h_capacity;
    element = new Element[h_capacity];
    size = h_size;
}

HEAP::~HEAP(void)
{
    //element = new Element[0];
    //delete[] element;
}


//##############################################################################


/******************************************************************************
* FUNCTION: InitializeHeap(int h_capacity)
*
* DESC: Initalizes the Heap with the disired capacity
*
* Calls: HEAP(Capacity, Size)
******************************************************************************/
HEAP InitializeHeap(int h_capacity)
{
    HEAP return_heap(h_capacity, 0);
    
    return return_heap;
    
}

/******************************************************************************
* FUNCTION: BuildHeap(HEAP &i_heap, Element a[], int size)
*
* DESC: Builds the heap with the inputed array of Elements
*
* Calls: InsertToHeap(HEAP, Element)
******************************************************************************/
void BuildHeap(HEAP &i_heap, Element a[], int size)
{


    debug("size of a", size);
    debug("Size before build heap", i_heap.get_size());
    
    //Make the heap in the order of the array
    for (int i = 0 ; i < size && i < i_heap.get_capacity(); i++)
    {
        InsertToHeap(i_heap, a[i]);    
    }
    
    debug("Size after build heap", i_heap.get_size());
    debug(i_heap.get_element(0).key);

    debug("i",floor(i_heap.get_size()/2));

    for(int i=floor(i_heap.get_size()/2); i >= 1 ; i--)
    {
        Heapify(i_heap, i);
    }
    
   
    
}

/******************************************************************************
* FUNCTION: InsertToHeap(HEAP &i_heap, Element i_element)
*
* DESC: Inserts the Element into the array and calls Heapify
*
* Calls: Heapify(HEAP, element#)
******************************************************************************/
void InsertToHeap(HEAP &i_heap, Element i_element)
{
    //Inset to last element of the Heap
    i_heap.inc_size();
    i_heap.set_element(i_heap.get_size(), i_element);
    
    //DEBUG STATMENT
    //PrintHeap(i_heap);

}

/******************************************************************************
* FUNCTION: Heapify(HEAP &i_heap, int element)
*
* DESC: Heapifys the heap starting at the element# provided 
*
* Calls: Heapify(HEAP, element#)
******************************************************************************/
void Heapify(HEAP &i_heap, int element)
{
    debug("Heapify");
    //PrintHeap(i_heap);
    //Get the key values for the left and right elements
    int left_key, right_key, largest;
    int current_key = i_heap.get_element(element).key;
    int left_node = i_heap.get_left_child(element);
    int right_node = i_heap.get_right_child(element);

    if(left_node <= i_heap.get_size())
    {
        left_key = i_heap.get_left_child_element(element).key;

        if(left_key > current_key)
            largest = left_node;
        else
            largest = element;
    }
    else
        largest = element;
    if(right_node <= i_heap.get_size())
    {
        right_key = i_heap.get_right_child_element(element).key;

        if(right_key > i_heap.get_element(largest).key)
            largest = right_node;
    }
    if(largest != element)
    {
        Element largest_element = i_heap.get_element(largest);
        i_heap.set_element(largest, i_heap.get_element(element));
        i_heap.set_element(element, largest_element);
        Heapify(i_heap, largest);
    }


}
/******************************************************************************
* FUNCTION: InsertHeap(HEAP &i_heap, int key)
*
* DESC: Inserts a new element into the Heap with a key of key 
*
* Calls: InsertToHeao(HEAP, Element)
******************************************************************************/
void InsertHeap(HEAP &i_heap, int key)
{
    //Make the new element
    Element new_element;
    new_element.key = key;
    
    //Insert the new element into the Heap
    InsertToHeap(i_heap, new_element);

    for(int i=floor(i_heap.get_size()/2); i >= 1 ; i--)
    {
        Heapify(i_heap, i);
    }
}

/******************************************************************************
* FUNCTION: DeleteMaxHeap(HEAP &i_heap)
* 
* DESC: Deletes the max element in the heap, resorts the heap and returns the
*       element that it deleted.
*
* Calls:  InitializeHeap(Capacity)
*         InsertToHeap(HEAP, Element)
******************************************************************************/
int DeleteMaxHeap(HEAP &i_heap)
{
    Element deleted_element = i_heap.get_element(1);

    i_heap.set_element(1, i_heap.get_element(i_heap.get_size()));
    i_heap.dec_size();

    for(int i=floor(i_heap.get_size()/2); i >= 1 ; i--)
    {
        Heapify(i_heap, i);
    }  

    return deleted_element.key;  
   
}

/******************************************************************************
* FUNCTION: IncreaseKeyHeap(HEAP &i_heap, int element, int key)
* 
* DESC: Sets the key of the inputd element# to the new key provied as key
*
* Calls:  InitializeHeap(Capacity)
*         InsertToHeap(HEAP, Element)
******************************************************************************/
void IncreaseKeyHeap(HEAP &i_heap, int element, int key)
{
    //Set the element key
    i_heap.set_element_key(element, key);

    while(element > 1 && i_heap.get_parent_element(element).key < key)
    {
        i_heap.swap_with_parent(element);
        element = i_heap.get_parent(element);
    }



 }

/******************************************************************************
* FUNCTION: PrintHeap(HEAP i_heap)
* 
* DESC: Prints the Heap infromation to the screen or to a file
*
* Calls:  NONE
******************************************************************************/
void PrintHeap(HEAP i_heap)
{
    cout << "HEAP Size: " << i_heap.get_size() << "\n";
    cout << "HEAP Capacity: " << i_heap.get_capacity() << "\n";
    cout << "[ ";
    for (int i=1 ; i <= i_heap.get_size() ; i++)
    {
        cout << i_heap.get_element(i).key << " ";
        
        if(i <= (i_heap.get_size()-1))
        cout << "| ";
    }
    
    cout << "]\n";
    
}
 