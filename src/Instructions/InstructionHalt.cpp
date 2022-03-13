#include "../../includes/Instructions/InstructionHalt.h"

#include <string>
#include <sstream>

InstructionHalt::InstructionHalt(
    vector<string> args,
    Memory& mem,
    RAMInput& input,
    RAMOutput& output,
    InstructionsTable& insTranslator
  ) : 
    Instruction(args, mem, input, output, insTranslator) {}

void InstructionHalt::execute() {}

void InstructionHalt::parse() {}

bool InstructionHalt::successful() {
  return true; //cant go wrong
}

string InstructionHalt::errorMessage() {
  return "Error: Halted instruction didn't execute right.";
}