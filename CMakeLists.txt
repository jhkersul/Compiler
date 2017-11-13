cmake_minimum_required(VERSION 3.8)

project(Compiler)
set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(SOURCE_FILES
  src/main.c src/semantic.c src/lexical.c src/lexical.h src/text-manipulator.c src/text-manipulator.h src/lexical-transitions.c src/lexical-transitions.h
)
add_executable(Compiler ${SOURCE_FILES})

project(CompilerTests)
set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
file(GLOB TEST_SOURCE_FILES
  tests/*.c src/semantic.c src/lexical.c src/lexical.h src/text-manipulator.c src/text-manipulator.h src/lexical-transitions.c src/lexical-transitions.h
)
SET(CMAKE_EXE_LINKER_FLAGS  "-Wall -lcriterion")
add_executable(CompilerTests ${TEST_SOURCE_FILES})
