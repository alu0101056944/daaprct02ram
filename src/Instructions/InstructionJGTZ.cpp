#include "../../includes/Instructions/InstructionJGTZ.h"

#include <string>
#include <sstream>

InstructionJGTZ::InstructionJGTZ(
    vector<string> args,
    Memory& mem,
    RAMInput& input,
    RAMOutput& output,
    InstructionsTable& insTranslator
  ) : 
    Instruction(args, mem, input, output, insTranslator) {}

void InstructionJGTZ::parse() {}

void InstructionJGTZ::execute() {
  if (memory.getRegister(0) > 0) {
    insTranslator.jump(args[1]);
  }
}

bool InstructionJGTZ::successful() {
  return true; //cant go wrong
}

string InstructionJGTZ::errorMessage() {
  return "no error";
}