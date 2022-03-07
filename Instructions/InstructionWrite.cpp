#include "InstructionWrite.h"

#include <string>
#include <sstream>

InstructionWrite::InstructionWrite(
    vector<string> args,
    Memory& mem,
    RAMInput& input,
    RAMOutput& output,
    InstructionTranslator& insTranslator
  ) : 
    Instruction(args, mem, input, output, insTranslator),
    obtainedValue(0) {}

void InstructionWrite::parse() {
  passedValue = parseValue(args[1]);
  setAddressTypeFlags();
}

void InstructionWrite::execute() {
  if (isIndirectValue) { // indirect address
    obtainedValue = memory.getRegister(memory.getRegister(passedValue));
  } else if (isInmediateValue) { // inmediate address
    obtainedValue = passedValue;
  } else {
    obtainedValue = memory.getRegister(passedValue); // direct address
  }
  output.writeValue(obtainedValue);
}

bool InstructionWrite::successful() {
  if (!isInmediateValue && passedValue < 1 || passedValue < 0) {
    return false;
  }
  return true;
}

string InstructionWrite::errorMessage() {
  return "Error: Write";
}