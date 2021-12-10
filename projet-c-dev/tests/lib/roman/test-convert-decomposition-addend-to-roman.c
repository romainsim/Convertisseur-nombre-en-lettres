#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <roman/roman.h>

extern void test_roots(Symbols *symbols);
extern void test_additive(Symbols *symbols);
extern void test_substractive(Symbols *symbols);

int main(void) {
  Symbols *symbols = get_roman_symbols();

  test_roots(symbols);
  test_additive(symbols);
  test_substractive(symbols);

  symbols_destroy(symbols);

  return EXIT_SUCCESS;
}

void test_roots(Symbols *symbols) {
  char *one = malloc(sizeof(char) * 2);
  char *five = malloc(sizeof(char) * 2);
  char *ten = malloc(sizeof(char) * 2);
  char *fifty = malloc(sizeof(char) * 2);
  char *one_hundred = malloc(sizeof(char) * 2);
  char *five_hundred = malloc(sizeof(char) * 2);
  char *one_thousand = malloc(sizeof(char) * 2);

  convert_decomposition_addend_to_roman(one, 1, symbols);
  convert_decomposition_addend_to_roman(five, 5, symbols);
  convert_decomposition_addend_to_roman(ten, 10, symbols);
  convert_decomposition_addend_to_roman(fifty, 50, symbols);
  convert_decomposition_addend_to_roman(one_hundred, 100, symbols);
  convert_decomposition_addend_to_roman(five_hundred, 500, symbols);
  convert_decomposition_addend_to_roman(one_thousand, 1000, symbols);

  assert(strcmp(one, "I") == 0);
  assert(strcmp(five, "V") == 0);
  assert(strcmp(ten, "X") == 0);
  assert(strcmp(fifty, "L") == 0);
  assert(strcmp(one_hundred, "C") == 0);
  assert(strcmp(five_hundred, "D") == 0);
  assert(strcmp(one_thousand, "M") == 0);

  free(one);
  free(five);
  free(ten);
  free(fifty);
  free(one_hundred);
  free(five_hundred);
  free(one_thousand);
}

void test_additive(Symbols *symbols) {
  char *two = malloc(16 * sizeof(char));
  char *eight = malloc(16 * sizeof(char));
  char *twenty = malloc(16 * sizeof(char));
  char *sixty = malloc(16 * sizeof(char));
  char *seven_hundred = malloc(16 * sizeof(char));

  convert_decomposition_addend_to_roman(two, 2, symbols);
  convert_decomposition_addend_to_roman(eight, 8, symbols);
  convert_decomposition_addend_to_roman(twenty, 20, symbols);
  convert_decomposition_addend_to_roman(sixty, 60, symbols);
  convert_decomposition_addend_to_roman(seven_hundred, 700, symbols);

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

  convert_decomposition_addend_to_roman(four, 4, symbols);
  convert_decomposition_addend_to_roman(nine, 9, symbols);
  convert_decomposition_addend_to_roman(fourty, 40, symbols);
  convert_decomposition_addend_to_roman(four_hundred, 400, symbols);
  convert_decomposition_addend_to_roman(nine_hundred, 900, symbols);

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
