#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <french/french.h>

extern void test_until_nineteen_be(void);
extern void test_higher_nineteen_be(void);

extern void test_until_nineteen_fr(void);
extern void test_higher_nineteen_fr(void);

extern void test_until_nineteen_fr_african(void);
extern void test_higher_nineteen_fr_african(void);

extern void test_wrong_number(void);
extern void test_wrong_dialect(void);

int main(void) {
  test_until_nineteen_be();
  test_higher_nineteen_be();

  test_until_nineteen_fr();
  test_higher_nineteen_fr();

  test_until_nineteen_fr_african();
  test_higher_nineteen_fr_african();

  test_wrong_number();
  test_wrong_dialect();

  return EXIT_SUCCESS;
}

void test_until_nineteen_be(void) {
  char *eleven_str = convert_not_round_two_digits_number(11, "--fr_BE");
  char *twelve_str = convert_not_round_two_digits_number(12, "--fr_BE");
  char *thirteen_str = convert_not_round_two_digits_number(13, "--fr_BE");
  char *fourteen_str = convert_not_round_two_digits_number(14, "--fr_BE");
  char *fifteen_str = convert_not_round_two_digits_number(15, "--fr_BE");
  char *sixteen_str = convert_not_round_two_digits_number(16, "--fr_BE");
  char *seventeen_str = convert_not_round_two_digits_number(17, "--fr_BE");
  char *eighteen_str = convert_not_round_two_digits_number(18, "--fr_BE");
  char *nineteen_str = convert_not_round_two_digits_number(19, "--fr_BE");

  assert(strcmp(eleven_str, "onze") == 0);
  assert(strcmp(twelve_str, "douze") == 0);
  assert(strcmp(thirteen_str, "treize") == 0);
  assert(strcmp(fourteen_str, "quatorze") == 0);
  assert(strcmp(fifteen_str, "quinze") == 0);
  assert(strcmp(sixteen_str, "seize") == 0);
  assert(strcmp(seventeen_str, "dix-sept") == 0);
  assert(strcmp(eighteen_str, "dix-huit") == 0);
  assert(strcmp(nineteen_str, "dix-neuf") == 0);

  free(eleven_str);
  free(twelve_str);
  free(thirteen_str);
  free(fourteen_str);
  free(fifteen_str);
  free(sixteen_str);
  free(seventeen_str);
  free(eighteen_str);
  free(nineteen_str);
}

