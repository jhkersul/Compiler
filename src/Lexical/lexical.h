#include <stdbool.h>

#ifndef COMPILER_LEXICAL_H
#define COMPILER_LEXICAL_H

struct Atom {
  char type[1000];
  char value[1000];
};

bool isEndOfAtom(char currentInput, const char* currentState, const char* currentOutput);
bool isValidAtom(struct Atom atom);
struct Atom getLexicalErrorAtom(const char* value);
struct Atom iterateAtom(struct Atom currentAtom, char character, char* type);
struct Atom* generateAtoms(char* text, int* resultSize);
struct Atom* appendAtomArray(struct Atom* atoms, int size, struct Atom atom);

#endif //COMPILER_LEXICAL_H

