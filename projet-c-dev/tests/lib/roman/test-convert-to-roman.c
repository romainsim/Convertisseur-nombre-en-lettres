#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <roman/roman.h>

void test_valid_numbers(void);
void test_wrong_numbers(void);

int main(void) {
  test_valid_numbers();
  test_wrong_numbers();

  return EXIT_SUCCESS;
}

void test_valid_numbers(void) {
  char *one = malloc(sizeof(char) * 18);
  char *two_hundred_twenty_two = malloc(sizeof(char) * 18);
  char *four_hundred = malloc(sizeof(char) * 18);
  char *three_thousand_seventeen = malloc(sizeof(char) * 18);

  convert_to_roman(one, 1);
  convert_to_roman(two_hundred_twenty_two, 222);
  convert_to_roman(four_hundred, 400);
  convert_to_roman(three_thousand_seventeen, 3017);

  assert(strcmp(one, "I") == 0);
  assert(strcmp(two_hundred_twenty_two, "CCXXII") == 0);
  assert(strcmp(four_hundred, "CD") == 0);
  assert(strcmp(three_thousand_seventeen, "MMMXVII") == 0);

  free(one);
  free(two_hundred_twenty_two);
  free(four_hundred);
  free(three_thousand_seventeen);
}

void test_wrong_numbers(void) {
  char *zero = malloc(sizeof(char) * 18);
  char *five_thousand = malloc(sizeof(char) * 18);
  char *five_thousand_five = malloc(sizeof(char) * 18);
  char *five_thousand_twenty = malloc(sizeof(char) * 18);
  char *six_thousand = malloc(sizeof(char) * 18);

  convert_to_roman(zero, 0);
  convert_to_roman(five_thousand, 5000);
  convert_to_roman(five_thousand_five, 5005);
  convert_to_roman(five_thousand_twenty, 5020);
  convert_to_roman(six_thousand, 6000);

  assert(strlen(zero) == 0);
  assert(strlen(five_thousand) == 0);
  assert(strlen(five_thousand_five) == 0);
  assert(strlen(five_thousand_twenty) == 0);
  assert(strlen(six_thousand) == 0);

  free(zero);
  free(five_thousand);
  free(five_thousand_five);
  free(five_thousand_twenty);
  free(six_thousand);
}

