#include <iostream>
#include <sstream>

#include "../includes/RAM.h"

void initiateDebugMenu(RAM& ram) {
  char choice;
  bool programOn = true;
  while (programOn != false) {
    cout << endl << ">h\n";
    cout << "r: ver los registros\n";
    cout << "t: traza\n";
    cout << "e: ejecutar\n";
    cout << "s: desensamblador \n";
    cout << "i: ver cinta entrada \n";
    cout << "o: ver cinta salida \n";
    cout << "h: ayuda\n";
    cout << "x: salir\n";
    cout << ">";

    cin >> choice;

    switch (choice) {
      case 'r':
        ram.printRegisters();
        break;
      case 't':
        ram.printTrace();
        break;
      case 'e':
        if (!ram.hasFinishedExecution()) {
          ram.executeInstruction();
          ram.printCurrentInstruction();
          ram.printRegisters();
          ram.printInput();
          ram.printOutput();
        } else {
          cout << "Program execution has ended." << endl;
        }
        break;
      case 's':
        cout << "Not implemented.\n";
        break;
      case 'i':
        ram.printInput();
        break;
      case 'o':
        ram.printOutput();
        break;
      case 'h':
        cout << "No help included.\n";
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
    auto isOnDebugMode = stoi(argv[4]) == 0;
    if (isOnDebugMode) {
      r.executeProgram();
      r.printInstructionAmount();
      r.printRegisters();
      r.printInput();
      r.printOutput();
      return 0;
    } else {
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
