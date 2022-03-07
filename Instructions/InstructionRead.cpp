#include "InstructionRead.h"

#include <string>
#include <sstream>

InstructionRead::InstructionRead(
    vector<string> args,
    Memory& mem,
    RAMInput& input,
    RAMOutput& output,
    InstructionTranslator& insTranslator
  ) : 
    Instruction(args, mem, input, output, insTranslator),
    obtainedValue(0) {}

void InstructionRead::parse() {
  passedValue = parseValue(args[1]);
}

void InstructionRead::execute() {
  if (successful()) {
    memory.setRegister(input.readValue(), passedValue);
  }
}

bool InstructionRead::successful() {
  return passedValue >= 0;
}

string InstructionRead::errorMessage() {
  return "no ";
}