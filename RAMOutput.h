#ifndef RAMOUTPUT_H
#define RAMOUTPUT_H

#include <iostream>
#include <vector>

using namespace std;

class RAMOutput {
public:
  RAMOutput(string filePathParam);

  /**
    * Writes value and then offsets to the next position
    */
  void writeValue(int value);

  void printOutput();
private:
  vector<int> registers;
  int offset;
  string filePath;
  
  /**
    * So that everytime this program is executed the content of the output
    * file is cleared
    */
  void deleteFileContent();

  /**
    * Writes a value to the file
    */
  void writeFile(int value);
};


#endif