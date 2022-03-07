#include "Memory.h"

#include <iostream>

Memory::Memory() : registers() {}

int Memory::getRegister(int dir) {
  if (dir >= (registers.size())) {
    registers.resize(dir + 1);
  }
  return registers.at(dir);
}

void Memory::setRegister(int value, int dir) {
  if (dir >= (registers.size())) {
    registers.resize(dir + 1);
  }
  registers[dir] = value;
}

void Memory::printMemory() {
  cout << endl << "-- Memory: " << registers.size() << " elements." << endl;
  for (int i = 0; i < registers.size(); i++) {
    cout << "c(" << i << ") = " << registers.at(i);
    if(i != (registers.size() - 1)){
      cout << ", " << endl;
    }
  }
  cout << endl;
}