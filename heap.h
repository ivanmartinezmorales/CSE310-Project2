/* 
 * File:   heap.h
 * Author: zpriddy
 *
 * Created on ${date}, 6:02 PM
 */
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>

using namespace std;

#ifndef HEAP_H
#define	HEAP_H
 


struct Element
{
    int key;
};

class HEAP {
    public:
        HEAP ();
        HEAP (int, int, Element[]);
        HEAP (int, int, int);
        HEAP (int, int);
        ~HEAP(void);
        void InsertHeap(HEAP, int);
        
        void set_size_final(int fsize) {size_final=fsize;}
        
        int get_size() {return size;}
        void set_size(int n) {size=n;}
        void inc_size() {size++;}
        void dec_size() {size--;}
        int get_capacity() {return capacity;}
        
        
        Element get_element(int n) {return element[(n-1)];}
        void set_element_key(int node, int key) {this->element[(node-1)].key = key;}
        void set_element(int node,  Element i_element) {this->element[(node-1)] = i_element;} 

        int get_parent(int node)
        {
            if(node == 1)
                return NULL;
            else
                return floor(node/2);
        }
         Element get_parent_element(int node)
        {
           return (this->get_element(this->get_parent(node)));
        }
        bool parent_has_two_children(int node)
        {
            if(this->size >= this->get_parent(node)*2+1)
                return true;
            else
                return false;
        }
        Element get_right_child_element(int node)
        {
            return this->get_element((2*node)+1);
        }
        int get_right_child(int node)
        {
            if(2*node+1 <= this->size)
                return node*2+1;
            else
                return INT_MAX;
        }
        Element get_left_child_element(int node)
        {
            return this->get_element(2*node);
        }
        int get_left_child(int node)
        {
            if(node*2 <= this->get_size())
                return node*2;
            else
                return INT_MAX;
        }
        bool is_element(int node)
        {
            if(node <= this->size)
                return true;
            else
                return false;
        }
        void swap_with_parent(int node)
        {
            
            Element parent_element = this->get_parent_element(node);
            this->set_element(this->get_parent(node), this->get_element(node));
            this->set_element(node, parent_element);
            return;
        }
        //Swap with right and return node of where orginal element is
        int swap_with_right_child(int node)
        {
             Element current_element = this->get_element(node);
            this->set_element(node, this->get_right_child_element(node));
            this->set_element(this->get_right_child(node), current_element);
            return this->get_right_child(node);
        }

        //Swap with left and return node of where orginal element is
        int swap_with_left_child(int node)
        {
             Element current_element = this->get_element(node);
            this->set_element(node, this->get_left_child_element(node));
            this->set_element(this->get_left_child(node), current_element);
            return this->get_left_child(node);
        }


    private:
        int capacity;
        int size;
        int size_final;
        Element *element;
        
    
}; 




HEAP InitializeHeap(int);
int DeleteMaxHeap(HEAP&);
void InsertToHeap(HEAP&,  Element);
void InsertHeap(HEAP&, int);
void BuildHeap(HEAP&, Element[], int);
void IncreaseKeyHeap(HEAP&, int, int);
void PrintHeap(HEAP);
void Heapify(HEAP&, int);
void Sort_Heap(HEAP&);



#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* HEAP_H */

