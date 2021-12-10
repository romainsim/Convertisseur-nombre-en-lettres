#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <french/french.h>

extern void test_one_digit_be(void);
extern void test_two_digits_round_be(void);
extern void test_two_digits_not_round_be(void);
extern void test_three_digits_be(void);

extern void test_one_digit_fr(void);
extern void test_two_digits_round_fr(void);
extern void test_two_digits_not_round_fr(void);
extern void test_three_digits_fr(void);

extern void test_one_digit_fr_african(void);
extern void test_two_digits_round_fr_african(void);
extern void test_two_digits_not_round_fr_african(void);
extern void test_three_digits_fr_african(void);

int main(void) {
  test_one_digit_be();
  test_two_digits_round_be();
  test_two_digits_not_round_be();
  test_three_digits_be();

  test_one_digit_fr();
  test_two_digits_round_fr();
  test_two_digits_not_round_fr();
  test_three_digits_fr();

  test_one_digit_fr_african();
  test_two_digits_round_fr_african();
  test_two_digits_not_round_fr_african();
  test_three_digits_fr_african();

  return EXIT_SUCCESS;
}

void test_one_digit_be(void) {
  char *one_str = convert_three_or_less_digits_number(1, "--fr_BE");
  char *two_str = convert_three_or_less_digits_number(2, "--fr_BE");
  char *three_str = convert_three_or_less_digits_number(3, "--fr_BE");
  char *four_str = convert_three_or_less_digits_number(4, "--fr_BE");
  char *five_str = convert_three_or_less_digits_number(5, "--fr_BE");
  char *six_str = convert_three_or_less_digits_number(6, "--fr_BE");
  char *seven_str = convert_three_or_less_digits_number(7, "--fr_BE");
  char *eight_str = convert_three_or_less_digits_number(8, "--fr_BE");
  char *nine_str = convert_three_or_less_digits_number(9, "--fr_BE");

  assert(strcmp(one_str, "un") == 0);
  assert(strcmp(two_str, "deux") == 0);
  assert(strcmp(three_str, "trois") == 0);
  assert(strcmp(four_str, "quatre") == 0);
  assert(strcmp(five_str, "cinq") == 0);
  assert(strcmp(six_str, "six") == 0);
  assert(strcmp(seven_str, "sept") == 0);
  assert(strcmp(eight_str, "huit") == 0);
  assert(strcmp(nine_str, "neuf") == 0);

  free(one_str);
  free(two_str);
  free(three_str);
  free(four_str);
  free(five_str);
  free(six_str);
  free(seven_str);
  free(eight_str);
  free(nine_str);
}

void test_two_digits_round_be(void) {
  char *ten_str = convert_three_or_less_digits_number(10, "--fr_BE");
  char *twenty_str = convert_three_or_less_digits_number(20, "--fr_BE");
  char *thirty_str = convert_three_or_less_digits_number(30, "--fr_BE");
  char *forty_str = convert_three_or_less_digits_number(40, "--fr_BE");
  char *fifty_str = convert_three_or_less_digits_number(50, "--fr_BE");
  char *sixty_str = convert_three_or_less_digits_number(60, "--fr_BE");
  char *seventy_str = convert_three_or_less_digits_number(70, "--fr_BE");
  char *eighty_str = convert_three_or_less_digits_number(80, "--fr_BE");
  char *ninety_str = convert_three_or_less_digits_number(90, "--fr_BE");

  assert(strcmp(ten_str, "dix") == 0);
  assert(strcmp(twenty_str, "vingt") == 0);
  assert(strcmp(thirty_str, "trente") == 0);
  assert(strcmp(forty_str, "quarante") == 0);
  assert(strcmp(fifty_str, "cinquante") == 0);
  assert(strcmp(sixty_str, "soixante") == 0);
  assert(strcmp(seventy_str, "septante") == 0);
  assert(strcmp(eighty_str, "quatre-vingts") == 0);
  assert(strcmp(ninety_str, "nonante") == 0);

  free(ten_str);
  free(twenty_str);
  free(thirty_str);
  free(forty_str);
  free(fifty_str);
  free(sixty_str);
  free(seventy_str);
  free(eighty_str);
  free(ninety_str);
}

