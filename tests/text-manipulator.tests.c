#include <criterion/criterion.h>
#include "../src/text-manipulator.h"

/**
 * Testing if the text of the file is the test returned by readFile function
 */
Test(first_suite, passing) {
  char* text = malloc(sizeof(char) * 100);
  char* fileName = "tests/testfile.txt";
  readFile(fileName, text);
  char* textToCompare = "var teste = 10;";
  cr_assert(strcmp(text, textToCompare) == 0, "The file content must be equal textToCompare");
}

/**
 * Testing if space is returning space
 */
Test(second_suite, passing) {
  // True
  cr_assert(isSpace(' '), "Space is a space character");
  cr_assert(isSpace('\n'), "Jump line is a space character");
  // False
  cr_assert_not(isSpace('h'), "h is not a space");
}

/**
 * Testing readCharacter function
 */
Test(reading_char, passing) {
  char* text = "Hello World!";
  char character = readCharacter(text, 1);
  cr_assert(character == 'e', "Retrieved character must be e");
}

