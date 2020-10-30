#include "DoublyLinkedList.hpp"

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(): headPtr(nullptr), listSize(0){
//set headPtr to nullptr
//set listSize = 0 signifying 0 items
}


template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>* aList){
    DoublyLinkedList<T> newList;
    int pos = 1;
    while (pos != aList->listSize){
        newList.insert(aList->getAtPos(pos)->getItem(), pos);
    }
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    clear();
}

template<typename T>
void DoublyLinkedList<T>::clear(){
    for (int i = 1; i <= listSize; i++){
        remove(i);
    }
}

template<typename T>
bool DoublyLinkedList<T>::remove(const int &position){
    if (isEmpty()){
        return false;
    }
    if (position == 1){
        DoubleNode<T>* oldHeadPtr = headPtr;
        DoubleNode<T>* newHeadPtr = headPtr->getNext();
        newHeadPtr->setPrevious(nullptr);
        headPtr = newHeadPtr;
        delete oldHeadPtr;
        oldHeadPtr = nullptr;
        listSize--;
        return true;
    }
    return true;
}

template<typename T>
bool DoublyLinkedList<T>::insert(const T &item, const int &position){
    if (position == 1){
        DoubleNode<T>* newHeadPtr = new DoubleNode<T>(item);
        DoubleNode<T>* prevHeadPtr = headPtr;
        newHeadPtr->setNext(prevHeadPtr);
        newHeadPtr->setPrevious(nullptr);
        prevHeadPtr->setPrevious(newHeadPtr);
        headPtr == newHeadPtr;
        listSize++;
        return true;
    }else if (position == listSize+1){
        DoubleNode<T>* newEnd = new DoubleNode<T>(item);
        DoubleNode<T>* oldEnd = getAtPos(listSize);
        oldEnd->setNext(newEnd);
        newEnd->setPrevious(oldEnd);
        newEnd->setNext(nullptr);
        listSize++;
        return true;
    }else {
        DoubleNode<T>* newAtPos = new DoubleNode<T>(item);
        DoubleNode<T>* prevAtPos = getAtPos(position);
        newAtPos->setPrevious(prevAtPos->getPrevious());
        newAtPos->setNext(prevAtPos);
        prevAtPos->setPrevious(newAtPos);
        listSize++;
        return true;
    }
    return false;
}
template<typename T>
bool DoublyLinkedList<T>::isEmpty() const {
    return listSize == 0;
}

template<typename T>
void DoublyLinkedList<T>::display() const {
    DoubleNode<T>* currNode = headPtr;
    if (currNode == nullptr){
        return;
    }
    while (currNode != nullptr){
        std::cout << currNode->getItem() << " ";
        currNode = currNode->getNext();
    }
}

template<typename T>
void DoublyLinkedList<T>::displayBackwards() const {
    DoubleNode<T>* currNode = getAtPos(listSize);
    while (currNode != nullptr){
        std::cout << currNode->getItem() << " ";
        currNode = currNode->getPrevious();
    }
}


template<typename T>
int DoublyLinkedList<T>::getSize() const {
    return listSize;
}


template<typename T>
DoubleNode<T>* DoublyLinkedList<T>::getHeadPtr() const{
    return headPtr;
}


template<typename T>
DoubleNode<T>* DoublyLinkedList<T>::getAtPos(const int &pos) const {
    int i = 1;
    DoubleNode<T>* currNode = headPtr;
    while(currNode != nullptr){
        if (i == pos){
            return currNode;
        }
        currNode = currNode->getNext();
        i++;
    }
    return currNode;
}

template<typename T>
DoublyLinkedList<T> DoublyLinkedList<T>::interleave(const DoublyLinkedList<T> &a_list){
    int currPos = 1;
    int i = 1;
    DoublyLinkedList<T> newList;
    int sizeList1 = this->listSize;
    int sizeList2 = a_list.getSize();
    if (sizeList1 - sizeList2 == 0){
        while (i != sizeList1 + sizeList2){
            if (i % 2 != 0 ){
                newList.insert(getAtPos(currPos)->getItem(), i);
                i++;
            } else {
                newList.insert(a_list.getAtPos(currPos)->getItem(), i);
                i++;
                currPos++;
            }
        }
    } else {
        if (sizeList1 > sizeList2){
            while (i != sizeList2*2){
                if (i % 2 != 0 ){
                    newList.insert(getAtPos(currPos)->getItem(), i);
                    i++;
                } else {
                    newList.insert(getAtPos(currPos)->getItem(), i);
                    i++;
                    currPos++;
                }
           } 
            while (i != sizeList1){
                newList.insert(getAtPos(currPos)->getItem(), i);
                i++;
                currPos++;
            }
        } else{
            while (i != sizeList1*2){
                if (i % 2 != 0 ){
                    newList.insert(getAtPos(currPos)->getItem(), i);
                    i++;
                } else {
                newList.insert(a_list.getAtPos(currPos)->getItem(), i);
                    i++;
                    currPos++;
                }
            }
            while (i != sizeList2){
                newList.insert(a_list.getAtPos(currPos)->getItem(), i);
                i++;
                currPos++;
            }
        }
    }
    return newList;
}
