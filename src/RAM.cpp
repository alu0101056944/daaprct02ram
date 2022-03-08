#include "../includes/RAM.h"

#include <algorithm>
#include <vector>
#include <string>

#include "../includes/Instructions/InstructionLoad.h"
#include "../includes/Instructions/InstructionStore.h"
#include "../includes/Instructions/InstructionAdd.h"
#include "../includes/Instructions/InstructionSub.h"
#include "../includes/Instructions/InstructionMult.h"
#include "../includes/Instructions/InstructionDiv.h"
#include "../includes/Instructions/InstructionRead.h"
#include "../includes/Instructions/InstructionWrite.h"
#include "../includes/Instructions/InstructionHalt.h"
#include "../includes/Instructions/InstructionJump.h"
#include "../includes/Instructions/InstructionJGTZ.h"
#include "../includes/Instructions/InstructionJZero.h"

RAM::RAM(string programPath, string inputPath, string outputPath) :
    ptrLatestExecutedInstruction(nullptr),
    instructionsTable(programPath),
    memory(),
    input(inputPath),
    output(outputPath),
    numberOfInsExecuted(0),
    halt(false) {}

void RAM::chooseInstruction(vector<string> instructionArgs) {
  string opCode = instructionArgs[0];
  if (opCode.compare("load") == 0) {
    setCurrentInstruction(new InstructionLoad(instructionArgs, memory, input, output, instructionsTable));
  } else if (opCode.compare("store") == 0) {
    setCurrentInstruction(new InstructionStore(instructionArgs, memory, input, output, instructionsTable));
  } else if (opCode.compare("add") == 0) {
    setCurrentInstruction(new InstructionAdd(instructionArgs, memory, input, output, instructionsTable));
  } else if (opCode.compare("sub") == 0) {
    setCurrentInstruction(new InstructionSub(instructionArgs, memory, input, output, instructionsTable));
  } else if (opCode.compare("mul") == 0 || opCode.compare("mult") == 0) {
    setCurrentInstruction(new InstructionMult(instructionArgs, memory, input, output, instructionsTable));
  } else if (opCode.compare("div") == 0) {
    setCurrentInstruction(new InstructionDiv(instructionArgs, memory, input, output, instructionsTable));
  } else if (opCode.compare("read") == 0) {
    setCurrentInstruction(new InstructionRead(instructionArgs, memory, input, output, instructionsTable));
  } else if (opCode.compare("write") == 0) {
    setCurrentInstruction(new InstructionWrite(instructionArgs, memory, input, output, instructionsTable));
  } else if (opCode.compare("jump") == 0) {
    setCurrentInstruction(new InstructionJump(instructionArgs, memory, input, output, instructionsTable));
  } else if (opCode.compare("jgtz") == 0) {
    setCurrentInstruction(new InstructionJGTZ(instructionArgs, memory, input, output, instructionsTable));
  } else if (opCode.compare("jzero") == 0) {
    setCurrentInstruction(new InstructionJZero(instructionArgs, memory, input, output, instructionsTable));
  } else {
    setCurrentInstruction(new InstructionHalt(instructionArgs, memory, input, output, instructionsTable));
  }
}

/**
 * @brief Instantiate an Instruction object and execute it if non empty
 *    instruction was received from the instructions table.
 */
void RAM::executeInstruction() {
  vector<string> nextInstruction = instructionsTable.nextInstruction();
  if (!nextInstruction.empty()) {
    chooseInstruction(nextInstruction);
    interpretInstruction(); // execute the right instruction
    numberOfInsExecuted++;
  } else {
    halt = true;
    cerr << "There aren't more instructions to be executed." << endl;
  }
}

/**
 * @brief Auxiliary function of executeInstructions()
 * @pre ptrLatestExecutedInstruction != nullptr
 */
void RAM::interpretInstruction() {
  ptrLatestExecutedInstruction->parse();
  ptrLatestExecutedInstruction->execute();
  if (!ptrLatestExecutedInstruction->successful()) {
    cout << ptrLatestExecutedInstruction->errorMessage() << endl;
    cout << "On instruction number " << numberOfInsExecuted << endl;
    ptrLatestExecutedInstruction->print();
    halt = true;
  }
}

void RAM::executeProgram() {
  while(!hasFinishedExecution()) {
    executeInstruction();
  }
}

void RAM::setCurrentInstruction(Instruction* ptrLatestExecutedInstructionParam) {
  delete ptrLatestExecutedInstruction;
  ptrLatestExecutedInstruction = ptrLatestExecutedInstructionParam;
}

bool RAM::hasFinishedExecution() {
  return halt;
}

void RAM::printInput() {
  input.printInput();
}

void RAM::printOutput() {
  output.printOutput();
}

void RAM::printMemoryRegisters() {
  memory.printMemory();
}

void RAM::printInstructionAmount() {
  cout << "Amount of instructions executed: " << numberOfInsExecuted << endl;
}

void RAM::printCurrentInstructionInfo() {
  if(ptrLatestExecutedInstruction != nullptr) {
    ptrLatestExecutedInstruction->print();
  }
}
