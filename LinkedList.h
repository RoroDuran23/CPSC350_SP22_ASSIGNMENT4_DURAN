#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//include files
#include <iostream>
#include <exception>

using namespace std;

//template class
template<typename T> class ListNode{
  public:
    ListNode();
    ListNode(T d);
    ~ListNode();
    ListNode *next;
    ListNode *prev;
    T data;
};

//implementation
template<typename T> ListNode<T>::ListNode(){
}

//a list node with value = data of type T
template <typename T> ListNode<T>::ListNode(T d){
  data = d;
  next = NULL;
  prev = NULL;
}

template <typename T> ListNode<T>::~ListNode(){
}

//doublylinked list class
template <typename T> class DoublyLinkedList{
  private:
    ListNode<T> *front;
    ListNode<T> *back;
    unsigned int size;
  public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    //functions
    void insertFront(T d);
    void insertBack(T d);
    T removeFront();
    T removeBack();
    T removeNode(T value);
    T find (T value);
    bool isEmpty();
    unsigned int getSize();
    void printList(bool isPrintLink);
    T peek();


};

template <typename T> DoublyLinkedList<T>::DoublyLinkedList(){
  front = NULL;
  back = NULL;
  size = 0;
}

template <typename T> DoublyLinkedList<T>::~DoublyLinkedList(){
  //guess what??? build some character and research
    //thank you Rene
    
  ListNode <T> *node = front;
  ListNode <T> *nodeToDelete = front;
  while(node != NULL){
    nodeToDelete = node -> next;
    delete node;
    node = nodeToDelete;
  }
}

template <typename T> T DoublyLinkedList<T>::peek(){
  //make sure stack is not empty before proceeding
  if(isEmpty()){
    throw runtime_error("stack is empty");
  }
  return back->data;
}

template <typename T> void DoublyLinkedList<T>::insertFront(T d){
  ListNode <T> * node = new ListNode <T> (d);

  if(isEmpty()){
    back = node;
  }
  else{
    //if it's not isEmpty
    node -> next = front;
    front -> prev = node;
  }
  front = node;
  ++size;
}

template <typename T> void DoublyLinkedList<T>::insertBack(T d){
  ListNode <T> * node = new ListNode <T> (d);

  if(isEmpty()){
    front = node;
  }
  else{
    //if it's not isEmpty
    node -> prev = back;
    back -> next = node;
  }
  back = node;
  ++size;
}

template <typename T> T DoublyLinkedList<T>::removeFront(){
  if(isEmpty()){
    throw runtime_error("list is empty!");
  }

  ListNode<T> *temp = front;

  if(front -> next == NULL){
    back = NULL;
  }
  else{
    //more than one mode in the List
    front ->next->prev = NULL;
  }
  front = front -> next;
  temp -> next = NULL;
  int data = temp -> data;
  --size;
  delete temp;
  return data;
}

template <typename T> T DoublyLinkedList<T>::removeBack(){
  if(isEmpty()){
    throw runtime_error("list is empty");
  }

    ListNode<T> *temp = back;

    if(back -> prev == NULL){
      //only node in the list
      front = NULL;
    }
    else{
      //more than one mode in the List
      back ->prev->next = NULL;
    }
    back = back -> prev;
    temp -> prev = NULL;
    int data = temp -> data;
    --size;
    delete temp;
    return data;
}

template <typename T> T DoublyLinkedList<T>::find(T value){
  int pos = -1;
  ListNode <T> *curr = front;

  while(curr != NULL){
    ++pos;
    if(curr->data == value)
      break;

    curr = curr -> next;
  }
  //checks if curr is NULL which signifies value not in Linked ListNode
  if(curr == NULL)
  pos = -1;

  return pos;
}

template <typename T> T DoublyLinkedList<T>::removeNode(T value){
  if(isEmpty()){
    throw runtime_error("list is empty!");
  }

  //we could leverage the find method

  ListNode<T> *curr = front;
  while(curr->data != value){
    curr = curr -> next;

    if(curr == NULL)
      return -1;
  }
  //but if we make it here, we found the value
  //we found it, let's proceed to remove it

  if(curr != front && curr != back){
    //it's in between front and back
    curr -> prev->next = curr -> next;
    curr -> next -> prev = curr -> prev;
  }

  if (curr == front){
    front = curr -> next;
    front -> prev = NULL;
  }

  if(curr == back){
    back = curr -> prev;
    back -> next = NULL;
  }

  curr -> prev = NULL;
  int data = curr -> data;
  --size;
  delete curr;

  return data;
}

template <typename T> unsigned int DoublyLinkedList<T>::getSize(){
  return size;
}

template <typename T> bool DoublyLinkedList<T>::isEmpty(){
  return (size == 0);
}

template <typename T> void DoublyLinkedList<T>::printList(bool printLink){
  ListNode<T> *curr = front;
  while(curr != 0){
    if(curr == front){
      cout << "{FRONT}: ";
    }
    else if(curr == back){
      cout << "{BACK}: ";
    }
    else
      cout << "[ " << curr ->data << " ] ";

    curr = curr -> next;
    if(curr != 0){
      cout << " <==> ";
    }
  }
  cout << endl;
}


#endif
