#ifndef RAM_H
#define RAM_H

#include <iostream>

#include "IOHandler.h"
#include "InstructionTranslator.h"
#include "RAMInput.h"
#include "RAMOutput.h"
#include "Memory.h"
#include "Instructions/Instruction.h"

using namespace std;

class RAM {
public:
  RAM(string programPath, string inputPath, string outputPath);

  void printHelp();
  void printInput();
  void printOutput();
  void printInstructionAmount();
  void printCurrentInstruction();
  void printRegisters();
  void printTrace();
  void executeInstruction();
  void executeProgram();
  bool hasFinishedExecution();
private:
  vector<string> isa; // list of executable instruction codes
  int numberOfInsExecuted;
  Instruction* ptrLatestExecutedInstruction;

  IOHandler io;
  InstructionTranslator insTranslator;
  Memory memory;
  RAMInput input;
  RAMOutput output;
  
  bool halt;

  /**
   * Set the instruction set architecture including only the instruction codes
   */
  void initializeISA();

  /**
   * Executes the right instruction depending on the opCode
   */
  void interpretInstruction(vector<string> instructionArgs);

  /**
   * Dynamically changes current instruction to be executed
   */
  void setCurrentInstruction(Instruction* ptrCurrentInstruction);
};


#endif