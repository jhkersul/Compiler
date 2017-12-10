#ifndef COMPILER_SYNTATIC_TRANSITIONS_H
#define COMPILER_SYNTATIC_TRANSITIONS_H

// Important definitions
// #define LETTER "abcdefghijklmnopqrstuvxz"
// #define DIGIT "0123456789"
// #define LETTER_DIGIT "abcdefghijklmnopqrstuvxz0123456789"
// #define LETTER_DIGIT_EMPTY "abcdefghijklmnopqrstuvxz0123456789 "

// Lexical transition struct
struct SyntaticTransition {
  char* currentState;
  char* token_types;
  char* token_complements;
  char* nextState;
  char* stack_action;
};



char* getNextState(char currentState[], char token_type[], char token_complement[], char stack[]);
//char* getNextOutput(char currentState[], char nextState[]);

#endif //COMPILER_LEXICAL_TRANSITIONS_H
