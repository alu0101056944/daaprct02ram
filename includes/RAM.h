#ifndef RAM_H
#define RAM_H

#include <iostream>

#include "instructions_table.h"
#include "RAMInput.h"
#include "RAMOutput.h"
#include "Memory.h"
#include "Instructions/Instruction.h"

using namespace std;

class RAM {
public:
  RAM(string programPath, string inputPath, string outputPath);

  /**
   * @brief For Strategy pattern. Sets the final instruction to execute.
   */
  void chooseInstruction(vector<string> instructionArgs);

  /**
   * @brief Execute a single instruction.
   */
  void executeInstruction();

  /**
   * @brief Execute the whole program directly.
   */
  void executeProgram();

  /**
   * @brief To check if it's still executing or on halt. Main menu uses this.
   */
  bool hasFinishedExecution();

  void printInput();
  void printOutput();
  void printInstructionAmount();
  void printMemoryRegisters();
  void printCurrentInstructionInfo();
private:
  int numberOfInsExecuted;
  bool halt;
  Instruction* ptrLatestExecutedInstruction;

  InstructionsTable instructionsTable;
  Memory memory;
  RAMInput input;
  RAMOutput output;
  
  /**
   * @brief Auxiliary function of executeFunction(). Executes the instruction
   *    and check if it was successful. Halt otherwise.
   */
  void interpretInstruction();

  /**
   * @brief Auxiliary function of chooseFuncton(). Sets the pointer to the new
   *    instruction.
   */
  void setCurrentInstruction(Instruction* ptrCurrentInstruction);
};


#endif