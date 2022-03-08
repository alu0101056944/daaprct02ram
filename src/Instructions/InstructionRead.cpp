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

void InstructionRead::parse() {
  passedValue = parseValue(args[1]);
  setAddressTypeFlags();
}

void InstructionRead::execute() {
  if (successful()) {
    memory.setRegister(input.readValue(), passedValue);
  }
}

bool InstructionRead::successful() {
  if (passedValue <= 0) { // por requisito
    return false;
  }
  return true;
}

string InstructionRead::errorMessage() {
  return "Fallo en la instrucción Read.";
}