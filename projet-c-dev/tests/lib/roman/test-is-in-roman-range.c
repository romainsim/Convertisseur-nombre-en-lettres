#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <roman/roman.h>

int main(void) {
  assert(is_in_roman_range(ROMAN_MIN));
  assert(is_in_roman_range(30));
  assert(is_in_roman_range(1234));
  assert(is_in_roman_range(3489));
  assert(is_in_roman_range(2485));
  assert(is_in_roman_range(ROMAN_MAX));

  assert(!is_in_roman_range(0));
  assert(!is_in_roman_range(5000));
  assert(!is_in_roman_range(6549));
  assert(!is_in_roman_range(7855));

  return EXIT_SUCCESS;
}
