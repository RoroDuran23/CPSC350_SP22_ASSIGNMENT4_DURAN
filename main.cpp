//include files
#include <iostream>
#include "GenStack.h"
#include "LinkedList.h"
#include "FileProcessor.h"

int main(int argc, char **argv)
{
  FileProcessor fp; //instantiate fp
  string inputIn;

  //set variables to command line
  inputIn = argv[1];
  //use the function
  fp.readTextFile(inputIn);
}
