#include "InstructionAdd.h"

#include <string>
#include <sstream>

InstructionAdd::InstructionAdd(
    vector<string> args,
    Memory& mem,
    RAMInput& input,
    RAMOutput& output,
    InstructionTranslator& insTranslator
  ) : 
    Instruction(args, mem, input, output, insTranslator),
    result(0) {}

void InstructionAdd::parse() {
  passedValue = parseValue(args[1]);
}

void InstructionAdd::execute() {
  if (successful()) {
    memory.setRegister(result, 0);
  }
}

bool InstructionAdd::successful() {
  if (passedValue < 0) {
    return false;
  }

  if (!successfulChecked) {
    result = memory.getRegister(0) + memory.getRegister(passedValue);
    successfulChecked = true;
  }
  return result >= 0;
}

string InstructionAdd::errorMessage() {
  return "Error: result < 0";
}