#include "../../includes/Instructions/InstructionSub.h"

#include <string>
#include <sstream>

InstructionSub::InstructionSub(
    vector<string> args,
    Memory& mem,
    RAMInput& input,
    RAMOutput& output,
    InstructionsTable& insTranslator
  ) : 
    Instruction(args, mem, input, output, insTranslator),
    result(0) {}

void InstructionSub::execute() {
  if (successful()) {
    if (isIndirectValue) { // indirect address
      result = memory.getRegister(0) - 
          memory.getRegister(memory.getRegister(operatorNumericValue));
    } else if (isInmediateValue) { // inmediate address
      result = memory.getRegister(0) - operatorNumericValue;
    } else {
      result = memory.getRegister(0) - memory.getRegister(operatorNumericValue);
    }
    memory.setRegister(result, 0);
  }
}

bool InstructionSub::successful() {
  return true;
}

string InstructionSub::errorMessage() {
  return "An error occured when substracting.";
}