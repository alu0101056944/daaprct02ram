/**
 * @file InstructionTranslator.h
 * @author 
 * @brief Keeps the instruction execution order of the program.
 * 
 * @version 0.1
 * @date 2022-03-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef INSTRUCTIONTRANSLATOR_H
#define INSTRUCTIONTRANSLATOR_H

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class InstructionsTable {
public:
  InstructionsTable(string filePath);

  /**
   * @brief To be used by RAM to get the next instruction of the program.
   */
  vector<string> nextInstruction();

  /**
   * @brief Jump instructions call this to change the next instruction.
   * @param label Label on source code
   */
  void jump(string label);
private:
  int currentLineOfCodeInExecution;
  vector<string> savedProgram;
  map<string, int> labelLocations;

  // Constructor functions
  void readFile(string filePath);
  void cleanSavedProgram();
  
  // Following functions are auxiliary of cleanSavedProgram()
  void extractLabelFromLine(int lineNumber, string &lineOfCode);
  void removeCommentsFrom(string &lineOfCode);
  void leftTrim(string& s);
  void rightTrim(string& s);
  void toLowerCase(string& line);

  // Auxiliary function of nextInstruction()
  vector<string> parseVectorOfOperatorsFrom(string instruction);
};

#endif
