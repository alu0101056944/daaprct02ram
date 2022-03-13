#include "../includes/Memory.h"

#include <iostream>

Memory::Memory() : registers() {}

int Memory::getRegister(int dir, int indexOfVector) {
  if (dir >= (registers.size())) {
    registers.resize(dir + 1);
  }
  return registers[dir][indexOfVector];
}

void Memory::setRegister(int value, int dir,
    int indexOfVector) {
  if (dir >= (registers.size())) {
    registers.resize(dir + 1);
  }
  if (indexOfVector >= registers[dir].size()) {
    registers[dir].resize(indexOfVector + 1);
  }
  registers[dir][indexOfVector] = value;
}

void Memory::printMemory() {
  cout << endl << "-- Memory: " << registers.size() << " elements." << endl;
  for (int i = 0; i < registers.size(); i++) {
    cout << "c(" << i << ") = ";
    for (int j = 0; j < registers[i].size(); j++) {
      cout << registers[i][j];
      if(j != (registers[i].size() - 1)){
        cout << ", ";
      } else {
        cout << endl;
      }
    }
  }
  cout << endl;
}