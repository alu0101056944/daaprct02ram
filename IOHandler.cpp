#include "IOHandler.h"

#include <sstream>
#include <fstream>
#include <algorithm>

IOHandler::IOHandler(string filePath) : filePath(filePath) {}

vector<string> IOHandler::readFile() {
  ifstream inFile(filePath);
  numberOfLines = 1;
  lines.clear();
  
  string line;
  while (getline(inFile, line)) {
      lines.push_back(line);
      numberOfLines++;
  }
  return lines;
}

void IOHandler::printFile() {
  for(int i = 0; i < lines.size(); i++){
    cout << lines.at(i) << endl;
  }
}