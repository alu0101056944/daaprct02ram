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

void InstructionLoad::execute() {
  if (successful()) {
    if (isIndirectValue) { // indirect address
      obtainedValue = memory.getRegister(memory.getRegister(operatorNumericValue));
    } else if (isInmediateValue) { // inmediate address
      obtainedValue = operatorNumericValue;
    } else {
      obtainedValue = memory.getRegister(operatorNumericValue); // direct address
    }
    memory.setRegister(obtainedValue, 0);
  }
}

bool InstructionLoad::successful() {
  if (!isInmediateValue && !isIndirectValue && operatorNumericValue < 1) {
    return false;
  }
  return true;
}

string InstructionLoad::errorMessage() {
    return "Error: negative address";
}