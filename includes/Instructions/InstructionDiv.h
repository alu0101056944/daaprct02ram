#ifndef INSTRUCTIONDIV_H
#define INSTRUCTIONDIV_H

#include <iostream>
#include <vector>

#include "../RAMInput.h"
#include "../RAMOutput.h"
#include "../Memory.h"

#include "Instruction.h"

using namespace std;

class InstructionDiv : public Instruction {
public:
  InstructionDiv(vector<string> args, Memory& mem, RAMInput& input,
    RAMOutput& output, InstructionsTable& insTranslator); //mem, entrada, salida, args

  virtual ~InstructionDiv() {};

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