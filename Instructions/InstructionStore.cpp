#include "InstructionStore.h"

#include <string>
#include <sstream>

InstructionStore::InstructionStore(
    vector<string> args,
    Memory& mem,
    RAMInput& input,
    RAMOutput& output,
    InstructionTranslator& insTranslator
  ) : 
    Instruction(args, mem, input, output, insTranslator) {}

void InstructionStore::parse() {
  passedValue = parseValue(args[1]);
  setAddressTypeFlags();
}

void InstructionStore::execute() {
  if (isIndirectValue) { // direccionamiento indirecto
    memory.setRegister(memory.getRegister(0), memory.getRegister(passedValue));
  } else if (!isIndirectValue && !isInmediateValue){ // direccionamiento directo
    memory.setRegister(memory.getRegister(0), passedValue);
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