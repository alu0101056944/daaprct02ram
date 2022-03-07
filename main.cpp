#include <iostream>
#include <sstream>

#include "RAM.h"

int main(int argc, char** argv) {
  if (argc >= 5) {
    RAM r(argv[1], argv[2], argv[3]);
    auto isOnDebugMode = stoi(argv[4]) == 0;
    if (isOnDebugMode) {
      r.executeProgram();
      r.printInstructionAmount();
      return 0;
    }
  } else {
    cerr << "Invalid amount of input values." << endl;
    cerr << "Requires 4 arguments to be passed to the program." << endl;
    cerr << "For example: " << endl;
    cerr << "Practica2Programa.exe ./Programa.txt ./input.txt ./output.txt 0" << endl;
  }
  

/* 
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
        r.printRegisters();
        break;
      case 't':
        r.printTrace();
        break;
      case 'e':
        r.executeInstruction();
        r.printCurrentInstruction();
        r.printRegisters();
        r.printInput();
        r.printOutput();
        break;
      case 's':
        cout << "Not implemented.\n";
        break;
      case 'i':
        r.printInput();
        break;
      case 'o':
        r.printOutput();
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
  } */
} 