void test_two_digits_not_round_be(void) {
  char *twenty_three_str = convert_three_or_less_digits_number(23, "--fr_BE");
  char *thirty_eight_str = convert_three_or_less_digits_number(38, "--fr_BE");
  char *fourty_two_str = convert_three_or_less_digits_number(42, "--fr_BE");
  char *fifty_six_str = convert_three_or_less_digits_number(56, "--fr_BE");
  char *sixty_one_str = convert_three_or_less_digits_number(61, "--fr_BE");
  char *seventy_four_str = convert_three_or_less_digits_number(74, "--fr_BE");
  char *eighty_five_str = convert_three_or_less_digits_number(85, "--fr_BE");
  char *ninety_seven_str = convert_three_or_less_digits_number(97, "--fr_BE");

  assert(strcmp(twenty_three_str, "vingt-trois") == 0);
  assert(strcmp(thirty_eight_str, "trente-huit") == 0);
  assert(strcmp(fourty_two_str, "quarante-deux") == 0);
  assert(strcmp(fifty_six_str, "cinquante-six") == 0);
  assert(strcmp(sixty_one_str, "soixante-et-un") == 0);
  assert(strcmp(seventy_four_str, "septante-quatre") == 0);
  assert(strcmp(eighty_five_str, "quatre-vingt-cinq") == 0);
  assert(strcmp(ninety_seven_str, "nonante-sept") == 0);

  free(twenty_three_str);
  free(thirty_eight_str);
  free(fourty_two_str);
  free(fifty_six_str);
  free(sixty_one_str);
  free(seventy_four_str);
  free(eighty_five_str);
  free(ninety_seven_str);
}

void test_three_digits_be(void) {
  char *one_hundred_str = convert_three_or_less_digits_number(100, "--fr_BE");
  char *two_hundred_six_str = convert_three_or_less_digits_number(206, "--fr_BE");
  char *three_hundred_seventy_seven_str = convert_three_or_less_digits_number(377, "--fr_BE");
  char *nine_hundred_fifteen_str = convert_three_or_less_digits_number(915, "--fr_BE");
  char *one_hundred_ninety_four_str = convert_three_or_less_digits_number(194, "--fr_BE");
  char *one_hundred_eight_str = convert_three_or_less_digits_number(138, "--fr_BE");
  char *eight_hundred_eight_str = convert_three_or_less_digits_number(808, "--fr_BE");
  char *five_hundred_str = convert_three_or_less_digits_number(500, "--fr_BE");

  assert(strcmp(one_hundred_str, "cent") == 0);
  assert(strcmp(two_hundred_six_str, "deux cent six") == 0);
  assert(strcmp(three_hundred_seventy_seven_str, "trois cent septante-sept") == 0);
  assert(strcmp(nine_hundred_fifteen_str, "neuf cent quinze") == 0);
  assert(strcmp(one_hundred_ninety_four_str, "cent nonante-quatre") == 0);
  assert(strcmp(one_hundred_eight_str, "cent trente-huit") == 0);
  assert(strcmp(eight_hundred_eight_str, "huit cent huit") == 0);
  assert(strcmp(five_hundred_str, "cinq cents") == 0);

  free(one_hundred_str);
  free(two_hundred_six_str);
  free(three_hundred_seventy_seven_str);
  free(nine_hundred_fifteen_str);
  free(one_hundred_ninety_four_str);
  free(one_hundred_eight_str);
  free(eight_hundred_eight_str);
  free(five_hundred_str);
}

void test_one_digit_fr(void) {
  char *one_str = convert_three_or_less_digits_number(1, "--fr_FR");
  char *two_str = convert_three_or_less_digits_number(2, "--fr_FR");
  char *three_str = convert_three_or_less_digits_number(3, "--fr_FR");
  char *four_str = convert_three_or_less_digits_number(4, "--fr_FR");
  char *five_str = convert_three_or_less_digits_number(5, "--fr_FR");
  char *six_str = convert_three_or_less_digits_number(6, "--fr_FR");
  char *seven_str = convert_three_or_less_digits_number(7, "--fr_FR");
  char *eight_str = convert_three_or_less_digits_number(8, "--fr_FR");
  char *nine_str = convert_three_or_less_digits_number(9, "--fr_FR");

  assert(strcmp(one_str, "un") == 0);
  assert(strcmp(two_str, "deux") == 0);
  assert(strcmp(three_str, "trois") == 0);
  assert(strcmp(four_str, "quatre") == 0);
  assert(strcmp(five_str, "cinq") == 0);
  assert(strcmp(six_str, "six") == 0);
  assert(strcmp(seven_str, "sept") == 0);
  assert(strcmp(eight_str, "huit") == 0);
  assert(strcmp(nine_str, "neuf") == 0);

  free(one_str);
  free(two_str);
  free(three_str);
  free(four_str);
  free(five_str);
  free(six_str);
  free(seven_str);
  free(eight_str);
  free(nine_str);
}

