/* 
 * File:   heap.h
 * Author: zpriddy
 *
 * Created on ${date}, 6:02 PM
 */


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
        //void BuildHeap(HEAP , int);
        void InsertHeap(HEAP, int);
        
        void set_size_final(int fsize) {size_final=fsize;}
        
        int get_size() {return size;}
        void set_size(int n) {size=n;}
        void inc_size() {size++;}
        void dec_size() {size--;}
        int get_capacity() {return capacity;}
        
        
        Element get_element(int n) {return element[(n-1)];}
        void set_element_key(int node, int key) {this->element[(node-1)].key = key;}
        void set_element(int node, Element i_element) {this->element[(node-1)] = i_element;} 

        int get_parent(int node)
        {
            int parent;

            if(node%2 == 0)
            {
                parent = node/2;
            }
            else
            {
                parent = (node-1)/2;
            }
            return parent;
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
            return node*2+1;
        }
        Element get_left_child_element(int node)
        {
            return this->get_element(2*node);
        }
        int get_left_child(int node)
        {
            return node*2;
        }
        bool    is_leaf_element(int node)
        {
            if(this->size_final <= 2*node+1)
                return true;
            else 
                return false;
        }


        
    private:
        int capacity;
        int size;
        int size_final;
        Element *element;
        
    
}; 




HEAP InitializeHeap(int);
Element DeleteMaxHeap(HEAP&);
void InsertToHeap(HEAP&, Element);
void InsertHeap(HEAP&, int);
void BuildHeap(HEAP&, Element[], int);
void IncreaseKeyHeap(HEAP&, int, int);
void PrintHeap(HEAP);
void Heapify(HEAP&, int);



#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* HEAP_H */

