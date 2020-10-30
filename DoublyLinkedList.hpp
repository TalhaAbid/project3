#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST
#include "DoubleNode.hpp"
#include <iostream>

template<class T>
class DoublyLinkedList {
    protected:
        DoubleNode<T>* headPtr;
        int listSize;
    public:
        //    Default Constructor
        DoublyLinkedList(); 
        //Copy Constructor 
        DoublyLinkedList(const DoublyLinkedList<T> * aList);
        //Destructor
        ~DoublyLinkedList();

        bool insert(const T &item, const int &position); 
        //inserts item at position in caller list
        bool remove(const int &position);           
        //removes the node at position
        int getSize() const; 
        // returns the number of the nodes in the calling list
        DoubleNode<T>* getHeadPtr() const; 
        // returns a copy of the headPtr
        DoubleNode<T>* getAtPos(const int &pos) const; 
        // returns a pointer to the node located at pos
        bool isEmpty() const;                       
        // returns whether the calling list is empty
        void clear();                               
        // clears the list
        int getIndexOf(const T &item) const; 
        // returns the position of the given item in the list, -1 otherwise
        void display() const;                       
        // prints the contents of the calling list in order
        void displayBackwards() const;              
        // prints the contents of the calling list in reverse order
        //DoubleNode<T>* copyNode(DoubleNode<T> &node);
        //take a node and return a copy of it
        DoublyLinkedList<T> interleave(const DoublyLinkedList<T> &a_list); 
        // returns the interleaved list of the calling and parameter lists

};
#include "DoublyLinkedList.cpp"

#endif
