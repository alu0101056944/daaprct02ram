#include <iostream>
#include <sstream>

#include "../includes/RAM.h"

void initiateDebugMenu(RAM& ram) {
  char choice;
  bool programOn = true;
  while (programOn != false) {
    cout << endl << ">h\n";
    cout << "e: ejecutar\n";
    cout << "r: ver los registros\n";
    cout << "i: ver cinta entrada\n";
    cout << "o: ver cinta salida \n";
    cout << "x: salir\n";
    cout << ">";

    cin >> choice;

    switch (choice) {
      case 'e':
        if (!ram.hasFinishedExecution()) {
          ram.executeInstruction();
          ram.printCurrentInstructionInfo();
          ram.printMemoryRegisters();
          ram.printInput();
          ram.printOutput();
        } else {
          cout << "Program execution has ended." << endl;
        }
        break;
      case 'r':
        ram.printMemoryRegisters();
        break;
      case 'i':
        ram.printInput();
        break;
      case 'o':
        ram.printOutput();
        break;
      case 'x':
        programOn = false;
        break;
      default:
        cout << "Not a Valid Choice. \n";
        cout << "Choose again.\n";
        cin >> choice;
        break;
    }
  }
}

int main(int argc, char** argv) {
  if (argc >= 5) {
    RAM r(argv[1], argv[2], argv[3]);
    auto executionMode = stoi(argv[4]);
    switch (executionMode) {
      default:
          r.executeProgram();
          r.printInstructionAmount();
          r.printMemoryRegisters();
          r.printInput();
          r.printOutput();
      case 1:
          r.executeProgram();
          r.printInstructionAmount();
      case 2:
          cout << "Initiating debug mode." << endl;
          initiateDebugMenu(r);
    }
  } else {
    cerr << "Invalid amount of input values." << endl;
    cerr << "Requires 4 arguments to be passed to the program." << endl;
    cerr << "For example: " << endl;
    cerr << "Practica2Programa.exe ./Programa.txt ./input.txt ./output.txt 0" << endl;
  }
}
