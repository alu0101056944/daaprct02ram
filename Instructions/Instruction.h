#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>
#include <vector>

#include "../RAMInput.h"
#include "../RAMOutput.h"
#include "../Memory.h"
#include "../InstructionTranslator.h"

using namespace std;

class Instruction {
public:
  Instruction(vector<string> args, Memory& memory, RAMInput& input,
    RAMOutput& output, InstructionTranslator& insTranslator);

  virtual ~Instruction() = default;
  virtual void execute() = 0;

  /**
   * Check args format and initialize instruction values. Called on object construction.
   */
  virtual void parse() = 0;

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
  InstructionTranslator& insTranslator;

  int passedValue;
  bool isIndirectValue, isInmediateValue;

  bool successfulChecked;

  /**
   * Meant to be used in Instruction::parse() method implementations.
   * 
   * Get int value from instruction string value argument (ex: =2, *4, 7).
   * @pre value = /[*=]?\d+]/ 
   * @param value Find value inside /[*=]?\d+]/ 
   * @returns Numeric value in string param
   */
  int parseValue(string value);

  /**
   * Meant to be used in Instruction::parse() method implementations.
   * 
   * Checks if instruction's passed value is an inmediate value (=<value), 
   * indirect value (*<number>) or direct value(<number>), then sets
   * proper bool flags.
   */
  void setAddressTypeFlags();
};

#endif