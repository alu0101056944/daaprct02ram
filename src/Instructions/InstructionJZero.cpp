#include "../../includes/Instructions/InstructionJZero.h"

#include <string>
#include <sstream>

InstructionJZero::InstructionJZero(
    vector<string> args,
    Memory& mem,
    RAMInput& input,
    RAMOutput& output,
    InstructionsTable& insTranslator
  ) : 
    Instruction(args, mem, input, output, insTranslator) {}

void InstructionJZero::parse() {}

void InstructionJZero::execute() {
  if (memory.getRegister(0) == 0) {
    insTranslator.jump(args[1]);
  }
}

bool InstructionJZero::successful() {
  return true; //cant go wrong
}

string InstructionJZero::errorMessage() {
  return "no error";
}