void test_higher_nineteen_be(void) {
  char *twenty_three_str = convert_not_round_two_digits_number(23, "--fr_BE");
  char *thirty_eight_str = convert_not_round_two_digits_number(38, "--fr_BE");
  char *fourty_two_str = convert_not_round_two_digits_number(42, "--fr_BE");
  char *fifty_six_str = convert_not_round_two_digits_number(56, "--fr_BE");
  char *sixty_one_str = convert_not_round_two_digits_number(61, "--fr_BE");
  char *seventy_four_str = convert_not_round_two_digits_number(74, "--fr_BE");
  char *eighty_five_str = convert_not_round_two_digits_number(85, "--fr_BE");
  char *ninety_seven_str = convert_not_round_two_digits_number(97, "--fr_BE");

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

void test_until_nineteen_fr(void) {
  char *eleven_str = convert_not_round_two_digits_number(11, "--fr_FR");
  char *twelve_str = convert_not_round_two_digits_number(12, "--fr_FR");
  char *thirteen_str = convert_not_round_two_digits_number(13, "--fr_FR");
  char *fourteen_str = convert_not_round_two_digits_number(14, "--fr_FR");
  char *fifteen_str = convert_not_round_two_digits_number(15, "--fr_FR");
  char *sixteen_str = convert_not_round_two_digits_number(16, "--fr_FR");
  char *seventeen_str = convert_not_round_two_digits_number(17, "--fr_FR");
  char *eighteen_str = convert_not_round_two_digits_number(18, "--fr_FR");
  char *nineteen_str = convert_not_round_two_digits_number(19, "--fr_FR");

  assert(strcmp(eleven_str, "onze") == 0);
  assert(strcmp(twelve_str, "douze") == 0);
  assert(strcmp(thirteen_str, "treize") == 0);
  assert(strcmp(fourteen_str, "quatorze") == 0);
  assert(strcmp(fifteen_str, "quinze") == 0);
  assert(strcmp(sixteen_str, "seize") == 0);
  assert(strcmp(seventeen_str, "dix-sept") == 0);
  assert(strcmp(eighteen_str, "dix-huit") == 0);
  assert(strcmp(nineteen_str, "dix-neuf") == 0);

  free(eleven_str);
  free(twelve_str);
  free(thirteen_str);
  free(fourteen_str);
  free(fifteen_str);
  free(sixteen_str);
  free(seventeen_str);
  free(eighteen_str);
  free(nineteen_str);
}

void test_higher_nineteen_fr(void) {
  char *twenty_three_str = convert_not_round_two_digits_number(23, "--fr_FR");
  char *thirty_eight_str = convert_not_round_two_digits_number(38, "--fr_FR");
  char *fourty_two_str = convert_not_round_two_digits_number(42, "--fr_FR");
  char *fifty_six_str = convert_not_round_two_digits_number(56, "--fr_FR");
  char *sixty_one_str = convert_not_round_two_digits_number(61, "--fr_FR");
  char *seventy_four_str = convert_not_round_two_digits_number(74, "--fr_FR");
  char *eighty_five_str = convert_not_round_two_digits_number(85, "--fr_FR");
  char *ninety_seven_str = convert_not_round_two_digits_number(97, "--fr_FR");

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

void test_until_nineteen_fr_african(void) {
  char *eleven_str = convert_not_round_two_digits_number(11, "--fr_FR_african");
  char *twelve_str = convert_not_round_two_digits_number(12, "--fr_FR_african");
  char *thirteen_str = convert_not_round_two_digits_number(13, "--fr_FR_african");
  char *fourteen_str = convert_not_round_two_digits_number(14, "--fr_FR_african");
  char *fifteen_str = convert_not_round_two_digits_number(15, "--fr_FR_african");
  char *sixteen_str = convert_not_round_two_digits_number(16, "--fr_FR_african");
  char *seventeen_str = convert_not_round_two_digits_number(17, "--fr_FR_african");
  char *eighteen_str = convert_not_round_two_digits_number(18, "--fr_FR_african");
  char *nineteen_str = convert_not_round_two_digits_number(19, "--fr_FR_african");

  assert(strcmp(eleven_str, "onze") == 0);
  assert(strcmp(twelve_str, "douze") == 0);
  assert(strcmp(thirteen_str, "treize") == 0);
  assert(strcmp(fourteen_str, "quatorze") == 0);
  assert(strcmp(fifteen_str, "quinze") == 0);
  assert(strcmp(sixteen_str, "seize") == 0);
  assert(strcmp(seventeen_str, "dix-et-sept") == 0);
  assert(strcmp(eighteen_str, "dix-et-huit") == 0);
  assert(strcmp(nineteen_str, "dix-et-neuf") == 0);

  free(eleven_str);
  free(twelve_str);
  free(thirteen_str);
  free(fourteen_str);
  free(fifteen_str);
  free(sixteen_str);
  free(seventeen_str);
  free(eighteen_str);
  free(nineteen_str);
}

void test_higher_nineteen_fr_african(void) {
  char *twenty_three_str = convert_not_round_two_digits_number(23, "--fr_FR_african");
  char *thirty_eight_str = convert_not_round_two_digits_number(38, "--fr_FR_african");
  char *fourty_two_str = convert_not_round_two_digits_number(42, "--fr_FR_african");
  char *fifty_six_str = convert_not_round_two_digits_number(56, "--fr_FR_african");
  char *sixty_one_str = convert_not_round_two_digits_number(61, "--fr_FR_african");
  char *seventy_four_str = convert_not_round_two_digits_number(74, "--fr_FR_african");
  char *eighty_five_str = convert_not_round_two_digits_number(85, "--fr_FR_african");
  char *ninety_seven_str = convert_not_round_two_digits_number(97, "--fr_FR_african");

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

void test_wrong_number(void) {
  char *one_str = convert_not_round_two_digits_number(1, "--fr_FR");
  char *eight_str = convert_not_round_two_digits_number(8, "--fr_BE");
  char *two_hundred_twenty_five_str = convert_not_round_two_digits_number(225, "--fr_FR");
  char *three_hundred_eighteen_str = convert_not_round_two_digits_number(318, "--fr_BE");

  char *ten_str = convert_not_round_two_digits_number(10, "--fr_FR");
  char *twenty_str = convert_not_round_two_digits_number(20, "--fr_FR");
  char *thirty_str = convert_not_round_two_digits_number(30, "--fr_BE");
  char *fourty_str = convert_not_round_two_digits_number(40, "--fr_BE");
  char *fifty_str = convert_not_round_two_digits_number(50, "--fr_FR");
  char *sixty_str = convert_not_round_two_digits_number(60, "--fr_BE");
  char *seventy_str = convert_not_round_two_digits_number(70, "--fr_FR");
  char *eighty_str = convert_not_round_two_digits_number(80, "--fr_BE");
  char *ninety_str = convert_not_round_two_digits_number(90, "--fr_FR");

  assert(strlen(one_str) == 0);
  assert(strlen(eight_str) == 0);
  assert(strlen(two_hundred_twenty_five_str) == 0);
  assert(strlen(three_hundred_eighteen_str) == 0);

  assert(strlen(ten_str) == 0);
  assert(strlen(twenty_str) == 0);
  assert(strlen(thirty_str) == 0);
  assert(strlen(fourty_str) == 0);
  assert(strlen(fifty_str) == 0);
  assert(strlen(sixty_str) == 0);
  assert(strlen(seventy_str) == 0);
  assert(strlen(eighty_str) == 0);
  assert(strlen(ninety_str) == 0);

  free(one_str);
  free(eight_str);
  free(two_hundred_twenty_five_str);
  free(three_hundred_eighteen_str);

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

void test_wrong_dialect(void) {
  char *fourty_two_str = convert_not_round_two_digits_number(42, "--fr_GS");
  char *fifty_six_str = convert_not_round_two_digits_number(56, "--hqsd");
  char *sixty_one_str = convert_not_round_two_digits_number(61, "dks");
  char *seventy_four_str = convert_not_round_two_digits_number(74, "");

  assert(strlen(fourty_two_str) == 0);
  assert(strlen(fifty_six_str) == 0);
  assert(strlen(sixty_one_str) == 0);
  assert(strlen(seventy_four_str) == 0);

  free(fourty_two_str);
  free(fifty_six_str);
  free(sixty_one_str);
  free(seventy_four_str);
}
