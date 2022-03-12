#include "../../includes/Instructions/InstructionMult.h"

#include <string>
#include <sstream>

InstructionMult::InstructionMult(
    vector<string> args,
    Memory& mem,
    RAMInput& input,
    RAMOutput& output,
    InstructionsTable& insTranslator
  ) : 
    Instruction(args, mem, input, output, insTranslator),
    result(0) {}

void InstructionMult::parse() {
  passedValue = parseValue(args[1]);
  setAddressTypeFlags();
}

void InstructionMult::execute() {
  if (successful()) {
    if (isIndirectValue) { // indirect address
      result = memory.getRegister(0) *
          memory.getRegister(memory.getRegister(passedValue));
    } else if (isInmediateValue) { // inmediate address
      result = memory.getRegister(0) * passedValue;
    } else {
      result = memory.getRegister(0) * memory.getRegister(passedValue);
    }
    memory.setRegister(result, 0);
  }
}

bool InstructionMult::successful() {
  if (passedValue < 0) {
    return false;
  }
  return true;
}

string InstructionMult::errorMessage() {
  return "Error: Multiplication instruction failed.";
}