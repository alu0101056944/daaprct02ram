#include "InstructionSub.h"

#include <string>
#include <sstream>

InstructionSub::InstructionSub(
    vector<string> args,
    Memory& mem,
    RAMInput& input,
    RAMOutput& output,
    InstructionTranslator& insTranslator
  ) : 
    Instruction(args, mem, input, output, insTranslator),
    obtainedValue(0) {}

void InstructionSub::parse() {
  passedValue = parseValue(args[1]);
}

void InstructionSub::execute() {
  if (successful()) {
    memory.setRegister(obtainedValue, 0);
  }
}

bool InstructionSub::successful() {
  if (passedValue < 0) {
    return false;
  }
  
  if (!successfulChecked) {
    obtainedValue = memory.getRegister(0) - memory.getRegister(passedValue);
    cout << endl << "memory.getRegister(0) = " << memory.getRegister(0) << " , passe: " << memory.getRegister(passedValue);
    successfulChecked = true;
  }
  return obtainedValue >= 0;
}

string InstructionSub::errorMessage() {
  if (passedValue < 0) {
    return "Error: passed value negative";
  }
  return "Error: Obtained value negative";
}