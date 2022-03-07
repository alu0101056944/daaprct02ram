#ifndef INSTRUCTIONSUB_H
#define INSTRUCTIONSUB_H

#include <iostream>
#include <vector>

#include "../RAMInput.h"
#include "../RAMOutput.h"
#include "../Memory.h"

#include "Instruction.h"

using namespace std;

class InstructionSub : public Instruction {
public:
  InstructionSub(vector<string> args, Memory& mem, RAMInput& input,
      RAMOutput& output, InstructionTranslator& insTranslator); //mem, entrada, salida, args

  virtual ~InstructionSub() {};

  void execute();

  /**
   * Check args format and initialize instruction values. Called on object construction.
   */
  void parse();

  /**
   * @returns true if execution was successful
   */
  bool successful();

  /**
   * "no error" if successful
   * @returns error message if unsuccesful
   */
  string errorMessage();
private:
  int result; // used to save result of successful() function for quick reutilization on execute()
};

#endif