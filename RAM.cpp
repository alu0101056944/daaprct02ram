#include "RAM.h"

#include <algorithm>
#include <vector>
#include <string>

#include "Instructions/InstructionLoad.h"
#include "Instructions/InstructionStore.h"
#include "Instructions/InstructionAdd.h"
#include "Instructions/InstructionSub.h"
#include "Instructions/InstructionMult.h"
#include "Instructions/InstructionDiv.h"
#include "Instructions/InstructionRead.h"
#include "Instructions/InstructionWrite.h"
#include "Instructions/InstructionHalt.h"
#include "Instructions/InstructionJump.h"
#include "Instructions/InstructionJGTZ.h"
#include "Instructions/InstructionJZero.h"

RAM::RAM(string programPath, string inputPath, string outputPath) :
    ptrLatestExecutedInstruction(nullptr),
    io(programPath),
    insTranslator(io.readFile()),
    isa(),
    memory(),
    input(inputPath),
    output(outputPath),
    numberOfInsExecuted(0),
    halt(false) {}

void RAM::printHelp() {
  cout << endl << "r: Imprime los valores almacenados en la memoria. " << 
      "El formato es el siguiente: " << endl <<
      "Memory: <size> elements." << endl <<
      "dir 1: <value1>, dir 2: <value2>, dir 3: <value3>," << endl <<
      "dir 4: <value4>, ... , dir i: <valuei>" << endl;
  cout << "t: Mostrar las instrucciones ejecutadas hasta ahora." << endl;
  cout << "e: ejecutar la siguiente instruccion. " << endl;
  cout << "s: " << endl;
  cout << "i: Imprime en pantalla el estado actual de la cinta de entrada" << endl;
  cout << "o: Imprime en pantalla el estado actua lde la cinta de salida" << endl;
}

void RAM::printInput() {
  input.printInput();
}

void RAM::printOutput() {
  output.printOutput();
}

void RAM::printRegisters() {
  memory.printMemory();
}

void RAM::printTrace() {
  insTranslator.printTranslatedInstructions();
}

void RAM::printInstructionAmount() {
  cout << "Amount of instructions executed: " << numberOfInsExecuted << endl;
}

void RAM::printCurrentInstruction() {
  if (ptrLatestExecutedInstruction != nullptr) {
    ptrLatestExecutedInstruction->print();
  }
}

//CAMBIARLO PARA QUE CONTINUE MIENTRAS DEVUELVA SIZE 0 Y SIGAN HABIENDO INSTRUCCIONES

/**
 * Obtain and execute the next valid instruction on the source file
 */
void RAM::executeInstruction() {
  vector<string> nextInstruction;
  // next instruction obtained from translator may be unsuited or empty, 
  // obtain more instructions until one is valid and while there are
  // instructions available
  while (nextInstruction.empty() && insTranslator.moreInstructions()) {
    nextInstruction = insTranslator.nextInstruction();
    if (!nextInstruction.empty()) { // valid ins found
      string opCode = nextInstruction.at(0);
      interpretInstruction(nextInstruction); // execute the right instruction
      numberOfInsExecuted++;
    }
  }
}

                                            //CAMBIAR VALORES CABLEADOS POR CONSTANTES
                                            //DISSASEMBLE = OBTENER LA IMPLEMENTACION DE LA INSTRUCCION EN FORMA DE TEXTO

/**
 * @brief Auxiliary function of executeInstructions()
 * instructionArgs cant be empty because it is checked beforehand.
 */
void RAM::interpretInstruction(vector<string> instructionArgs) {
  string opCode = instructionArgs[0];
  if (opCode.compare("load") == 0) {
    setCurrentInstruction(new InstructionLoad(instructionArgs, memory, input, output, insTranslator));
  } else if (opCode.compare("store") == 0) {
    setCurrentInstruction(new InstructionStore(instructionArgs, memory, input, output, insTranslator));
  } else if (opCode.compare("add") == 0) {
    setCurrentInstruction(new InstructionAdd(instructionArgs, memory, input, output, insTranslator));
  } else if (opCode.compare("sub") == 0) {
    setCurrentInstruction(new InstructionSub(instructionArgs, memory, input, output, insTranslator));
  } else if (opCode.compare("mult") == 0) {
    setCurrentInstruction(new InstructionMult(instructionArgs, memory, input, output, insTranslator));
  } else if (opCode.compare("div") == 0) {
    setCurrentInstruction(new InstructionDiv(instructionArgs, memory, input, output, insTranslator));
  } else if (opCode.compare("read") == 0) {
    setCurrentInstruction(new InstructionRead(instructionArgs, memory, input, output, insTranslator));
  } else if (opCode.compare("write") == 0) {
    setCurrentInstruction(new InstructionWrite(instructionArgs, memory, input, output, insTranslator));
  } else if (opCode.compare("jump") == 0) {
    setCurrentInstruction(new InstructionJump(instructionArgs, memory, input, output, insTranslator));
  } else if (opCode.compare("jgtz") == 0) {
    setCurrentInstruction(new InstructionJGTZ(instructionArgs, memory, input, output, insTranslator));
  } else if (opCode.compare("jzero") == 0) {
    setCurrentInstruction(new InstructionJZero(instructionArgs, memory, input, output, insTranslator));
  } else { // halt
    setCurrentInstruction(new InstructionHalt(instructionArgs, memory, input, output, insTranslator));
    halt = true;
  }

  ptrLatestExecutedInstruction->parse();
  ptrLatestExecutedInstruction->execute();
  if (!ptrLatestExecutedInstruction->successful()) {
    cout << ptrLatestExecutedInstruction->errorMessage() << endl;
    cout << "On instruction number " << numberOfInsExecuted << endl;
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