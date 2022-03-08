#include "../../includes/Instructions/InstructionLoad.h"

#include <string>
#include <sstream>

#include <iostream>

InstructionLoad::InstructionLoad(
    vector<string> args,
    Memory& mem,
    RAMInput& input,
    RAMOutput& output,
    InstructionsTable& insTranslator
  ) : 
    Instruction(args, mem, input, output, insTranslator),
    obtainedValue(0) {
}

void InstructionLoad::parse() {
  passedValue = parseValue(args[1]);
  setAddressTypeFlags();
}

void InstructionLoad::execute() {
  if (successful()) {
    if (isIndirectValue) { // indirect address
      obtainedValue = memory.getRegister(memory.getRegister(passedValue));
    } else if (isInmediateValue) { // inmediate address
      obtainedValue = passedValue;
    } else {
      obtainedValue = memory.getRegister(passedValue); // direct address
    }
    memory.setRegister(obtainedValue, 0);
  }
}

bool InstructionLoad::successful() {
  if (!isInmediateValue && !isIndirectValue && passedValue < 1) {
    return false;
  }
  return true;
}

string InstructionLoad::errorMessage() {
    return "Error: negative address";
}