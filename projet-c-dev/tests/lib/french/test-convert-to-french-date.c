#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <french/date.h>

extern void test_before_thousand(void);
extern void test_date(void);
extern void test_after_two_thousand(void);

int main(void) {
  test_before_thousand();
  test_date();
  test_after_two_thousand();

  return EXIT_SUCCESS;
}

void test_before_thousand(void) {
  char *dest1 = malloc(50 * sizeof(char));
  char *dest2 = malloc(50 * sizeof(char));
  char *dest3 = malloc(50 * sizeof(char));
  char *dest4 = malloc(50 * sizeof(char));
  char *dest5 = malloc(50 * sizeof(char));

  convert_to_french_date(dest1, 0);
  convert_to_french_date(dest2, 36);
  convert_to_french_date(dest3, 745);
  convert_to_french_date(dest4, 298);
  convert_to_french_date(dest5, 500);

  assert(strcmp(dest1, "zero") == 0);
  assert(strcmp(dest2, "trente-six") == 0);
  assert(strcmp(dest3, "sept cent quarante-cinq") == 0);
  assert(strcmp(dest4, "deux cent quatre-vingt-dix-huit") == 0);
  assert(strcmp(dest5, "cinq cents") == 0);

  free(dest1);
  free(dest2);
  free(dest3);
  free(dest4);
  free(dest5);
}

void test_date(void) {
  char *dest1 = malloc(50 * sizeof(char));
  char *dest2 = malloc(50 * sizeof(char));
  char *dest3 = malloc(50 * sizeof(char));
  char *dest4 = malloc(50 * sizeof(char));
  char *dest5 = malloc(50 * sizeof(char));

  convert_to_french_date(dest1, 1000);
  convert_to_french_date(dest2, 1631);
  convert_to_french_date(dest3, 1768);
  convert_to_french_date(dest4, 1200);
  convert_to_french_date(dest5, 1800);

  assert(strcmp(dest1, "dix cents") == 0);
  assert(strcmp(dest2, "seize cent trente-et-un") == 0);
  assert(strcmp(dest3, "dix-sept cent soixante-huit") == 0);
  assert(strcmp(dest4, "douze cents") == 0);
  assert(strcmp(dest5, "dix-huit cents") == 0);

  free(dest1);
  free(dest2);
  free(dest3);
  free(dest4);
  free(dest5);
}

void test_after_two_thousand(void) {
  char *dest1 = malloc(50 * sizeof(char));
  char *dest2 = malloc(50 * sizeof(char));
  char *dest3 = malloc(50 * sizeof(char));
  char *dest4 = malloc(75 * sizeof(char));
  char *dest5 = malloc(75 * sizeof(char));

  convert_to_french_date(dest1, 3000);
  convert_to_french_date(dest2, 4448);
  convert_to_french_date(dest3, 96503);
  convert_to_french_date(dest4, 541669);
  convert_to_french_date(dest5, 6371558);

  assert(strcmp(dest1, "trois mille") == 0);
  assert(strcmp(dest2, "quatre mille quatre cent quarante-huit") == 0);
  assert(strcmp(dest3, "quatre-vingt-seize mille cinq cent trois") == 0);
  assert(strcmp(dest4, "cinq cent quarante-et-un mille six cent soixante-neuf") == 0);
  assert(strcmp(dest5, "six millions trois cent soixante-et-onze mille cinq cent cinquante-huit") == 0);

  free(dest1);
  free(dest2);
  free(dest3);
  free(dest4);
  free(dest5);
}
