#ifndef COMPILER_LEXICAL_TRANSITIONS_H
#define COMPILER_LEXICAL_TRANSITIONS_H

// Important definitions
#define LETTER "abcdefghijklmnopqrstuvxz"
#define DIGIT "0123456789"
#define LETTER_DIGIT "abcdefghijklmnopqrstuvxz0123456789"
#define LETTER_DIGIT_EMPTY "abcdefghijklmnopqrstuvxz0123456789 "

// Lexical transition struct
struct LexicalTransition {
  char* currentState;
  char* inputs;
  char* nextState;
  char* output;
};

char* getNextState(char currentState[], char input);
char* getNextOutput(char currentState[], char nextState[]);

#endif //COMPILER_LEXICAL_TRANSITIONS_H
