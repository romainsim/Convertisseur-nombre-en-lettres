#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <roman/roman.h>

void test_symbols(Symbols *symbols);
void test_no_symbols(Symbols *symbols);

int main(void) {
  Symbols *symbols = get_roman_symbols();

  test_symbols(symbols);
  test_no_symbols(symbols);

  symbols_destroy(symbols);

  return EXIT_SUCCESS;
}

void test_symbols(Symbols *symbols) {
  char *one = malloc(sizeof(char) * 2);
  char *five = malloc(sizeof(char) * 2);
  char *ten = malloc(sizeof(char) * 2);
  char *fifty = malloc(sizeof(char) * 2);
  char *one_hundred = malloc(sizeof(char) * 2);
  char *five_hundred = malloc(sizeof(char) * 2);
  char *one_thousand = malloc(sizeof(char) * 2);

  get_symbol(one, 1, symbols);
  get_symbol(five, 5, symbols);
  get_symbol(ten, 10, symbols);
  get_symbol(fifty, 50, symbols);
  get_symbol(one_hundred, 100, symbols);
  get_symbol(five_hundred, 500, symbols);
  get_symbol(one_thousand, 1000, symbols);

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

void test_no_symbols(Symbols* symbols) {
  char *two = malloc(sizeof(char) * 2);
  char *four = malloc(sizeof(char) * 2);
  char *twelve = malloc(sizeof(char) * 2);
  char *eighty_nine = malloc(sizeof(char) * 2);
  char *nine_hundred = malloc(sizeof(char) * 2);

  get_symbol(two, 2, symbols);
  get_symbol(four, 4, symbols);
  get_symbol(twelve, 12, symbols);
  get_symbol(eighty_nine, 89, symbols);
  get_symbol(nine_hundred, 900, symbols);

  assert(strlen(two) == 0);
  assert(strlen(four) == 0);
  assert(strlen(twelve) == 0);
  assert(strlen(eighty_nine) == 0);
  assert(strlen(nine_hundred) == 0);

  free(two);
  free(four);
  free(twelve);
  free(eighty_nine);
  free(nine_hundred);
}
