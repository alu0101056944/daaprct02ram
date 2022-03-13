#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <vector>

using namespace std;

class Memory {
public:
  Memory();

  /**
   * Access a register by its direction
   */
  int getRegister(int dir, int indexOfVector = 0);
  
  /**
   * Set a registers value
   */
  void setRegister(int value, int dir, int indexOfVector = 0);

  void printMemory();
private:
  vector<vector<int>> registers;
};


#endif