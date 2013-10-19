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

    i_heap.set_size_final(size);

    debug("size of a", size);
    debug("Size before build heap", i_heap.get_size());
    
    //Make the heap in the order of the array
    for (int i = 0 ; i < size && i < i_heap.get_capacity(); i++)
    {
        InsertToHeap(i_heap, a[i]);    
    }
    
    debug("Size after build heap", i_heap.get_size());
    debug(i_heap.get_element(0).key);

    Sort_Heap(i_heap);
    
   
    
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
    PrintHeap(i_heap);

}

/******************************************************************************
* FUNCTION: Heapify(HEAP &i_heap, int element)
*
* DESC: Heapifys the heap starting at the element# provided 
*
* Calls: Heapify(HEAP, element#)
******************************************************************************/
void Heapify(HEAP &i_heap, int element, int furthest_left_node)
{
    PrintHeap(i_heap);

    if(element == furthest_left_node)
    {
        debug("SHOULD BE FIRST TIME");
        element = i_heap.get_parent(furthest_left_node);
    }

    //while(element != furthest_left_node)
    for(int i=0 ; i < i_heap.get_size()*9 ; i++)
    {
        debug("WHILE LOOP");
        PrintHeap(i_heap);
        //If the element has two children then swap with the largest one
        if(i_heap.parent_has_two_children(element))
        {
            if(i_heap.get_left_child_element(element).key > i_heap.get_element(element).key && i_heap.get_right_child_element(element).key > i_heap.get_element(element).key)
            {
                if(i_heap.get_left_child_element(element).key > i_heap.get_right_child_element(element).key)
                {
                    element = i_heap.swap_with_left_child(element);
                }
                else
                {
                    element = i_heap.swap_with_right_child(element);
                }

            }
            else if(i_heap.get_left_child_element(element).key > i_heap.get_element(element).key && i_heap.get_right_child_element(element).key <= i_heap.get_element(element).key)
            {
                element = i_heap.swap_with_left_child(element);
            }
            else if(i_heap.get_right_child_element(element).key > i_heap.get_element(element).key && i_heap.get_left_child_element(element).key <= i_heap.get_element(element).key)
            {
                element = i_heap.swap_with_right_child(element);
            }
            else
            {
                if(element == 1)
                {
                    //if(i_heap.is_element(furthest_left_node+1))
                    //    element = element + 1;
                    //else 
                        element = 3;

                }
                else
                    element = i_heap.get_parent(element);
            }


        }
        else if(i_heap.get_left_child_element(element).key > i_heap.get_element(element).key)
        {
            element = i_heap.swap_with_left_child(element);
        }
        else
        {
            if(element == 1)
            {
                if(i_heap.is_element(furthest_left_node+1))
                    element = element + 1;
                else 
                    element = 3;

            }
            else
                element = i_heap.get_parent(element);
        }

        //Heapify(i_heap, element, furthest_left_node);
        
    }

    /*
    if(i_heap.is_element(element+1))
        element = element+1;
    else
        element = i_heap.get_parent(element)+1;

    Heapify(i_heap, element, furthest_left_node);
    */
}

void Sort_Heap(HEAP &i_heap)
{
    //Find furthest left leaf node
    int current_node = 1;
    int furthest_left_node;
    int node_to_check;
    //Keep going left until you find a leaf node
    while(!i_heap.is_leaf_element(current_node))
    {
        current_node = 2*current_node;
    }
    furthest_left_node = current_node;

    Heapify(i_heap, current_node, furthest_left_node);
/*
    if(i_heap.is_element(furthest_left_node+1))
        node_to_check = furthest_left_node+1;
    else
        node_to_check = i_heap.get_parent(furthest_left_node)+1;

    current_node = node_to_check;

    while(current_node != furthest_left_node)
    {
        if(i_heap.is_leaf_element(current_node))
            Heapify(i_heap, current_node, furthest_left_node);
        if(i_heap.is_element(current_node+1))
            current_node = current_node+1;
        else
            current_node = i_heap.get_parent(current_node)+1;
    }

    */

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

    int current_node = 1;
    int furthest_left_node;
    int node_to_check;
    //Keep going left until you find a leaf node
    while(!i_heap.is_leaf_element(current_node))
    {
        current_node = 2*current_node;
    }
    furthest_left_node = current_node;

    Heapify(i_heap, current_node, furthest_left_node);
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
Element DeleteMaxHeap(HEAP &i_heap)
{
    Element return_element;
    //Max element will be at the element 1
    return_element = i_heap.get_element(1);
    i_heap.set_element(1, i_heap.get_element(i_heap.get_size()));

    int current_node = 1;
    i_heap.dec_size();

    while(!i_heap.is_leaf_element(current_node))
    {
        PrintHeap(i_heap);
        debug("DEL HEAP");
        if(i_heap.parent_has_two_children(current_node))
        {

            if(i_heap.get_left_child_element(current_node).key > i_heap.get_right_child_element(current_node).key)
            {
                current_node = i_heap.swap_with_left_child(current_node);
            }
            else
            {
                current_node = i_heap.swap_with_right_child(current_node);
            }


        }
        else if(i_heap.get_left_child_element(current_node).key > i_heap.get_element(current_node).key)
        {
            current_node = i_heap.swap_with_left_child(current_node);
        }
        else
        {
        
        }
    }
    

    

    //i_heap = new_heap;
    //delete new_heap;
    

    //Return the element that was deleted
    return return_element;
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
    
    //Re-order the heap
    //HEAP new_heap = InitializeHeap(i_heap.get_capacity());
    //for(int i=1; i <= i_heap.get_size() ; i++)
    //{
    //    InsertToHeap(new_heap, i_heap.get_element(i));
    //}

    //set the old heap to the new heap
    
    //i_heap = new_heap;
    //
    Heapify(i_heap, element, 2*2*2);
    return;

    
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
 