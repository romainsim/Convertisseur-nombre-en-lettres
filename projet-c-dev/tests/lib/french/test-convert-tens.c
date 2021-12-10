#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <french/french.h>

extern void test_be(void);
extern void test_fr(void);
extern void test_fr_african(void);

extern void test_wrong_number(void);
extern void test_wrong_dialect(void);

int main(void) {
  test_be();
  test_fr();
  test_fr_african();

  test_wrong_number();
  test_wrong_dialect();

  return EXIT_SUCCESS;
}

void test_be(void) {
  char *ten_str = convert_tens(10, "--fr_BE");
  char *twenty_str = convert_tens(20, "--fr_BE");
  char *thirty_str = convert_tens(30, "--fr_BE");
  char *fourty_str = convert_tens(40, "--fr_BE");
  char *fifty_str = convert_tens(50, "--fr_BE");
  char *sixty_str = convert_tens(60, "--fr_BE");
  char *seventy_str = convert_tens(70, "--fr_BE");
  char *eighty_str = convert_tens(80, "--fr_BE");
  char *ninety_str = convert_tens(90, "--fr_BE");

  assert(strcmp(ten_str, "dix") == 0);
  assert(strcmp(twenty_str, "vingt") == 0);
  assert(strcmp(thirty_str, "trente") == 0);
  assert(strcmp(fourty_str, "quarante") == 0);
  assert(strcmp(fifty_str, "cinquante") == 0);
  assert(strcmp(sixty_str, "soixante") == 0);
  assert(strcmp(seventy_str, "septante") == 0);
  assert(strcmp(eighty_str, "quatre-vingts") == 0);
  assert(strcmp(ninety_str, "nonante") == 0);

  free(ten_str);
  free(twenty_str);
  free(thirty_str);
  free(fourty_str);
  free(fifty_str);
  free(sixty_str);
  free(seventy_str);
  free(eighty_str);
  free(ninety_str);
}

void test_fr(void) {
  char *ten_str = convert_tens(10, "--fr_FR");
  char *twenty_str = convert_tens(20, "--fr_FR");
  char *thirty_str = convert_tens(30, "--fr_FR");
  char *fourty_str = convert_tens(40, "--fr_FR");
  char *fifty_str = convert_tens(50, "--fr_FR");
  char *sixty_str = convert_tens(60, "--fr_FR");
  char *seventy_str = convert_tens(70, "--fr_FR");
  char *eighty_str = convert_tens(80, "--fr_FR");
  char *ninety_str = convert_tens(90, "--fr_FR");

  assert(strcmp(ten_str, "dix") == 0);
  assert(strcmp(twenty_str, "vingt") == 0);
  assert(strcmp(thirty_str, "trente") == 0);
  assert(strcmp(fourty_str, "quarante") == 0);
  assert(strcmp(fifty_str, "cinquante") == 0);
  assert(strcmp(sixty_str, "soixante") == 0);
  assert(strcmp(seventy_str, "soixante-dix") == 0);
  assert(strcmp(eighty_str, "quatre-vingts") == 0);
  assert(strcmp(ninety_str, "quatre-vingt-dix") == 0);

  free(ten_str);
  free(twenty_str);
  free(thirty_str);
  free(fourty_str);
  free(fifty_str);
  free(sixty_str);
  free(seventy_str);
  free(eighty_str);
  free(ninety_str);
}

void test_fr_african(void) {
  char *ten_str = convert_tens(10, "--fr_FR_african");
  char *twenty_str = convert_tens(20, "--fr_FR_african");
  char *thirty_str = convert_tens(30, "--fr_FR_african");
  char *fourty_str = convert_tens(40, "--fr_FR_african");
  char *fifty_str = convert_tens(50, "--fr_FR_african");
  char *sixty_str = convert_tens(60, "--fr_FR_african");
  char *seventy_str = convert_tens(70, "--fr_FR_african");
  char *eighty_str = convert_tens(80, "--fr_FR_african");
  char *ninety_str = convert_tens(90, "--fr_FR_african");

  assert(strcmp(ten_str, "dix") == 0);
  assert(strcmp(twenty_str, "vingt") == 0);
  assert(strcmp(thirty_str, "trente") == 0);
  assert(strcmp(fourty_str, "quarante") == 0);
  assert(strcmp(fifty_str, "cinquante") == 0);
  assert(strcmp(sixty_str, "soixante") == 0);
  assert(strcmp(seventy_str, "soixante-dix") == 0);
  assert(strcmp(eighty_str, "quatre-vingts") == 0);
  assert(strcmp(ninety_str, "quatre-vingt-dix") == 0);

  free(ten_str);
  free(twenty_str);
  free(thirty_str);
  free(fourty_str);
  free(fifty_str);
  free(sixty_str);
  free(seventy_str);
  free(eighty_str);
  free(ninety_str);
}

void test_wrong_number(void) {
  char *three_str = convert_tens(3, "--fr_BE");
  char *five_str = convert_tens(5, "--fr_FR");
  char *seven_str = convert_tens(7, "--fr_FR_african");
  char *thirty_two_str = convert_tens(32, "--fr_BE");
  char *eighty_nine_str = convert_tens(89, "--fr_FR");
  char *seventy_three_str = convert_tens(73, "--fr_FR_african");
  char *fiveHundred_str = convert_tens(500, "--fr_BE");
  char *two_hundred_thirty_five_str = convert_tens(235, "--fr_FR");
  char *six_hundred_thirty_height_str = convert_tens(638, "--fr_FR_african");

  assert(strlen(three_str) == 0);
  assert(strlen(five_str) == 0);
  assert(strlen(seven_str) == 0);
  assert(strlen(thirty_two_str) == 0);
  assert(strlen(eighty_nine_str) == 0);
  assert(strlen(seventy_three_str) == 0);
  assert(strlen(fiveHundred_str) == 0);
  assert(strlen(two_hundred_thirty_five_str) == 0);
  assert(strlen(six_hundred_thirty_height_str) == 0);

  free(three_str);
  free(five_str);
  free(seven_str);
  free(thirty_two_str);
  free(eighty_nine_str);
  free(seventy_three_str);
  free(fiveHundred_str);
  free(two_hundred_thirty_five_str);
  free(six_hundred_thirty_height_str);
}

void test_wrong_dialect(void) {
  char *ten_str = convert_tens(10, "--asdfj");
  char *twenty_str = convert_tens(20, "fr_EH");
  char *thirty_str = convert_tens(30, "--rf_BE");
  char *fourty_str = convert_tens(40, "roman");
  char *fifty_str = convert_tens(50, "ja");
  char *sixty_str = convert_tens(60, "--ufjwe");
  char *seventy_str = convert_tens(70, "");
  char *eighty_str = convert_tens(80, "--sdE");
  char *ninety_str = convert_tens(90, "rk");

  assert(strlen(ten_str) == 0);
  assert(strlen(twenty_str) == 0);
  assert(strlen(thirty_str) == 0);
  assert(strlen(fourty_str) == 0);
  assert(strlen(fifty_str) == 0);
  assert(strlen(sixty_str) == 0);
  assert(strlen(seventy_str) == 0);
  assert(strlen(eighty_str) == 0);
  assert(strlen(ninety_str) == 0);

  free(ten_str);
  free(twenty_str);
  free(thirty_str);
  free(fourty_str);
  free(fifty_str);
  free(sixty_str);
  free(seventy_str);
  free(eighty_str);
  free(ninety_str);
}
