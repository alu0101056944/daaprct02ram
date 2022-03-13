#ifndef INSTRUCTIONSTORE_H
#define INSTRUCTIONSTORE_H

#include <iostream>
#include <vector>

#include "../RAMInput.h"
#include "../RAMOutput.h"
#include "../Memory.h"

#include "Instruction.h"

using namespace std;

class InstructionStore : public Instruction {
public:
  InstructionStore(vector<string> args, Memory& mem, RAMInput& input,
      RAMOutput& output, InstructionsTable& insTranslator); //mem, entrada, salida, args
  
  virtual ~InstructionStore() {};

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
  int obtainedValue; // used to save result of successful() function for quick reutilization on execute()
};

#endif