#include "InstructionMult.h"

#include <string>
#include <sstream>

InstructionMult::InstructionMult(
    vector<string> args,
    Memory& mem,
    RAMInput& input,
    RAMOutput& output,
    InstructionTranslator& insTranslator
  ) : 
    Instruction(args, mem, input, output, insTranslator),
    obtainedValue(0) {}

void InstructionMult::parse() {
  passedValue = parseValue(args[1]);
}

void InstructionMult::execute() {
  if (successful()) {
    memory.setRegister(memory.getRegister(0) * obtainedValue, 0);
  }
}

bool InstructionMult::successful() {
  if (passedValue < 0) {
    return false;
  }
  
  if (!successfulChecked) {
    obtainedValue = memory.getRegister(passedValue);
    successfulChecked = true;
  }
  return obtainedValue >= 0;
}

string InstructionMult::errorMessage() {
    return "no error";
}