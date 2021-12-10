#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <french/date.h>
#include <french/french.h>
#include <roman/roman.h>

int main(int argc, char *argv[]) {
  char *dialect;
  char *nptr;
  unsigned long number;

  if (argc != 3) {
    fprintf(stderr, "You need to specify %stwo arguments.\n", (argc > 3)? "only ": "");
    return EXIT_FAILURE;
  }

  dialect = argv[1];
  number = strtoul(argv[2], &nptr, 10);

  if (strcmp(dialect, "--roman") == 0 && !is_in_roman_range(number)) {
    fprintf(stderr, "The number entered must be between %d and %d for the roman dialect.\n", ROMAN_MIN, ROMAN_MAX);
    return EXIT_FAILURE;

  } else if (number >= 4000000000) {
    fprintf(stderr, "The number entered must be between 0 and 4000000000.\n");
    return EXIT_FAILURE;
  }

  if (strcmp(dialect, "--roman") == 0) {
    char *str = malloc(18 * sizeof(char));

    convert_to_roman(str, number);

    printf("%s\n", str);

    free(str);
  } else if (is_french_dialect(dialect)) {
    char *str = malloc(150 * sizeof(char));

    convert_to_french(str, number, dialect);

    printf("%s\n", str);

    free(str);
  } else if (strcmp(dialect, "--fr_FR_date") == 0) {
    char *str = malloc(150 * sizeof(char));

    convert_to_french_date(str, number);

    printf("%s\n", str);

    free(str);
  } else {
    printf("The indicated dialect does not exist.\n");

    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
