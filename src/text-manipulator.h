//
// Created by Kersul on 09/11/17.
//

#ifndef COMPILER_TEXT_MANIPULATOR_H
#define COMPILER_TEXT_MANIPULATOR_H

#include <stdbool.h>

void readFile(char* fileName, char* text);
bool isSpace(char character);
char readCharacter(char* text, int position);

#endif //COMPILER_TEXT_MANIPULATOR_H