void test_two_digits_round_fr(void) {
  char *ten_str = convert_three_or_less_digits_number(10, "--fr_FR");
  char *twenty_str = convert_three_or_less_digits_number(20, "--fr_FR");
  char *thirty_str = convert_three_or_less_digits_number(30, "--fr_FR");
  char *forty_str = convert_three_or_less_digits_number(40, "--fr_FR");
  char *fifty_str = convert_three_or_less_digits_number(50, "--fr_FR");
  char *sixty_str = convert_three_or_less_digits_number(60, "--fr_FR");
  char *seventy_str = convert_three_or_less_digits_number(70, "--fr_FR");
  char *eighty_str = convert_three_or_less_digits_number(80, "--fr_FR");
  char *ninety_str = convert_three_or_less_digits_number(90, "--fr_FR");

  assert(strcmp(ten_str, "dix") == 0);
  assert(strcmp(twenty_str, "vingt") == 0);
  assert(strcmp(thirty_str, "trente") == 0);
  assert(strcmp(forty_str, "quarante") == 0);
  assert(strcmp(fifty_str, "cinquante") == 0);
  assert(strcmp(sixty_str, "soixante") == 0);
  assert(strcmp(seventy_str, "soixante-dix") == 0);
  assert(strcmp(eighty_str, "quatre-vingts") == 0);
  assert(strcmp(ninety_str, "quatre-vingt-dix") == 0);

  free(ten_str);
  free(twenty_str);
  free(thirty_str);
  free(forty_str);
  free(fifty_str);
  free(sixty_str);
  free(seventy_str);
  free(eighty_str);
  free(ninety_str);
}

void test_two_digits_not_round_fr(void) {
  char *twenty_three_str = convert_three_or_less_digits_number(23, "--fr_FR");
  char *thirty_eight_str = convert_three_or_less_digits_number(38, "--fr_FR");
  char *fourty_two_str = convert_three_or_less_digits_number(42, "--fr_FR");
  char *fifty_six_str = convert_three_or_less_digits_number(56, "--fr_FR");
  char *sixty_one_str = convert_three_or_less_digits_number(61, "--fr_FR");
  char *seventy_four_str = convert_three_or_less_digits_number(74, "--fr_FR");
  char *eighty_five_str = convert_three_or_less_digits_number(85, "--fr_FR");
  char *ninety_seven_str = convert_three_or_less_digits_number(97, "--fr_FR");

  assert(strcmp(twenty_three_str, "vingt-trois") == 0);
  assert(strcmp(thirty_eight_str, "trente-huit") == 0);
  assert(strcmp(fourty_two_str, "quarante-deux") == 0);
  assert(strcmp(fifty_six_str, "cinquante-six") == 0);
  assert(strcmp(sixty_one_str, "soixante-et-un") == 0);
  assert(strcmp(seventy_four_str, "soixante-quatorze") == 0);
  assert(strcmp(eighty_five_str, "quatre-vingt-cinq") == 0);
  assert(strcmp(ninety_seven_str, "quatre-vingt-dix-sept") == 0);

  free(twenty_three_str);
  free(thirty_eight_str);
  free(fourty_two_str);
  free(fifty_six_str);
  free(sixty_one_str);
  free(seventy_four_str);
  free(eighty_five_str);
  free(ninety_seven_str);
}

