#include "../../includes/Instructions/InstructionWrite.h"

#include <string>
#include <sstream>

InstructionWrite::InstructionWrite(
    vector<string> args,
    Memory& mem,
    RAMInput& input,
    RAMOutput& output,
    InstructionsTable& insTranslator
  ) : 
    Instruction(args, mem, input, output, insTranslator),
    obtainedValue(0) {}

void InstructionWrite::execute() {
  if (successful()) {
    if (isIndirectValue) { // indirect address
      obtainedValue = memory.getRegister(memory.getRegister(operatorNumericValue));
    } else if (isInmediateValue) { // inmediate address
      obtainedValue = operatorNumericValue;
    } else {
      obtainedValue = memory.getRegister(operatorNumericValue); // direct address
    }
    output.writeValue(obtainedValue);
  }
}

bool InstructionWrite::successful() {
  if (!isInmediateValue && operatorNumericValue < 1) {
    return false;
  }
  return true;
}

string InstructionWrite::errorMessage() {
  return "Error: Write instruction failed.";
}