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
  int getRegister(int dir);
  
  /**
   * Set a registers value
   */
  void setRegister(int value, int dir);

  void printMemory();
private:
  vector<int> registers;
};


#endif