#include "../../includes/Instructions/InstructionAdd.h"

#include <string>
#include <sstream>

InstructionAdd::InstructionAdd(
    vector<string> args,
    Memory& mem,
    RAMInput& input,
    RAMOutput& output,
    InstructionsTable& insTranslator
  ) : 
    Instruction(args, mem, input, output, insTranslator),
    result(0) {}

void InstructionAdd::execute() {
  if (successful()) {
    if (isIndirectValue) { // indirect address
      result = memory.getRegister(0) +
          memory.getRegister(memory.getRegister(operatorNumericValue));
    } else if (isInmediateValue) { // inmediate address
      result = memory.getRegister(0) + operatorNumericValue;
    } else {
      result = memory.getRegister(0) + memory.getRegister(operatorNumericValue);
    }
    memory.setRegister(result, 0);
  }
}

bool InstructionAdd::successful() {
  if (operatorNumericValue < 0) {
    return false;
  }
  return result >= 0;
}

string InstructionAdd::errorMessage() {
  return "Error: result < 0";
}