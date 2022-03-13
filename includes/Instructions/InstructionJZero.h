#ifndef INSTRUCTIONJZERO_H
#define INSTRUCTIONJZERO_H

#include <iostream>
#include <vector>

#include "../RAMInput.h"
#include "../RAMOutput.h"
#include "../Memory.h"

#include "Instruction.h"

using namespace std;

class InstructionJZero : public Instruction {
public:
  InstructionJZero(vector<string> args, Memory& mem, RAMInput& input,
      RAMOutput& output, InstructionsTable& insTranslator); //mem, entrada, salida, args

  virtual ~InstructionJZero() {};

  void execute();

  /**
   * To overload original parse; just leave first argument of instruction as
   *  it is since only a label is needed.
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
};

#endif