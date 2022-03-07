#include "InstructionLoad.h"

#include <string>
#include <sstream>

#include <iostream>

InstructionLoad::InstructionLoad(
    vector<string> args,
    Memory& mem,
    RAMInput& input,
    RAMOutput& output,
    InstructionTranslator& insTranslator
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
    memory.setRegister(obtainedValue, 0);
  }
}

bool InstructionLoad::successful() {
  if (passedValue < 0) {
      return false;
  }

  if (!successfulChecked) {
    if (isIndirectValue) { // indirect address
      obtainedValue = memory.getRegister(memory.getRegister(passedValue));
    } else if (isInmediateValue) { // inmediate address
      obtainedValue = passedValue;
    } else {
      obtainedValue = memory.getRegister(passedValue); // direct address
    }
    successfulChecked = true;
  }
  return obtainedValue >= 0;
}

string InstructionLoad::errorMessage() {
    return "Error: negative address";
}