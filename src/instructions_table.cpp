#include "../includes/instructions_table.h"

#include <sstream>
#include <string>
#include <algorithm>
#include <fstream>

InstructionsTable::InstructionsTable(string filePath) :
    currentLineOfCodeInExecution(0) {
  readFile(filePath);
  cleanSavedProgram();
}

/**
 * @brief Auxiliary function of constructor
 */
void InstructionsTable::readFile(string filePath) {
  ifstream inFile(filePath);
  string line;
  while (getline(inFile, line)) {
    savedProgram.push_back(line);
  }
}

/**
 * @brief Auxiliary function of constructor. For each line remove the comments,
 *    trim and lowercase it. Then delete the empty lines from the program.
 *    Finally set the labels.
 */
void InstructionsTable::cleanSavedProgram() {
  vector<int> indexOfEmptyLines;
  for (int i = 0; i < savedProgram.size(); i++) {
    removeCommentsFrom(savedProgram[i]);
    leftTrim(savedProgram[i]);
    rightTrim(savedProgram[i]);
    toLowerCase(savedProgram[i]);
  }
  savedProgram.erase(
    remove_if(savedProgram.begin(), savedProgram.end(), [](string s) {
          return s.size() == 0;
        }),
    savedProgram.end());
  for (int i = 0; i < savedProgram.size(); i++) {
    extractLabelFromLine(i, savedProgram[i]);
  }
}

/**
 * @brief Auxiliary function of cleanSavedProgram()
 */
void InstructionsTable::removeCommentsFrom(string &lineOfCode) {
  for (int j = 0; j < lineOfCode.size(); j++) {
    char characterInLine = lineOfCode[j];
    if (characterInLine == '#') {
      lineOfCode = lineOfCode.substr(0, j);
      break;
    }
  }
}

/**
 * @brief Auxiliary function of cleanSavedProgram().
 * erase() receives an iterator to the elements to be erased. The iterator
 *    returns specific elements that match their criteria. In this case,
 *    find_if() iterates all the elements from the end of the string to
 *    the first non white space character, non inclusive.
 */
void InstructionsTable::leftTrim(string &s) {
  s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) {
    return !isspace(ch);
  }));
}

/**
 * @brief Auxiliary function of cleanSavedProgram().
 * erase() receives an iterator to the elements to be erased. The iterator
 *    returns specific elements that match their criteria. In this case,
 *    find_if() iterates all the elements from the end of the string to
 *    the first non white space character, non inclusive. base() le da
 *    la vuelta al iterador, lo que permite luego pasarle el s.end()
 */
void InstructionsTable::rightTrim(string &s) {
  s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
    return !isspace(ch);
  }).base(), s.end());
}

/**
 * @brief Auxiliary function of cleanSavedProgram().
 * Apply an operation to each element of the given string, in this case
 * apply std::tolower to each character.
 */
void InstructionsTable::toLowerCase(string& line) {
  transform(line.begin(), line.end(), line.begin(), [](unsigned char c) {
      return tolower(c);
    }
  );
}

/**
 * @brief Search label and then save it on the label table. Finally erase it
 *    from the argument string.
 */
void InstructionsTable::extractLabelFromLine(int lineNumber, string &lineOfCode) {
  for (int i = 0; i < lineOfCode.size(); i++) {
    char characterInLine = lineOfCode[i];
    if (characterInLine == ':') {
      string labelName = lineOfCode.substr(0, i);
      labelLocations[labelName] = lineNumber;
      lineOfCode.erase(0, i + 1);
      break;
    }
  }
}

vector<string> InstructionsTable::nextInstruction() {
  if (currentLineOfCodeInExecution >= savedProgram.size()) {
    return vector<string>();
  }
  string instructionToBeExecuted = savedProgram.at(currentLineOfCodeInExecution);
  currentLineOfCodeInExecution++;
  return parseVectorOfOperatorsFrom(instructionToBeExecuted);
}

/**
 * @brief Auxiliary function of nextInstruction().
 */
vector<string> InstructionsTable::parseVectorOfOperatorsFrom(string instruction) {
  vector<string> instructionFields;
  istringstream ss(instruction);
  string word;
  while (ss >> word) {
    instructionFields.push_back(word);
  }
  return instructionFields;
}

/**
 * @brief count() returns the amount of elements with labelKey as key. Since
 *    it is only a map it will stop at the first match.
 */
void InstructionsTable::jump(string labelKey) {
  if(labelLocations.count(labelKey)) {
    currentLineOfCodeInExecution = labelLocations[labelKey];
  }
}