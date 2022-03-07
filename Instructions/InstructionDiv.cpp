#include "InstructionDiv.h"

#include <string>
#include <sstream>

InstructionDiv::InstructionDiv(
    vector<string> args,
    Memory& mem,
    RAMInput& input,
    RAMOutput& output,
    InstructionTranslator& insTranslator
  ) : 
    Instruction(args, mem, input, output, insTranslator) {}

void InstructionDiv::parse() {
  passedValue = parseValue(args[1]);
}

void InstructionDiv::execute() {
  if (successful()) {
    memory.setRegister(memory.getRegister(0) / + memory.getRegister(passedValue), 0);
  }
}

bool InstructionDiv::successful() {
  if (passedValue < 0) {
    return false;
  }
  return memory.getRegister(passedValue) > 0;
}

string InstructionDiv::errorMessage() {
  return "Error: divide by 0";
}