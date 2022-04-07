#ifndef SYNTAX_H
#define SYNTAX_H

//include files
#include "GenStack.h"

//create a template class
template <typename T> class Syntax{
  public:
    Syntax(); //constructor
    ~Syntax(); //garbage collector
    GenStack <T> *gs; //instantiate a genstack
    bool AreDelimetersBalanced(string str); //set function
};

template <typename T> Syntax<T>::Syntax(){
}

template <typename T> Syntax<T>::~Syntax(){

}

template <typename T> bool Syntax<T>::AreDelimetersBalanced(string str){
  //set variables
  gs = new GenStack<T>();
  T t;

  for(int i = 0; i < str.length(); ++i){ //iterate through string
    //if it's part of the punctuation
    if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
      gs->push(str[i]); //add punctuation to the stack   -> maybe need to add "peek", "getFront"
      continue;
    }

    //if the genStack is empty
    if(gs->isEmpty()){
      return false;
    }

    //create a switch statement for the each specific character in the line
    switch (str[i]){

      //check each of the delimeters
      case ')':
        t = gs->pop();

        //if not the matching-delimeters
        if (t == '{' || t == '['){
          cout << "\nIt should be ";
          cout << str[i];
          cout << " instead of ";
          cout << t;
          return false;
        }
        break;

      case ']':
        t = gs->pop();

        if (t == '(' || t == '{'){
          cout << "\nIt should be ";
          cout << str[i];
          cout << " instead of ";
          cout << t;
          return false;
        }
        break;

      case '}':
        t = gs->pop();

        if (t == '(' || t == '['){
          cout << "\nIt should be ";
          cout << str[i];
          cout << " instead of ";
          cout << t;
          return false;
        }
        break;
    }
  }
  //if stack is not empty we need a closing-delimeter
  if(!gs->isEmpty()){
    cout << "\nMissing a closing delimeter";
  }
  //return bool
  return (gs->isEmpty());
}

#endif
