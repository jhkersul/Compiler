#include <criterion/criterion.h>
#include "../src/lexical-transitions.h"

Test(get_next_state, passing) {
  char* currentState = "S0";
  char input = ':';
  char* nextState = getNextState(currentState, input);
  cr_assert(strcmp(nextState, "OA1") == 0, "Next state must be OA1");

  cr_assert(strcmp(getNextState("S0", 'n'), "I1") == 0, "Next state must be I1");

  char* nextState3 = getNextState("OA2", ' ');
  cr_assert(strcmp(nextState3, "S0") == 0, "Next state must be S0");
}

Test(get_next_output, passing) {
  char currentState[] = "S0";
  char input = ':';
  char nextState[1000] = { 0 };
  strcpy(nextState, getNextState(currentState, input));
  char nextOutput[1000] = { 0 };
  char* nextGeneratedOutput1 = getNextOutput(currentState, nextState);
  strcpy(nextOutput, nextGeneratedOutput1);
  cr_assert(strlen(nextOutput) == 0, "Next output must be null");

  // Testing a invalid transition
  cr_assert(strlen(getNextOutput(currentState, "")) == 0, "Next output must be null");
  cr_assert(strlen(getNextOutput("", "")) == 0, "Sending all null must be null");
}

