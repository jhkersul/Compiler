#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "../General/text-manipulator.h"
#include "lexical.h"
#include "lexical-transitions.h"

/**
 * Checks if it' a end of a Atom
 * @param  {Char}  currentInput  The input
 * @param  {Char}  currentState  The current state
 * @param  {Char}  currentOutput  The current output
 * @return  {Boolean}  True if it's end of atom, false if it isn't
 */
bool isEndOfAtom(char currentInput, const char* currentState, const char* currentOutput) {
  if (isSpace(currentInput)) return true;

  // If the current transition using the input is null, it's the end too
  if (strlen(currentState) == 0 && strlen(currentOutput) == 0) return true;
  else return false;
}

/**
 * Checks if it' a valid atom
 * @param  {Atom}  atom  The atom that you wanna check
 * @return  {Boolean}  Returns true if it's valid, false if it isn't
 */
bool isValidAtom(struct Atom atom) {
  return (strlen(atom.value) != 0 && strlen(atom.type) != 0);
}

/*
 * Getting a atom of type Lexical Error
 * @param  {String}  value  The value to record on the atom
 * @return  {Atom}  Returns a new atom, of the type 'lexical_error'
 */
struct Atom getLexicalErrorAtom(const char* value) {
  struct Atom atom = { {0} , {0} };
  strcpy(atom.type, "lexical_error");
  strcpy(atom.value, value);
  return atom;
}

/**
 * Iterate a atom
 * @param  {Atom}  currentAtom  The current atom to iterate
 * @param  {Char}  character  The character to add on atom
 * @param  {String}  type  The type of the atom
 * @return  {Atom}  The new atom iterated
 */
struct Atom iterateAtom(struct Atom currentAtom, char character, char type[]) {
  struct Atom newAtom = { {0}, {0} };
  // Adding newAtom value
  if (strlen(currentAtom.value) == 0 && !isSpace(character)) {
    char stringChar[] = { character, '\0' };
    strcpy(newAtom.value, stringChar);
  } else if (strlen(currentAtom.value) != 0 && !isSpace(character)) {
    char stringCharacter[] = { character, '\0' };
    strcpy(newAtom.value, currentAtom.value);
    strcat(newAtom.value, stringCharacter);
  } else if (strlen(currentAtom.value) != 0 && isSpace(character)) {
    strcpy(newAtom.value, currentAtom.value);
  }
  // Setting the type
  if (strlen(type) != 0) {
    strcpy(newAtom.type, type);
  }

  return newAtom;
}

struct Atom* appendAtomArray(struct Atom* atoms, int size, struct Atom atom) {
  int newSize = size + 1;
  struct Atom *newAtoms = malloc(newSize * sizeof(struct Atom));

  for (int i = 0; i < size; i += 1) {
    strcpy(newAtoms[i].type, atoms[i].type);
    strcpy(newAtoms[i].value, atoms[i].value);
  }

  strcpy(newAtoms[size].type, atom.type);
  strcpy(newAtoms[size].value, atom.value);

  return newAtoms;
}

struct Atom* generateAtoms(char* text, int* resultSize) {
  struct Atom* atoms = NULL;
  struct Atom INITIAL_ATOM = { { 0 }, { 0 } };
  char INITIAL_STATE[] = "S0";

  // The first state is S0
  char currentState[1000] = { 0 };
  strcpy(currentState, INITIAL_STATE);
  // The number of atoms at the beggining is 0
  int numAtoms = 0;
  // Defining our current atom
  struct Atom currentAtom = INITIAL_ATOM;
  // Passing through the text to analyze
  for (int i = 0; i <= strlen(text); i++) {
    // Getting char
    char input = readCharacter(text, i);

    // If we're at the initial state and receive a space, continue
    if (strcmp(currentState, INITIAL_STATE) == 0 && (isSpace(input) || input == '\0')) {
      continue;
    }

    // Getting the new current state and output
    char nextState[1000] = { 0 };
    strcpy(nextState, getNextState(currentState, input));

    // Detects if it's a new char
    if (strlen(nextState) == 0) {
      // If the nextState doesnt exists, try to get a nextState with a space char
      strcpy(nextState, getNextState(currentState, ' '));
      char nextOutput[1000] = { 0 };
      strcpy(nextOutput, getNextOutput(currentState, nextState));
      // If not null, it means that we have a new char
      if (strlen(nextState) != 0 && strlen(nextOutput) != 0) {
        // If we have a output
        currentAtom = iterateAtom(currentAtom, ' ', nextOutput);
        atoms = appendAtomArray(atoms, numAtoms, currentAtom);
        numAtoms += 1;
        currentAtom = INITIAL_ATOM;
        strcpy(currentState, INITIAL_STATE);
        if (input == '\0') {
          continue;
        } else {
          strcpy(nextState, getNextState(currentState, input));
        }
      } else if (strlen(nextState) != 0) {
        // If the currentState still doesnt exists, we're with a lexical error
        currentAtom = iterateAtom(currentAtom, input, "");
        atoms = appendAtomArray(atoms, numAtoms, getLexicalErrorAtom(currentAtom.value));
        numAtoms += 1;
        currentAtom = INITIAL_ATOM;
        strcpy(currentState, INITIAL_STATE);
        continue;
      }
    }

    if (strlen(nextState) == 0) {
      // If the currentState still doesnt exists, we're with a lexical error
      currentAtom = iterateAtom(currentAtom, input, "");
      atoms = appendAtomArray(atoms, numAtoms, getLexicalErrorAtom(currentAtom.value));
      numAtoms += 1;
      currentAtom = INITIAL_ATOM;
      strcpy(currentState, INITIAL_STATE);
      continue;
    } else {
      // In case we have a currentState
      char nextOutput[1000] = { 0 };
      strcpy(nextOutput, getNextOutput(currentState, nextState));
      if (strlen(nextOutput) != 0) {
        // If we have a output
        currentAtom = iterateAtom(currentAtom, input, nextOutput);
        atoms = appendAtomArray(atoms, numAtoms, currentAtom);
        numAtoms += 1;
        currentAtom = INITIAL_ATOM;
      } else {
        // In case we don't have a output
        currentAtom = iterateAtom(currentAtom, input, "");
      }

      strcpy(currentState, nextState);
    }
  }

  // Setting the resulted size
  *resultSize = numAtoms;

  return atoms;
}
