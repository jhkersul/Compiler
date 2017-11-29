#!/bin/bash
# Compiling tests
cmake --build ./ --target Compiler -- -j 4
# Running tests
./Compiler
