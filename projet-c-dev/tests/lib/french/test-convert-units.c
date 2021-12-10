#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <french/french.h>

int main(void) {
  char *zero_str = convert_units(0);
  char *one_str = convert_units(1);
  char *two_str = convert_units(2);
  char *three_str = convert_units(3);
  char *four_str = convert_units(4);
  char *five_str = convert_units(5);
  char *six_str = convert_units(6);
  char *seven_str = convert_units(7);
  char *eight_str = convert_units(8);
  char *nine_str = convert_units(9);

  assert(strcmp(zero_str, "zero") == 0);
  assert(strcmp(one_str, "un") == 0);
  assert(strcmp(two_str, "deux") == 0);
  assert(strcmp(three_str, "trois") == 0);
  assert(strcmp(four_str, "quatre") == 0);
  assert(strcmp(five_str, "cinq") == 0);
  assert(strcmp(six_str, "six") == 0);
  assert(strcmp(seven_str, "sept") == 0);
  assert(strcmp(eight_str, "huit") == 0);
  assert(strcmp(nine_str, "neuf") == 0);

  free(zero_str);
  free(one_str);
  free(two_str);
  free(three_str);
  free(four_str);
  free(five_str);
  free(six_str);
  free(seven_str);
  free(eight_str);
  free(nine_str);

  return EXIT_SUCCESS;
}

