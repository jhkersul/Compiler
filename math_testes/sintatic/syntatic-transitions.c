#include <memory.h>
#include <stdbool.h>
#include <stdlib.h>
#include "syntatic-transitions.h"

// All lexical transitions
struct SyntaticTransition transitions[] = {
  { "A0", "declaracoes", NULL, "A1", NULL },
  { "A1", "IF", NULL, "B0", "push" },
  { "B2", ";", NULL, "A2", "pop"}
};


char* getNextState(char currentState[], char current_token_type[], char current_token_complement[], char stack[]) {
  char* nextState = (char *) malloc(sizeof(char) * 1000);
  strcpy(nextState, "");
  bool broke = false;
  for (int i = 0; i < (sizeof(transitions) / sizeof(transitions[0])) && !broke; i += 1) {
    struct SyntaticTransition transition = transitions[i];
    if (strcmp(transition.currentState, currentState) == 0) {
      for (int j = 0; j < strlen(transition.token_types); j += 1) {
        char token_type = transition.token_types[j];
        if (current_token_type[j] == token_type) {
          strcpy(nextState, transition.nextState);
        }
      }
      strncat(stack, &currentState[0], 1);
      //printf("%lu\n", sizeof(stack[]));
    }
  }

  return nextState;
}
