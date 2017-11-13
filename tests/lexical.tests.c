#include <criterion/criterion.h>
#include "../src/lexical.h"

Test(is_valid_atom, passing) {
  // Testing invalid atoms
  struct Atom atom1 = { {0}, {0} };
  struct Atom atom2 = { "lexical_error", {0} };
  bool atom1Valid = isValidAtom(atom1);
  bool atom2Valid = isValidAtom(atom2);
  cr_assert_not(atom1Valid, "atom1 must be invalid");
  cr_assert_not(atom2Valid, "atom2 must be invalid");

  // Testing valid atoms
  struct Atom atom3 = { "identifier", "if" };
  bool atom3Valid = isValidAtom(atom3);
  cr_assert(atom3Valid, "atom3 is a valid atom");
}

Test(get_lexical_error_atom, passing) {
  struct Atom lexicalErrorAtom1 = getLexicalErrorAtom("if");
  cr_assert(strcmp(lexicalErrorAtom1.type, "lexical_error") == 0, "The type must be lexical_error");
}

Test(is_end_of_atom, passing) {
  // Valid end of atoms
  cr_assert(isEndOfAtom(' ', "", ""), "' ' is end of atom");
  cr_assert(isEndOfAtom('i', "", ""), "The state and output null is end of atom");
  cr_assert(isEndOfAtom(' ', "S0", ""), "' ' is end of atom, even if has current state");

  // Not end of atoms
  cr_assert_not(isEndOfAtom('i', "S0", ""), "i with a state is not a end of atom");
  cr_assert_not(isEndOfAtom('f', "S0", "identifier"), "f and state and output is not a end of atom");
}

Test(iterate_atom, passing) {
  struct Atom atom1 = { { 0 }, "i" };
  struct Atom newAtom1 = iterateAtom(atom1, 'f', "");
  cr_assert(strcmp(newAtom1.value, "if") == 0, "New atom value must be if");

  struct Atom atom2 = { { 0 }, { 0 } };
  struct Atom newAtom2 = iterateAtom(atom2, 'i', "");
  cr_assert(strcmp(newAtom2.value, "i") == 0, "New atom value must be i");

  struct Atom atom3 = { { 0 }, "if" };
  struct Atom newAtom3 = iterateAtom(atom3, ' ', "identifier");
  cr_assert(strcmp(newAtom3.value, "if") == 0, "New atom value must continue to be if");
  cr_assert(strcmp(newAtom3.type, "identifier") == 0, "New atom type must be identifier");
}

Test(generate_atoms, passing) {
  struct Atom atomsExpected1[] = {
    { "identifier", "num" },
    { "attribution_op", ":=" },
    { "number", "10" },
    { "end", ";" }
  };
  struct Atom* generatedAtoms = generateAtoms("num := 10;");

  cr_assert(strcmp(generatedAtoms[0].type, atomsExpected1[0].type) == 0, "Generated atoms must be equal the atoms expected");
  cr_assert(strcmp(generatedAtoms[1].type, atomsExpected1[1].type) == 0, "Generated atoms must be equal the atoms expected");
  cr_assert(strcmp(generatedAtoms[2].type, atomsExpected1[2].type) == 0, "Generated atoms must be equal the atoms expected");
  cr_assert(strcmp(generatedAtoms[3].type, atomsExpected1[3].type) == 0, "Generated atoms must be equal the atoms expected");
}

Test(append_atom_array, passing) {
  struct Atom initialAtoms[] = {
    { "identifier", "num" },
    { "attribution_op", ":=" },
    { "number", "10" }
  };
  struct Atom* atoms = initialAtoms;
  struct Atom atom = { "end", ";" };
  atoms = appendAtomArray(atoms, 3, atom);

  for (int i = 0; i < 3; i += 1) {
    cr_assert(strcmp(atoms[i].value, initialAtoms[i].value) == 0, "Atoms must be of value of initial atoms");
    cr_assert(strcmp(atoms[i].type, initialAtoms[i].type) == 0, "Atoms must be of type of initial atoms");
  }

}

Test(append_empty_atom_array, passing) {
  struct Atom* atoms = NULL;
  struct Atom atom = { "end", ";" };
  atoms = appendAtomArray(atoms, 0, atom);

  cr_assert(strcmp(atoms[0].type, "end") == 0, "First atom must be of type end");
  cr_assert(strcmp(atoms[0].value, ";") == 0, "First atom must be of value ;");

  // Appending again
  struct Atom newAtom = { "hello", "i" };
  atoms = appendAtomArray(atoms, 1, newAtom);
  cr_assert(strcmp(atoms[1].type, "hello") == 0, "Second atom must be of type hello");
  cr_assert(strcmp(atoms[1].value, "i") == 0, "Second atom must be of value i");
}
