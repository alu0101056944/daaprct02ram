#ifndef InstructionRest_H
#define InstructionRest_H

#include <iostream>
#include <vector>

#include "../RAMInput.h"
#include "../RAMOutput.h"
#include "../instructions_table.h"
#include "../Memory.h"

#include "Instruction.h"

using namespace std;

class InstructionRest : public Instruction {
public:
  InstructionRest(vector<string> args, Memory& mem, RAMInput& input,
    RAMOutput& output, InstructionsTable& insTranslator);

  virtual ~InstructionRest() {};

  void execute();

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
  int result;
};

#endif