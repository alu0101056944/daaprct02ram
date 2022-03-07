#include "../../includes/Instructions/InstructionHalt.h"

#include <string>
#include <sstream>

InstructionHalt::InstructionHalt(
    vector<string> args,
    Memory& mem,
    RAMInput& input,
    RAMOutput& output,
    InstructionTranslator& insTranslator
  ) : 
    Instruction(args, mem, input, output, insTranslator) {}

void InstructionHalt::parse() {}

void InstructionHalt::execute() {}

bool InstructionHalt::successful() {
  return true; //cant go wrong
}

string InstructionHalt::errorMessage() {
  return "no error";
}