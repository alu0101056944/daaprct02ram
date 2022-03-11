cmake_minimum_required(VERSION 3.0.0)
project(Practica2Programa VERSION 0.1.0)

add_library(Practica2Implementation 
    IOHandler.cpp
    InstructionTranslator.cpp
    RAM.cpp
    RAMOutput.cpp
    RAMInput.cpp
    Memory.cpp
    Instructions/Instruction.cpp
    Instructions/InstructionLoad.cpp
    Instructions/InstructionRest.cpp
    Instructions/InstructionHalt.cpp
    Instructions/InstructionStore.cpp
    Instructions/InstructionAdd.cpp
    Instructions/InstructionSub.cpp
    Instructions/InstructionMult.cpp
    Instructions/InstructionDiv.cpp
    Instructions/InstructionRead.cpp
    Instructions/InstructionWrite.cpp
    Instructions/InstructionJump.cpp
    Instructions/InstructionJGTZ.cpp
    Instructions/InstructionJZero.cpp
    )

add_executable(Practica2Programa src/main.cpp)

target_include_directories(Practica2Programa PRIVATE "./Instructions")
target_link_libraries(Practica2Programa Practica2Implementation)