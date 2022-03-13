#include "../../includes/Instructions/InstructionStore.h"

#include <string>
#include <sstream>

InstructionStore::InstructionStore(
    vector<string> args,
    Memory& mem,
    RAMInput& input,
    RAMOutput& output,
    InstructionsTable& insTranslator
  ) : 
    Instruction(args, mem, input, output, insTranslator) {}

void InstructionStore::execute() {
  if (isIndirectValue) { // direccionamiento indirecto
    memory.setRegister(memory.getRegister(0), memory.getRegister(operatorNumericValue));
  } else if (!isIndirectValue && !isInmediateValue){ // direccionamiento directo
    memory.setRegister(memory.getRegister(0), operatorNumericValue);
  }
}

bool InstructionStore::successful() {
  if (isInmediateValue) {
    return false;
  }
  return true; //cant go wrong
}

string InstructionStore::errorMessage() {
  return "Error: Instruction Store failed.";
}