#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <french/french.h>

extern void test_in_be(void);
extern void test_in_fr(void);
extern void test_in_african(void);

int main(void) {
  test_in_be();
  test_in_fr();
  test_in_african();

  return EXIT_SUCCESS;
}

void test_in_be(void) {
  char *zero = malloc(50 * sizeof(char));
  char *seven = malloc(50 * sizeof(char));
  char *eighty = malloc(50 * sizeof(char));
  char *one_hundred = malloc(50 * sizeof(char));
  char *one_hundred_three = malloc(50 * sizeof(char));
  char *unwritable1 = malloc(75 * sizeof(char));
  char *unwritable2 = malloc(75 * sizeof(char));

  convert_to_french(zero, 0, "--fr_BE");
  convert_to_french(seven, 7, "--fr_BE");
  convert_to_french(eighty, 80, "--fr_BE");
  convert_to_french(one_hundred, 100, "--fr_BE");
  convert_to_french(one_hundred_three, 173, "--fr_BE");
  convert_to_french(unwritable1, 1928, "--fr_BE");
  convert_to_french(unwritable2, 13938, "--fr_BE");

  assert(strcmp(zero, "zero") == 0);
  assert(strcmp(seven, "sept") == 0);
  assert(strcmp(eighty, "quatre-vingts") == 0);
  assert(strcmp(one_hundred, "cent") == 0);
  assert(strcmp(one_hundred_three, "cent septante-trois") == 0);
  assert(strcmp(unwritable1, "mille neuf cent vingt-huit") == 0);
  assert(strcmp(unwritable2, "treize mille neuf cent trente-huit") == 0);

  free(zero);
  free(seven);
  free(eighty);
  free(one_hundred);
  free(one_hundred_three);
  free(unwritable1);
  free(unwritable2);
}

void test_in_fr(void) {
  char *zero = malloc(50 * sizeof(char));
  char *seven = malloc(50 * sizeof(char));
  char *eighty = malloc(50 * sizeof(char));
  char *one_hundred = malloc(50 * sizeof(char));
  char *one_hundred_three = malloc(50 * sizeof(char));
  char *unwritable1 = malloc(75 * sizeof(char));
  char *unwritable2 = malloc(75 * sizeof(char));

  convert_to_french(zero, 0, "--fr_FR");
  convert_to_french(seven, 7, "--fr_FR");
  convert_to_french(eighty, 80, "--fr_FR");
  convert_to_french(one_hundred, 100, "--fr_FR");
  convert_to_french(one_hundred_three, 173, "--fr_FR");
  convert_to_french(unwritable1, 1928, "--fr_FR");
  convert_to_french(unwritable2, 13938, "--fr_FR");

  assert(strcmp(zero, "zero") == 0);
  assert(strcmp(seven, "sept") == 0);
  assert(strcmp(eighty, "quatre-vingts") == 0);
  assert(strcmp(one_hundred, "cent") == 0);
  assert(strcmp(one_hundred_three, "cent soixante-treize") == 0);
  assert(strcmp(unwritable1, "mille neuf cent vingt-huit") == 0);
  assert(strcmp(unwritable2, "treize mille neuf cent trente-huit") == 0);

  free(zero);
  free(seven);
  free(eighty);
  free(one_hundred);
  free(one_hundred_three);
  free(unwritable1);
  free(unwritable2);
}

void test_in_african(void) {
  char *zero = malloc(50 * sizeof(char));
  char *seven = malloc(50 * sizeof(char));
  char *eighty = malloc(50 * sizeof(char));
  char *one_hundred = malloc(50 * sizeof(char));
  char *one_hundred_three = malloc(50 * sizeof(char));
  char *unwritable1 = malloc(75 * sizeof(char));
  char *unwritable2 = malloc(75 * sizeof(char));

  convert_to_french(zero, 0, "--fr_FR_african");
  convert_to_french(seven, 7, "--fr_FR_african");
  convert_to_french(eighty, 80, "--fr_FR_african");
  convert_to_french(one_hundred, 100, "--fr_FR_african");
  convert_to_french(one_hundred_three, 173, "--fr_FR_african");
  convert_to_french(unwritable1, 1928, "--fr_FR_african");
  convert_to_french(unwritable2, 13938, "--fr_FR_african");

  assert(strcmp(zero, "zero") == 0);
  assert(strcmp(seven, "sept") == 0);
  assert(strcmp(eighty, "quatre-vingts") == 0);
  assert(strcmp(one_hundred, "cent") == 0);
  assert(strcmp(one_hundred_three, "cent soixante-treize") == 0);
  assert(strcmp(unwritable1, "mille neuf cent vingt-et-huit") == 0);
  assert(strcmp(unwritable2, "treize mille neuf cent trente-et-huit") == 0);

  free(zero);
  free(seven);
  free(eighty);
  free(one_hundred);
  free(one_hundred_three);
  free(unwritable1);
  free(unwritable2);
}
