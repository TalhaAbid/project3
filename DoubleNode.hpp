#ifndef DOUBLE_NODE_
#define DOUBLE_NODE_

template<typename T>
class DoubleNode {
    private:
        T item_;
        DoubleNode<T>* next_;
        DoubleNode<T>* prev_;
    public:
        //constructors
        /**
         *Default constructor
         *set item_ to T()
         *set next_ to nullptr
         *set prev_ to nullptr
         **/
        DoubleNode();
        /**
         * Paratamerized constructor
         * @param anItem the item in the node
         * @param nextNodePtr the ptr to the nextNode
         **/
        DoubleNode(T anItem);
        /**
         * Paratamerized constructor
         * @param anItem the item in the node
         * @param nextNodePtr the ptr to the next node
         * @param prevNodePtr the ptr to the previous node.
         **/
        DoubleNode(T& anItem,DoubleNode<T>* nextNodePtr,DoubleNode<T>* prevNodePtr);
        //setter functions
        /**
         * Set nodes item to anItem
         * @param anItem the item to put in the node
         **/
        void setItem(const T &anItem);
        /**
         * Set node's previous pointer to the passed pointer
         * @param prevNodePtr the pointer to the previous node
         **/
        void setPrevious(DoubleNode<T> *prevNodePtr);
        /**
         * Set nodes next pointer to the passed pointer
         * @param nextNodePtr the pointer to the next node
         **/
        void setNext(DoubleNode<T> *nextNodePtr);
        //getter functions
        /**
         * @return the current item inside the node
        **/
        T getItem() const;
        /*
         * @return a pointer to the next node
        **/
        DoubleNode<T>* getNext() const;
        /**
         * @return a pointer to the previous node
        **/
        DoubleNode<T>* getPrevious() const;
};
#include "DoubleNode.cpp"
#endif
