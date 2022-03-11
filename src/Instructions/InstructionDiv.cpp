#include "../../includes/Instructions/InstructionDiv.h"

#include <string>
#include <sstream>

InstructionDiv::InstructionDiv(
    vector<string> args,
    Memory& mem,  
    RAMInput& input,
    RAMOutput& output,
    InstructionsTable& insTranslator
  ) : 
    Instruction(args, mem, input, output, insTranslator),
    result(0) {}

void InstructionDiv::parse() {
  passedValue = parseValue(args[1]);
  setAddressTypeFlags();
}

void InstructionDiv::execute() {
  if (successful()) {
    memory.setRegister(result, 0);
  }
}

bool InstructionDiv::successful() {
  if (isIndirectValue) { // indirect address
    result = memory.getRegister(0) /
        memory.getRegister(memory.getRegister(passedValue));
  } else if (isInmediateValue) { // inmediate address
    result = memory.getRegister(0) / passedValue;
  } else {
    result = memory.getRegister(0) / memory.getRegister(passedValue);
  }

  if (result <= 0 || passedValue < 0) {
    return false;
  }
  return memory.getRegister(passedValue) > 0;
}

string InstructionDiv::errorMessage() {
  return "Error: divide by 0";
}