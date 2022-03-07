#include "../../includes/Instructions/InstructionJump.h"

#include <string>
#include <sstream>

InstructionJump::InstructionJump(
    vector<string> args,
    Memory& mem,
    RAMInput& input,
    RAMOutput& output,
    InstructionTranslator& insTranslator
  ) : 
    Instruction(args, mem, input, output, insTranslator) {}

void InstructionJump::parse() {}

void InstructionJump::execute() {
  insTranslator.jump(args[1]);
}

bool InstructionJump::successful() {
  return true; //cant go wrong
}

string InstructionJump::errorMessage() {
  return "no error";
}