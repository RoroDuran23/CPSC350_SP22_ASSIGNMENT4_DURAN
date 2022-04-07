//include files
#include "FileProcessor.h"
#include <exception>
#include <string>

//default constructor
FileProcessor::FileProcessor()
{
  rowCounter = 1;
}

//garbage collector
FileProcessor::~FileProcessor()
{

}

//iterate through file per line
void FileProcessor::readTextFile(string file)
{
  fstream mapFile;
  string line;

  Syntax <char> syn; //instantiate
  int itWorked = 0; //counter

  //for reading file
  mapFile.open(file, ios::in);  //opens the stream to read from
  if(mapFile.is_open()) //check if opened
  {
    while(getline(mapFile, line)) //while there is a line in the file
    {
      if(syn.AreDelimetersBalanced(line)){ //if true
        itWorked++;
      }
      else{
        cout << " -> Go check line ";
        cout << rowCounter;
        cout << ".\n\n";
        itWorked--;
        break;
      }
      rowCounter++; //increase counter
    }
  }

  else
    throw runtime_error("File not found");

  mapFile.close(); //close file
  if(itWorked == rowCounter-1) //if all good
    cout << "\nEverything worked, no need to change anything!\n" << endl;

}
