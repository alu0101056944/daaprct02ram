#include "../../includes/Instructions/Instruction.h"

#include <sstream>

Instruction::Instruction(
    vector<string> args,
    Memory& memory,
    RAMInput& input,
    RAMOutput& output,
    InstructionTranslator& insTranslator
  ) : 
    args(args),
    memory(memory),
    input(input),
    output(output),
    insTranslator(insTranslator),
    passedValue(0),
    isIndirectValue(false),
    isInmediateValue(false),
    successfulChecked(false) {}

void Instruction::setAddressTypeFlags() {
  switch (args[1].at(0)) {
    case '*':
      isIndirectValue = true;
      isInmediateValue = false;
      break;
    case '=':
      isIndirectValue = false;
      isInmediateValue = true;
      break;
    default: // direct address
      isIndirectValue = false;
      isInmediateValue = false;
        break;
  }
}

int Instruction::parseValue(string value) {
  string lastChar;
  lastChar += value.at(value.size()-1);
  stringstream valueString(lastChar); // last char is always the numeric value
  int tempValue = 0;
  valueString >> tempValue; // coarses string to int
  return tempValue;
}

void Instruction::print() {
  cout << endl << "-- Instruction: ";
  for (int i = 0; i < args.size(); i++) {
    cout << args[i];
    if (i < args.size() - 1) {
      cout << " ";
    }
  }
  cout << endl;
}