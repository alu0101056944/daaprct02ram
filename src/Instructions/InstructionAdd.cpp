#include "../../includes/Instructions/InstructionAdd.h"

#include <string>
#include <sstream>

InstructionAdd::InstructionAdd(
    vector<string> args,
    Memory& mem,
    RAMInput& input,
    RAMOutput& output,
    InstructionTranslator& insTranslator
  ) : 
    Instruction(args, mem, input, output, insTranslator),
    result(0) {}

void InstructionAdd::parse() {
  passedValue = parseValue(args[1]);
  setAddressTypeFlags();
}

void InstructionAdd::execute() {
  if (successful()) {
    if (isIndirectValue) { // indirect address
      result = memory.getRegister(0) +
          memory.getRegister(memory.getRegister(passedValue));
    } else if (isInmediateValue) { // inmediate address
      result = memory.getRegister(0) + passedValue;
    } else {
      result = memory.getRegister(0) + memory.getRegister(passedValue);
    }
    memory.setRegister(result, 0);
  }
}

bool InstructionAdd::successful() {
  if (passedValue < 0) {
    return false;
  }
  return result >= 0;
}

string InstructionAdd::errorMessage() {
  return "Error: result < 0";
}