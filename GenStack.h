#ifndef GENSTACK_H
#define GENSTACK_H

//include files
#include "LinkedList.h"

//create a template class
template <typename T> class GenStack{
  public:
    GenStack();
    ~GenStack();
    DoublyLinkedList <T> *stack; //specific place in memory, type DoublyLinkedList
    //stack functions
    T push(T data);
    T pop();
    bool isEmpty();
};


template <typename T> GenStack<T>::GenStack(){
  stack = new DoublyLinkedList<T>();
}

template <typename T> GenStack<T>::~GenStack(){
  //delete//garbage collect doubly linked list
}

template <typename T> T GenStack<T>::push(T data){
  stack->insertBack(data);
}

template <typename T> T GenStack<T>::pop(){
  stack->removeBack();
}

template <typename T> bool GenStack<T>::isEmpty(){
  stack->isEmpty();
}

#endif
