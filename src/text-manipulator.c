#include <stdio.h>
#include "text-manipulator.h"
#include <stdlib.h>
#include <string.h>

/**
 * This function reads a file and record on text param the text of that file
 * @param fileName A pointer to the name of the file
 * @param text A pointer to the text of the file (will be recorded here)
 */
void readFile(char* fileName, char* text) {
  // Opening file
  FILE *f;
  char currentChar;
  f = fopen(fileName, "r");

  // Passing through file
  for (int i = 0; (currentChar = (char) fgetc(f)) != EOF; i += 1) {
    text[i] = currentChar;
  }
  // Closing file
  fclose(f);
}

/**
 * Checking if a character is a space (jump line is considered a space character)
 * @param character The character that you wanna analyse
 * @return True if is space, false if isn't
 */
bool isSpace(char character) {
  return character == ' '  || character == '\n';
}

/**
 * Reads a character at certain position
 * @param  {String}  text  The text that you wanna read
 * @param  {Integer}  position  The position you wanna retrieve a character
 * @return  {Char}  The retrieved char
 */
char readCharacter(char* text, int position) {
  return text[position];
}

