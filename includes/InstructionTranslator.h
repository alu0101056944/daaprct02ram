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

class InstructionTranslator {
public:
  InstructionTranslator(string filePath);

  /**
   * Meant for trace implementation.
   */
  void printTranslatedInstructions();

  /**
   * Checks for proper syntaxis and then translates the next instruction
   *  in the program.
   */
  vector<string> nextInstruction();

  /**
   * @returns false if there are no more instructions to be executed
   */
  bool moreInstructions();

  /**
   * Jump to previously saved label location
   * @param label Label on source code
   */
  void jump(string label);
private:
  string filePath_;
  bool moreIns;
  int programCounter, currentLine;
  vector<string> savedProgram;
  map<string, int> labelLocations;

  void readFile();

  void toLowerCase(string& line);

  /**
   * Find and save all the labels on the source code.
   */
  void setLabels();

  /**
   * Used each line of the program
   * @param instruction to be parsed
   */
  vector<string> parseInstructionFields(string instruction);
};


#endif