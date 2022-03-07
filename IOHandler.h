#ifndef IOHANDLER_H
#define IOHANDLER_H

#include <iostream>
#include <vector>

using namespace std;

class IOHandler {
public:
  IOHandler(string filePath);

  /**
   * Read all lines from the file
   */
  vector<string> readFile();
  void printFile();
private:
  string filePath;
  vector<string> lines;
  int numberOfLines;
};


#endif