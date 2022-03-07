#include "../includes/InstructionTranslator.h"

#include <sstream>
#include <cctype>
#include <string>
#include <algorithm>
#include <fstream>

InstructionTranslator::InstructionTranslator(string filePath) :
    filePath_(filePath), currentLine(0), moreIns(true) {
  readFile();
  setLabels();
}

/**
 * @brief Auxiliary function of constructor
 */
void InstructionTranslator::readFile() {
  ifstream inFile(filePath_);
  string line;
  while (getline(inFile, line)) {
    savedProgram.push_back(line);
  }
}

/**
 * @brief Auxiliary function of constructor
 */
void InstructionTranslator::setLabels() {
  for(int line = 0; line < savedProgram.size(); line++) {
    istringstream iss(savedProgram.at(line)); // for instruction slicing into words
    string currentWord;
    while (iss >> currentWord) {
      if(currentWord.length() > 0 && currentWord.back() == ':') { // label found
        currentWord.pop_back();
        labelLocations[currentWord] = line;
      }
    }
  }
}

void InstructionTranslator::printTranslatedInstructions() {
  for (int i = 0; i < currentLine; i++) {
    cout << savedProgram.at(i) << endl;
  }
}

vector<string> InstructionTranslator::nextInstruction() {
  string instruction = savedProgram.at(currentLine);
  currentLine++;
  
  toLowerCase(instruction);
  vector<string> instructionFields = parseInstructionFields(instruction);
  return instructionFields;
}

/**
 * nextInstruction() auxiliar method
 */
vector<string> InstructionTranslator::parseInstructionFields(string instruction) {
  vector<string> instructionFields;
  istringstream iss(instruction); // for instruction slicing into words
  string currentWord;
  while (iss >> currentWord) {
    if (currentWord.find(';') != string::npos ||
        currentWord.find('#') != string::npos) { // leave out comments
      break;
    }
    if(currentWord.length() > 0 && currentWord.back() == ':') { // label found
      continue; // don't include label in instruction fields
    }
    instructionFields.push_back(currentWord);
  }
  return instructionFields;
}

/**
 * nextInstruction() auxiliar method
 */
void InstructionTranslator::toLowerCase(string& line) {
  transform(line.begin(), line.end(), line.begin(),
    [](unsigned char c) {
      return std::tolower(c);
    }
  );
}

bool InstructionTranslator::moreInstructions() {
  if(currentLine > savedProgram.size()) {
    return false;
  }
  return true;
}

void InstructionTranslator::jump(string label) {
  if(labelLocations.find(label) != labelLocations.end()) {
    currentLine = labelLocations[label];
  }
}