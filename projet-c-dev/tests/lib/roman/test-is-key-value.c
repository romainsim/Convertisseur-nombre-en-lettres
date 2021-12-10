#include <assert.h>
#include <stdlib.h>

#include <roman/roman.h>

int main(void) {
  Symbols *symbols = get_roman_symbols();

  assert(is_key_value(1, symbols));
  assert(is_key_value(5, symbols));
  assert(is_key_value(10, symbols));
  assert(is_key_value(50, symbols));
  assert(is_key_value(100, symbols));
  assert(is_key_value(500, symbols));
  assert(is_key_value(1000, symbols));

  assert(!is_key_value(2, symbols));
  assert(!is_key_value(8, symbols));
  assert(!is_key_value(12, symbols));
  assert(!is_key_value(67, symbols));
  assert(!is_key_value(228, symbols));
  assert(!is_key_value(821, symbols));
  assert(!is_key_value(12384, symbols));

  symbols_destroy(symbols);

  return EXIT_SUCCESS;
}
