#include "../includes/RAMOutput.h"

#include <fstream>
#include <sstream>

RAMOutput::RAMOutput(string filePathParam) :
    registers(),
    offset(0),
    filePath(filePathParam) {
  deleteFileContent();
}

void RAMOutput::writeValue(int value) {
  registers.push_back(value);
  writeFile(value);
}

void RAMOutput::printOutput() {
  cout << endl << "-- Output: " << endl;
  for (int i = 0; i < registers.size(); i++) {
    cout << registers.at(i);
    if(i != (registers.size() - 1)){
      cout << ", ";
    }
  }
  cout << endl;
}

void RAMOutput::deleteFileContent(){
  std::ofstream ofs;
  ofs.open(filePath, std::ofstream::out | std::ofstream::trunc); // cleared when truncated
  ofs.close();
}

void RAMOutput::writeFile(int value){
  ofstream inFile;
  inFile.open(filePath, std::ios::app); // should append at the end of the file
  inFile << value << "\n";
  inFile.close();
}