#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <roman/roman.h>

extern void test_additive(Symbols *symbols);
extern void test_substractive(Symbols *symbols);

int main(void) {
  Symbols *symbols = get_roman_symbols();

  test_additive(symbols);
  test_substractive(symbols);

  symbols_destroy(symbols);

  return EXIT_SUCCESS;
}

void test_additive(Symbols *symbols) {
  char *two = malloc(16 * sizeof(char));
  char *eight = malloc(16 * sizeof(char));
  char *twenty = malloc(16 * sizeof(char));
  char *sixty = malloc(16 * sizeof(char));
  char *seven_hundred = malloc(16 * sizeof(char));

  convert_decomposition_addend_to_roman_no_key(two, 2, symbols);
  convert_decomposition_addend_to_roman_no_key(eight, 8, symbols);
  convert_decomposition_addend_to_roman_no_key(twenty, 20, symbols);
  convert_decomposition_addend_to_roman_no_key(sixty, 60, symbols);
  convert_decomposition_addend_to_roman_no_key(seven_hundred, 700, symbols);

  assert(strcmp(two, "II") == 0);
  assert(strcmp(eight, "VIII") == 0);
  assert(strcmp(twenty, "XX") == 0);
  assert(strcmp(sixty, "LX") == 0);
  assert(strcmp(seven_hundred, "DCC") == 0);

  free(two);
  free(eight);
  free(twenty);
  free(sixty);
  free(seven_hundred);
}

void test_substractive(Symbols *symbols) {
  char *four = malloc(16 * sizeof(char));
  char *nine = malloc(16 * sizeof(char));
  char *fourty = malloc(16 * sizeof(char));
  char *four_hundred = malloc(16 * sizeof(char));
  char *nine_hundred = malloc(16 * sizeof(char));

  convert_decomposition_addend_to_roman_no_key(four, 4, symbols);
  convert_decomposition_addend_to_roman_no_key(nine, 9, symbols);
  convert_decomposition_addend_to_roman_no_key(fourty, 40, symbols);
  convert_decomposition_addend_to_roman_no_key(four_hundred, 400, symbols);
  convert_decomposition_addend_to_roman_no_key(nine_hundred, 900, symbols);

  assert(strcmp(four, "IV") == 0);
  assert(strcmp(nine, "IX") == 0);
  assert(strcmp(fourty, "XL") == 0);
  assert(strcmp(four_hundred, "CD") == 0);
  assert(strcmp(nine_hundred, "CM") == 0);

  free(four);
  free(nine);
  free(fourty);
  free(four_hundred);
  free(nine_hundred);
}
