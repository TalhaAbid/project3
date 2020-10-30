#include "DoubleNode.hpp"

template<typename T>
DoubleNode<T>::DoubleNode(): item_(T()), next_(nullptr),prev_(nullptr){ 
}

template<typename T>
DoubleNode<T>::DoubleNode(T anItem):
    item_(anItem), next_(nullptr), prev_(nullptr) {   
}


template<typename T>
DoubleNode<T>::DoubleNode(T& anItem, DoubleNode<T>* nextNodePtr, DoubleNode<T>* prevNodePtr):
    item_(anItem), next_(nextNodePtr), prev_(prevNodePtr) {   
}

template<typename T>
void DoubleNode<T>::setItem(const T &anItem){
   item_ = anItem; 
}


template<typename T>
void DoubleNode<T>::setPrevious(DoubleNode<T>* prevNodePtr){
    prev_ = prevNodePtr;
}

template<typename T>
void DoubleNode<T>::setNext(DoubleNode<T>* nextNodePtr){
    next_ = nextNodePtr;
}

template<typename T>
T DoubleNode<T>::getItem() const{
    return item_;
}

template<typename T>
DoubleNode<T>* DoubleNode<T>::getNext() const{
    return next_;
}

template<typename T>
DoubleNode<T>* DoubleNode<T>::getPrevious() const{
    return prev_;
}
