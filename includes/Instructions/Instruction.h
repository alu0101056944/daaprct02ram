#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>
#include <vector>

#include "../RAMInput.h"
#include "../RAMOutput.h"
#include "../Memory.h"
#include "../instructions_table.h"

using namespace std;

class Instruction {
public:
  Instruction(vector<string> args, Memory& memory, RAMInput& input,
    RAMOutput& output, InstructionsTable& insTranslator);

  virtual ~Instruction() = default;
  virtual void execute() = 0;

  /**
   * Set address flags, operatorIndexValue and finally the operator numeric
   *    value.
   */
  virtual void parse();

  /**
   * @returns true if execution was successful
   */
  virtual bool successful() = 0;

  /**
   * "no error" if successful
   * @returns error message if unsuccesful
   */
  virtual string errorMessage() = 0;

  virtual void print();
protected:
  vector<string> args;

  Memory& memory;
  RAMInput& input;
  RAMOutput& output;
  InstructionsTable& insTranslator;

  int operatorNumericValue;
  int operatorIndexValue; // i[j] where j = operatorIndexValue
  bool isIndirectValue;
  bool isInmediateValue;

  bool successfulChecked;
};

#endif