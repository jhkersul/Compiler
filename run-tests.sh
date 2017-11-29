#!/bin/bash
# Compiling tests
cmake --build ./ --target CompilerTests -- -j 4
# Running tests
./CompilerTests
