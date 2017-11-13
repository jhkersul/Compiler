#include <stdio.h>
#include "Lexical/lexical.h"

int main() {
  int numAtoms = 0;
  struct Atom* generatedAtoms = generateAtoms("num := 10;", &numAtoms);

  for (int i = 0; i < numAtoms; ++i) {
    printf("ATOM [%d] %s %s \n", i, generatedAtoms[i].type, generatedAtoms[i].value);
  }

  return 0;
}
