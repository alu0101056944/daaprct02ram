#include "../../includes/Instructions/InstructionRest.h"

#include <string>
#include <sstream>

InstructionRest::InstructionRest(
    vector<string> args,
    Memory& mem,
    RAMInput& input,
    RAMOutput& output,
    InstructionsTable& insTranslator
  ) : 
    Instruction(args, mem, input, output, insTranslator),
    result(0) {}

void InstructionRest::execute() {
  if (successful()) {
    memory.setRegister(result, 0);
  }
}

bool InstructionRest::successful() {
  if (isIndirectValue) { // indirect address
    result = memory.getRegister(0) %
        memory.getRegister(memory.getRegister(operatorNumericValue));
  } else if (isInmediateValue) { // inmediate address
    result = memory.getRegister(0) % operatorNumericValue;
  } else {
    result = memory.getRegister(0) % memory.getRegister(operatorNumericValue);
  }
  return true;
}

string InstructionRest::errorMessage() {
  return "Error: divide by 0";
}