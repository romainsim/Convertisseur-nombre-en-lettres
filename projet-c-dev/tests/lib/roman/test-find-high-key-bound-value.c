#include <assert.h>
#include <stdlib.h>

#include <roman/roman.h>

int main(void) {
  Symbols *symbols = get_roman_symbols();

  assert(find_high_key_bound_value(0, symbols) == 1);

  assert(find_high_key_bound_value(1, symbols) == 5);
  assert(find_high_key_bound_value(2, symbols) == 5);
  assert(find_high_key_bound_value(3, symbols) == 5);

  assert(find_high_key_bound_value(5, symbols) == 10);
  assert(find_high_key_bound_value(6, symbols) == 10);
  assert(find_high_key_bound_value(8, symbols) == 10);

  assert(find_high_key_bound_value(10, symbols) == 50);
  assert(find_high_key_bound_value(11, symbols) == 50);
  assert(find_high_key_bound_value(25, symbols) == 50);

  assert(find_high_key_bound_value(50, symbols) == 100);
  assert(find_high_key_bound_value(51, symbols) == 100);
  assert(find_high_key_bound_value(85, symbols) == 100);

  assert(find_high_key_bound_value(100, symbols) == 500);
  assert(find_high_key_bound_value(101, symbols) == 500);
  assert(find_high_key_bound_value(465, symbols) == 500);

  assert(find_high_key_bound_value(500, symbols) == 1000);
  assert(find_high_key_bound_value(501, symbols) == 1000);
  assert(find_high_key_bound_value(846, symbols) == 1000);
  assert(find_high_key_bound_value(1000, symbols) == 1000);

  symbols_destroy(symbols);

  return EXIT_SUCCESS;
}
