cmake_minimum_required(VERSION 3.8)

project(Compiler)
set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(SOURCE_FILES
  src/main.c src/Lexical/lexical.c src/Lexical/lexical.h src/General/text-manipulator.c src/General/text-manipulator.h src/Lexical/lexical-transitions.c src/Lexical/lexical-transitions.h
)
add_executable(Compiler ${SOURCE_FILES})

project(CompilerTests)
set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
file(GLOB TEST_SOURCE_FILES
  tests/*.c src/Lexical/*.c src/Lexical/*.h src/General/*.c src/General/*h
)
SET(CMAKE_EXE_LINKER_FLAGS  "-Wall -lcriterion")
add_executable(CompilerTests ${TEST_SOURCE_FILES})