void test_three_digits_fr(void) {
  char *one_hundred_str = convert_three_or_less_digits_number(100, "--fr_FR");
  char *two_hundred_six_str = convert_three_or_less_digits_number(206, "--fr_FR");
  char *three_hundred_seventy_seven_str = convert_three_or_less_digits_number(377, "--fr_FR");
  char *nine_hundred_fifteen_str = convert_three_or_less_digits_number(915, "--fr_FR");
  char *one_hundred_ninety_four_str = convert_three_or_less_digits_number(194, "--fr_FR");
  char *one_hundred_eight_str = convert_three_or_less_digits_number(138, "--fr_FR");
  char *eight_hundred_eight_str = convert_three_or_less_digits_number(808, "--fr_FR");
  char *five_hundred_str = convert_three_or_less_digits_number(500, "--fr_FR");

  assert(strcmp(one_hundred_str, "cent") == 0);
  assert(strcmp(two_hundred_six_str, "deux cent six") == 0);
  assert(strcmp(three_hundred_seventy_seven_str, "trois cent soixante-dix-sept") == 0);
  assert(strcmp(nine_hundred_fifteen_str, "neuf cent quinze") == 0);
  assert(strcmp(one_hundred_ninety_four_str, "cent quatre-vingt-quatorze") == 0);
  assert(strcmp(one_hundred_eight_str, "cent trente-huit") == 0);
  assert(strcmp(eight_hundred_eight_str, "huit cent huit") == 0);
  assert(strcmp(five_hundred_str, "cinq cents") == 0);

  free(one_hundred_str);
  free(two_hundred_six_str);
  free(three_hundred_seventy_seven_str);
  free(nine_hundred_fifteen_str);
  free(one_hundred_ninety_four_str);
  free(one_hundred_eight_str);
  free(eight_hundred_eight_str);
  free(five_hundred_str);
}

void test_one_digit_fr_african(void) {
  char *one_str = convert_three_or_less_digits_number(1, "--fr_FR_african");
  char *two_str = convert_three_or_less_digits_number(2, "--fr_FR_african");
  char *three_str = convert_three_or_less_digits_number(3, "--fr_FR_african");
  char *four_str = convert_three_or_less_digits_number(4, "--fr_FR_african");
  char *five_str = convert_three_or_less_digits_number(5, "--fr_FR_african");
  char *six_str = convert_three_or_less_digits_number(6, "--fr_FR_african");
  char *seven_str = convert_three_or_less_digits_number(7, "--fr_FR_african");
  char *eight_str = convert_three_or_less_digits_number(8, "--fr_FR_african");
  char *nine_str = convert_three_or_less_digits_number(9, "--fr_FR_african");

  assert(strcmp(one_str, "un") == 0);
  assert(strcmp(two_str, "deux") == 0);
  assert(strcmp(three_str, "trois") == 0);
  assert(strcmp(four_str, "quatre") == 0);
  assert(strcmp(five_str, "cinq") == 0);
  assert(strcmp(six_str, "six") == 0);
  assert(strcmp(seven_str, "sept") == 0);
  assert(strcmp(eight_str, "huit") == 0);
  assert(strcmp(nine_str, "neuf") == 0);

  free(one_str);
  free(two_str);
  free(three_str);
  free(four_str);
  free(five_str);
  free(six_str);
  free(seven_str);
  free(eight_str);
  free(nine_str);
}

void test_two_digits_round_fr_african(void) {
  char *ten_str = convert_three_or_less_digits_number(10, "--fr_FR_african");
  char *twenty_str = convert_three_or_less_digits_number(20, "--fr_FR_african");
  char *thirty_str = convert_three_or_less_digits_number(30, "--fr_FR_african");
  char *forty_str = convert_three_or_less_digits_number(40, "--fr_FR_african");
  char *fifty_str = convert_three_or_less_digits_number(50, "--fr_FR_african");
  char *sixty_str = convert_three_or_less_digits_number(60, "--fr_FR_african");
  char *seventy_str = convert_three_or_less_digits_number(70, "--fr_FR_african");
  char *eighty_str = convert_three_or_less_digits_number(80, "--fr_FR_african");
  char *ninety_str = convert_three_or_less_digits_number(90, "--fr_FR_african");

  assert(strcmp(ten_str, "dix") == 0);
  assert(strcmp(twenty_str, "vingt") == 0);
  assert(strcmp(thirty_str, "trente") == 0);
  assert(strcmp(forty_str, "quarante") == 0);
  assert(strcmp(fifty_str, "cinquante") == 0);
  assert(strcmp(sixty_str, "soixante") == 0);
  assert(strcmp(seventy_str, "soixante-dix") == 0);
  assert(strcmp(eighty_str, "quatre-vingts") == 0);
  assert(strcmp(ninety_str, "quatre-vingt-dix") == 0);

  free(ten_str);
  free(twenty_str);
  free(thirty_str);
  free(forty_str);
  free(fifty_str);
  free(sixty_str);
  free(seventy_str);
  free(eighty_str);
  free(ninety_str);
}

