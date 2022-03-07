#ifndef RAMINPUT_H
#define RAMINPUT_H

#include <iostream>
#include <vector>

using namespace std;

class RAMInput {
public:
  RAMInput(string filePathParam);

  /**
   * @returns -1 if couldnt read from the input
   */
  int readValue();

  void printInput();
private:
  vector<int> registers;
  int offset;

  void readFile(string filePath);
};


#endif