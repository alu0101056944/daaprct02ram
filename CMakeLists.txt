cmake_minimum_required(VERSION 3.0.0)
project(Practica2Programa VERSION 0.1.0)

add_library(Practica2Implementation 
    src/instructions_table.cpp
    src/RAM.cpp
    src/RAMOutput.cpp
    src/RAMInput.cpp
    src/Memory.cpp
    src/Instructions/Instruction.cpp
    src/Instructions/InstructionLoad.cpp
    src/Instructions/InstructionRest.cpp
    src/Instructions/InstructionHalt.cpp
    src/Instructions/InstructionStore.cpp
    src/Instructions/InstructionAdd.cpp
    src/Instructions/InstructionSub.cpp
    src/Instructions/InstructionMult.cpp
    src/Instructions/InstructionDiv.cpp
    src/Instructions/InstructionRead.cpp
    src/Instructions/InstructionWrite.cpp
    src/Instructions/InstructionJump.cpp
    src/Instructions/InstructionJGTZ.cpp
    src/Instructions/InstructionJZero.cpp
  )

add_executable(Practica2Programa src/main.cpp)

target_include_directories(Practica2Programa PRIVATE "./Instructions")
target_link_libraries(Practica2Programa Practica2Implementation)