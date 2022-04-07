#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

//include files
#include "Syntax.h"
#include <iostream>
#include <fstream>

using namespace std;

class FileProcessor
{
  public:
    FileProcessor();
    ~FileProcessor();
    void readTextFile(string file);
    unsigned int rowCounter; //cannot be a negative number
};

#endif
