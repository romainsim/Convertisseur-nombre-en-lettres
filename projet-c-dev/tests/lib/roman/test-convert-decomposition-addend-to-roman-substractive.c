#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <roman/roman.h>

int main(void) {
  Symbols *symbols = get_roman_symbols();

  char *four = malloc(16 * sizeof(char));
  char *nine = malloc(16 * sizeof(char));
  char *fourty = malloc(16 * sizeof(char));
  char *four_hundred = malloc(16 * sizeof(char));
  char *nine_hundred = malloc(16 * sizeof(char));

  char *one = malloc(16 * sizeof(char));
  char *twenty = malloc(16 * sizeof(char));
  char *thirty = malloc(16 * sizeof(char));
  char *three_hundred = malloc(16 * sizeof(char));

  convert_decomposition_addend_to_roman_substractive(four, 4, symbols);
  convert_decomposition_addend_to_roman_substractive(nine, 9, symbols);
  convert_decomposition_addend_to_roman_substractive(fourty, 40, symbols);
  convert_decomposition_addend_to_roman_substractive(four_hundred, 400, symbols);
  convert_decomposition_addend_to_roman_substractive(nine_hundred, 900, symbols);

  convert_decomposition_addend_to_roman_substractive(one, 1, symbols);
  convert_decomposition_addend_to_roman_substractive(twenty, 20, symbols);
  convert_decomposition_addend_to_roman_substractive(thirty, 30, symbols);
  convert_decomposition_addend_to_roman_substractive(three_hundred, 300, symbols);

  assert(strcmp(four, "IV") == 0);
  assert(strcmp(nine, "IX") == 0);
  assert(strcmp(fourty, "XL") == 0);
  assert(strcmp(four_hundred, "CD") == 0);
  assert(strcmp(nine_hundred, "CM") == 0);

  assert(strlen(one) == 0);
  assert(strlen(twenty) == 0);
  assert(strlen(thirty) == 0);
  assert(strlen(three_hundred) == 0);

  free(four);
  free(nine);
  free(fourty);
  free(four_hundred);
  free(nine_hundred);

  free(one);
  free(twenty);
  free(thirty);
  free(three_hundred);

  symbols_destroy(symbols);

  return EXIT_SUCCESS;
}
