#include "../../includes/Instructions/InstructionRead.h"

#include <string>
#include <sstream>

InstructionRead::InstructionRead(
    vector<string> args,
    Memory& mem,
    RAMInput& input,
    RAMOutput& output,
    InstructionsTable& insTranslator
  ) : 
    Instruction(args, mem, input, output, insTranslator),
    obtainedValue(0) {}

void InstructionRead::execute() {
  if (successful()) {
    memory.setRegister(input.readValue(), operatorNumericValue);
  }
}

bool InstructionRead::successful() {
  if (operatorNumericValue <= 0) { // por requisito
    return false;
  }
  return true;
}

string InstructionRead::errorMessage() {
  return "Fallo en la instrucción Read.";
}