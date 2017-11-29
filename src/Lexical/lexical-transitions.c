#include <memory.h>
#include <stdbool.h>
#include <stdlib.h>
#include "lexical-transitions.h"
#include "../General/text-manipulator.h"

// All lexical transitions
struct LexicalTransition transitions[] = {
  { "S0", ":", "OA1", NULL },
  { "OA1", "=", "OA2", NULL },
  { "OA2", NULL, "S0", "attribution_op" },
  { "S0", "&", "OL2", NULL },
  { "OL2", "&", "OL3", NULL },
  { "OL3", NULL, "S0", "logical_op" },
  { "S0", "|", "OL1", NULL },
  { "OL1", "|", "OL3", NULL },
  { "OL3", NULL, "S0", "logical_op" },
  { "S0", ";", "FS1", NULL },
  { "FS1", NULL, "S0", "end" },
  { "S0", "><", "OR1", NULL },
  { "OR1", "=", "OR3", NULL },
  { "OR1", NULL, "S0", "comparison_op" },
  { "OR3", NULL, "S0", "comparison_op" },
  { "S0", "=", "OR2", NULL },
  { "OR2", "=", "OR3", NULL },
  { "S0", LETTER, "I1", NULL },
  { "I1", LETTER_DIGIT, "I1", NULL },
  { "I1", NULL, "S0", "identifier" },
  { "S0", DIGIT, "N1", NULL },
  { "N1", DIGIT, "N1", NULL },
  { "N1", NULL, "S0", "number" },
  { "N1", ".", "N2", NULL },
  { "N2", DIGIT, "N1", NULL },
  { "S0", "eof", "FA1", NULL },
  { "FA1", NULL, "S0", "final_space" },
  { "S0", ",", "SP1", NULL },
  { "SP1", NULL, "S0", "separator" },
  { "S0", "()[]{}", "A1", NULL },
  { "A1", NULL, "S0", "grouper" },
  { "S0", "/", "C1", NULL },
  { "C1", "/", "C2", NULL },
  { "C1", NULL, "S0", "arithmetic_op" },
  { "C2", LETTER_DIGIT_EMPTY, "C2", NULL },
  { "C2", "\n", "S0", "space" },
  { "C2", NULL, "S0", "space" },
  { "S0", "+-*", "OA1", NULL },
  { "OA1", NULL, "S0", "arithmetic_op" },
};

/**
 * Getting next state given the currentState and the current input
 * @param  {String}  currentState  The current state
 * @param  {Char}  currentInput  The current input
 * @return  {String}  The next state
 */
char* getNextState(char currentState[], char currentInput) {
  char* nextState = (char *) malloc(sizeof(char) * 1000);
  strcpy(nextState, "");
  bool broke = false;
  // Passing through all the transitions
  for (int i = 0; i < (sizeof(transitions) / sizeof(transitions[0])) && !broke; i += 1) {
    struct LexicalTransition transition = transitions[i];
    // Checking if the current state is the transition current state
    if (strcmp(transition.currentState, currentState) == 0) {
      // If the inputs is NULL and it's not a space, go to the next
      if (transition.inputs == NULL && !isSpace(currentInput)) continue;
      // If it's a space and the inputs is null, we can set the nextState already
      if (transition.inputs == NULL && isSpace(currentInput)) {
        strcpy(nextState, transition.nextState);
        break;
      }
      // Passing through all inputs and check if matches
      for (int j = 0; j < strlen(transition.inputs); j += 1) {
        char input = transition.inputs[j];
        // Checking if currentInput is the transition input
        if (currentInput == input) {
          strcpy(nextState, transition.nextState);
          broke = true;
          break;
        }
      }
    }
  }

  return nextState;
}

/**
 * Getting next output given the current state and the next state
 * @param  {String}  currentState  The current state
 * @param  {String}  nextState  The next state
 * @return  {String}  The output
 */
char * getNextOutput(char currentState[], char nextState[]) {
  char* nextOutput = (char *) malloc(sizeof(char) * 1000);
  // If nextState or currentState are null, return null
  if (strlen(nextState) == 0 || strlen(currentState) == 0) {
    return "";
  }
  // Passing through all the transitions
  for (int i = 0; i < sizeof(transitions)/ sizeof(transitions[0]); i += 1) {
    struct LexicalTransition transition = transitions[i];
    // Checking if the current state is the transition current state and the nextState matches
    if (strcmp(transition.currentState, currentState) == 0 && strcmp(transition.nextState, nextState) == 0) {
      if (transition.output == NULL) {
        strcpy(nextOutput, "");
      } else {
        strcpy(nextOutput, transition.output);
      }
    }
  }

  return nextOutput;
}
