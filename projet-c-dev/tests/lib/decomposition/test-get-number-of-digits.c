#include <assert.h>
#include <stdlib.h>

#include <decomposition/decomposition.h>

int main(void) {
  assert(get_number_of_digits(2) == 1);
  assert(get_number_of_digits(78) == 2);
  assert(get_number_of_digits(750) == 3);
  assert(get_number_of_digits(5447) == 4);
  assert(get_number_of_digits(99369) == 5);
  assert(get_number_of_digits(8201514367) == 10);
  assert(get_number_of_digits(137772460850509) == 15);

  return EXIT_SUCCESS;
}
