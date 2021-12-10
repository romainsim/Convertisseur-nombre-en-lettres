#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <roman/roman.h>

int main(void) {
  Symbols *symbols = get_roman_symbols();

  char *two = malloc(16 * sizeof(char));
  char *eight = malloc(16 * sizeof(char));
  char *twenty = malloc(16 * sizeof(char));
  char *sixty = malloc(16 * sizeof(char));
  char *seven_hundred = malloc(16 * sizeof(char));

  convert_decomposition_addend_to_roman_additive(two, 2, symbols);
  convert_decomposition_addend_to_roman_additive(eight, 8, symbols);
  convert_decomposition_addend_to_roman_additive(twenty, 20, symbols);
  convert_decomposition_addend_to_roman_additive(sixty, 60, symbols);
  convert_decomposition_addend_to_roman_additive(seven_hundred, 700, symbols);

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

  symbols_destroy(symbols);

  return EXIT_SUCCESS;
}