void test_two_digits_not_round_fr_african(void) {
  char *twenty_three_str = convert_three_or_less_digits_number(23, "--fr_FR_african");
  char *thirty_eight_str = convert_three_or_less_digits_number(38, "--fr_FR_african");
  char *fourty_two_str = convert_three_or_less_digits_number(42, "--fr_FR_african");
  char *fifty_six_str = convert_three_or_less_digits_number(56, "--fr_FR_african");
  char *sixty_one_str = convert_three_or_less_digits_number(61, "--fr_FR_african");
  char *seventy_four_str = convert_three_or_less_digits_number(74, "--fr_FR_african");
  char *eighty_five_str = convert_three_or_less_digits_number(85, "--fr_FR_african");
  char *ninety_seven_str = convert_three_or_less_digits_number(97, "--fr_FR_african");

  assert(strcmp(twenty_three_str, "vingt-et-trois") == 0);
  assert(strcmp(thirty_eight_str, "trente-et-huit") == 0);
  assert(strcmp(fourty_two_str, "quarante-et-deux") == 0);
  assert(strcmp(fifty_six_str, "cinquante-et-six") == 0);
  assert(strcmp(sixty_one_str, "soixante-et-un") == 0);
  assert(strcmp(seventy_four_str, "soixante-quatorze") == 0);
  assert(strcmp(eighty_five_str, "quatre-vingt-et-cinq") == 0);
  assert(strcmp(ninety_seven_str, "quatre-vingt-dix-et-sept") == 0);

  free(twenty_three_str);
  free(thirty_eight_str);
  free(fourty_two_str);
  free(fifty_six_str);
  free(sixty_one_str);
  free(seventy_four_str);
  free(eighty_five_str);
  free(ninety_seven_str);
}

void test_three_digits_fr_african(void) {
  char *one_hundred_str = convert_three_or_less_digits_number(100, "--fr_FR_african");
  char *two_hundred_six_str = convert_three_or_less_digits_number(206, "--fr_FR_african");
  char *three_hundred_seventy_seven_str = convert_three_or_less_digits_number(377, "--fr_FR_african");
  char *nine_hundred_fifteen_str = convert_three_or_less_digits_number(915, "--fr_FR_african");
  char *one_hundred_ninety_four_str = convert_three_or_less_digits_number(194, "--fr_FR_african");
  char *one_hundred_eight_str = convert_three_or_less_digits_number(138, "--fr_FR_african");
  char *eight_hundred_eight_str = convert_three_or_less_digits_number(808, "--fr_FR_african");
  char *five_hundred_str = convert_three_or_less_digits_number(500, "--fr_FR_african");

  assert(strcmp(one_hundred_str, "cent") == 0);
  assert(strcmp(two_hundred_six_str, "deux cent six") == 0);
  assert(strcmp(three_hundred_seventy_seven_str, "trois cent soixante-dix-et-sept") == 0);
  assert(strcmp(nine_hundred_fifteen_str, "neuf cent quinze") == 0);
  assert(strcmp(one_hundred_ninety_four_str, "cent quatre-vingt-quatorze") == 0);
  assert(strcmp(one_hundred_eight_str, "cent trente-et-huit") == 0);
  assert(strcmp(eight_hundred_eight_str, "huit cent huit") == 0);
  assert(strcmp(five_hundred_str, "cinq cents") == 0);

  free(one_hundred_str);
  free(two_hundred_six_str);
  free(three_hundred_seventy_seven_str);
  free(nine_hundred_fifteen_str);
  free(one_hundred_ninety_four_str);
  free(one_hundred_eight_str);
  free(eight_hundred_eight_str);
  free(five_hundred_str);
}
