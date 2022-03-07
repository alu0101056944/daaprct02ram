#include "../includes/RAMInput.h"

#include <fstream>
#include <sstream>

RAMInput::RAMInput(string filePathParam) : registers(), offset(0) {
    readFile(filePathParam);
}

int RAMInput::readValue() {
  if(registers.size() > 0 && offset < registers.size()) {
    offset++;
    return registers.at((offset-1));
  }
  return -1;
}

void RAMInput::printInput() {
  cout << endl << "-- Input: " << endl;
  for (int i = 0; i < registers.size(); i++) {
    cout << registers.at(i);
    if (i==offset) {
      cout << "(HERE)";
    }
    if(i != (registers.size() - 1)){
      cout << ", ";
    }
  }
  cout << endl;
}

void RAMInput::readFile(string filePathParam) {
  ifstream inFile(filePathParam);

  string line;
  while (getline(inFile, line)) {
    if(line.length() > 0){ // solo si no es una linea vacia
      stringstream cadena(line); 
      int valorNumerico = 0;
      cadena >> valorNumerico; // pasamos string a int

      registers.push_back(valorNumerico);
    }
  }
}