#include "../../includes/Instructions/Instruction.h"

#include <sstream>

Instruction::Instruction(
    vector<string> args,
    Memory& memory,
    RAMInput& input,
    RAMOutput& output,
    InstructionsTable& insTranslator
  ) : 
    args(args),
    memory(memory),
    input(input),
    output(output),
    insTranslator(insTranslator),
    operatorNumericValue(0),
    operatorIndexValue(0),
    isIndirectValue(false),
    isInmediateValue(false),
    successfulChecked(false) {}

void Instruction::parse() {
  string fistArgumentOfInstruction = args[1];
  for (int i = 0; i < fistArgumentOfInstruction.size(); i++) {
    if (fistArgumentOfInstruction[i] == '*') {
      isIndirectValue = true;
      isInmediateValue = false;
      fistArgumentOfInstruction.erase(i, 1);
      break;
    } else if (fistArgumentOfInstruction[i] == '=') {
      isIndirectValue = false;
      isInmediateValue = true;
      fistArgumentOfInstruction.erase(i, 1);
      break;
    } else if (fistArgumentOfInstruction[i] == '[') {
      operatorIndexValue = fistArgumentOfInstruction[i + 1];
      fistArgumentOfInstruction.erase(i, 3);
    }
  }
  string operatorValueAsString;
  operatorValueAsString +=
      fistArgumentOfInstruction.at(fistArgumentOfInstruction.size() - 1);
  operatorNumericValue = std::stoi(operatorValueAsString);
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