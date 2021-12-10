#include "./french.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./../decomposition/decomposition.inc"

bool is_french_dialect(char *dialect) {
  if (strcmp(dialect, "--fr_FR") == 0 || strcmp(dialect, "--fr_BE") == 0 || strcmp(dialect, "--fr_FR_african") == 0) {
    return true;
  }

  return false;
}

char *convert_units(unsigned long number) {
  char *digit = malloc(10 * sizeof(char));

  if (digit == NULL) {
    return NULL;
  }

  switch (number) {
    case 0:
      strcpy(digit, "zero");
      break;
    case 1:
      strcpy(digit, "un");
      break;
    case 2:
      strcpy(digit, "deux");
      break;
    case 3:
      strcpy(digit, "trois");
      break;
    case 4:
      strcpy(digit, "quatre");
      break;
    case 5:
      strcpy(digit, "cinq");
      break;
    case 6:
      strcpy(digit, "six");
      break;
    case 7:
      strcpy(digit, "sept");
      break;
    case 8:
      strcpy(digit, "huit");
      break;
    case 9:
      strcpy(digit, "neuf");
      break;
  }

  return digit;
}

char *convert_tens(unsigned long number, char *dialect) {
  char *result_str = malloc(50 * sizeof(char));

  if (result_str == NULL) {
    return NULL;
  }

  strcpy(result_str, "");

  if (is_french_dialect(dialect)) {
    switch (number) {
      case 10:
        strcpy(result_str, "dix");
        break;
      case 20:
        strcpy(result_str, "vingt");
        break;
      case 30:
        strcpy(result_str, "trente");
        break;
      case 40:
        strcpy(result_str, "quarante");
        break;
      case 50:
        strcpy(result_str, "cinquante");
        break;
      case 60:
        strcpy(result_str, "soixante");
        break;
      case 70:
        if (strcmp(dialect, "--fr_BE") == 0) {
          strcpy(result_str, "septante");
        } else {
          strcpy(result_str, "soixante-dix");
        }
        break;
      case 80:
        strcpy(result_str, "quatre-vingts");
        break;
      case 90:
        if (strcmp(dialect, "--fr_BE") == 0) {
          strcpy(result_str, "nonante");
        } else {
          strcpy(result_str, "quatre-vingt-dix");
        }
        break;
    }
  }

  return result_str;
}

char *convert_not_round_two_digits_number(unsigned long number, char *dialect) {
  char *result_str = malloc(50 * sizeof(char));

  if (result_str == NULL) {
    return NULL;
  }

  strcpy(result_str, "");

  Decomposition *decomposition = decompose(number);

  if (decomposition == NULL) {
    free(result_str);

    return NULL;
  }

  if (decomposition_get_addends_len(decomposition) != 2 || !is_french_dialect(dialect)) {
    decomposition_destroy(decomposition);

    return result_str;
  }

  switch (number) {
    case 11:
      strcpy(result_str, "onze");
      break;
    case 12:
      strcpy(result_str, "douze");
      break;
    case 13:
      strcpy(result_str, "treize");
      break;
    case 14:
      strcpy(result_str, "quatorze");
      break;
    case 15:
      strcpy(result_str, "quinze");
      break;
    case 16:
      strcpy(result_str, "seize");
      break;
    default:;  // semi-colon to avoid "declaration after label error"
      unsigned long *addends = decomposition_get_addends(decomposition);

      unsigned long tens = addends[0];
      unsigned long units = addends[1];

      char *tens_str;
      char *units_str;

      if (strcmp(dialect, "--fr_BE") == 0 || (tens != 70 && tens != 90)) {
        if (tens == 80) {
          tens_str = malloc(13 * sizeof(char));

          if (tens_str == NULL) {
            free(result_str);

            return NULL;
          }

          strcpy(tens_str, "quatre-vingt");
        } else {
          tens_str = convert_tens(tens, dialect);
        }

        units_str = convert_units(units);
      } else {
        tens_str = malloc(13 * sizeof(char));

        if (tens_str == NULL) {
          free(result_str);

          return NULL;
        }

        if (tens == 70) {
          strcpy(tens_str, "soixante");
        } else {
          strcpy(tens_str, "quatre-vingt");
        }

        units_str = convert_not_round_two_digits_number(10 + units, dialect);
      }

      strcpy(result_str, tens_str);

      if ((units == 1 && tens < 80) || (strcmp(dialect, "--fr_FR_african") == 0 && (tens < 70 || tens == 80))) {
        strcat(result_str, "-et-");
      } else {
        strcat(result_str, "-");
      }

      strcat(result_str, units_str);

      free(tens_str);
      free(units_str);
  }

  decomposition_destroy(decomposition);

  return result_str;
}

char *convert_two_digits_number(unsigned long number, char *dialect) {
  char *result_str = malloc(50 * sizeof(char));

  strcpy(result_str, "");

  Decomposition *decomposition = decompose(number);

  if (decomposition == NULL) {
    free(result_str);

    return NULL;
  }

  unsigned int number_of_digits = decomposition_get_addends_len(decomposition);

  if (number_of_digits == 1 && is_french_dialect(dialect)) {
    char *substr = convert_tens(decomposition_get_addends(decomposition)[0], dialect);

    if (substr == NULL) {
      free(result_str);
      decomposition_destroy(decomposition);

      return NULL;
    }

    strcpy(result_str, substr);

    free(substr);

  } else if (number_of_digits == 2 && is_french_dialect(dialect)) {
    char *substr = convert_not_round_two_digits_number(number, dialect);

    if (substr == NULL) {
      free(result_str);
      decomposition_destroy(decomposition);

      return NULL;
    }

    strcpy(result_str, substr);

    free(substr);
  }

  decomposition_destroy(decomposition);

  return result_str;
}

char *convert_three_or_less_digits_number(unsigned long number, char *dialect) {
  char *text = malloc(150 * sizeof(char));

  if (text == NULL) {
    return NULL;
  }

  strcpy(text, "");

  unsigned int number_len = get_number_of_digits(number);

  Decomposition *decomposition = decompose(number);

  if (decomposition == NULL) {
    free(text);

    return NULL;
  }

  unsigned int addends_len = decomposition_get_addends_len(decomposition);
  unsigned long *addends = decomposition_get_addends(decomposition);

  unsigned int number_of_digits = 0;
  unsigned int digit = 0;

  if (number_len == 1) {
    char *substr = convert_units(number);

    if (substr == NULL) {
      free(text);
      decomposition_destroy(decomposition);

      return NULL;
    }

    strcat(text, substr);

    free(substr);
  } else if (number_len == 2) {
    char *substr = convert_two_digits_number(number, dialect);

    if (substr == NULL) {
      free(text);
      decomposition_destroy(decomposition);

      return NULL;
    }

    strcat(text, substr);

    free(substr);
  } else {
    for (unsigned int i = 0; i < addends_len; i++) {
      number_of_digits = get_number_of_digits(addends[i]);

      if (number_of_digits == 1) {
        char *substr = convert_units(addends[i]);

        if (substr == NULL) {
          free(text);
          decomposition_destroy(decomposition);

          return NULL;
        }

        strcat(text, substr);

        free(substr);
      } else if (number_of_digits == 2) {
        char *substr;

        if(i + 1 < addends_len) {
          substr = convert_two_digits_number(addends[i] + addends[i + 1], dialect);
        } else {
          substr = convert_two_digits_number(addends[i], dialect);
        }

        if (substr == NULL) {
          free(text);
          decomposition_destroy(decomposition);

          return NULL;
        }

        strcat(text, substr);

        free(substr);
        break;
      } else if (number_of_digits == 3) {
        digit = (int)(addends[i] / 100);

        if (digit != 1) {
          char *substr = convert_units(digit);

          if (substr == NULL) {
            free(text);
            decomposition_destroy(decomposition);

            return NULL;
          }

          strcat(text, substr);

          if (number % 100 == 0) {
            strcat(text, " cents");
          } else {
            strcat(text, " cent");
          }

          free(substr);

        } else {
          strcat(text, "cent");
        }
      }

      if (addends_len != (i + 1)) {
        strcat(text, " ");
      }
    }
  }

  decomposition_destroy(decomposition);

  return text;
}

void convert_to_french(char *dest, unsigned long number, char *dialect) {
  strcpy(dest, "");

  char *text = malloc(150 * sizeof(char));

  if (text == NULL) {
    fprintf(stderr, "Memory allocation error.\n");

    return;
  }

  strcpy(text, "");

  Decomposition *decomposition = decompose_by_three(number);

  if (decomposition == NULL) {
    free(text);

    fprintf(stderr, "Memory allocation error.\n");

    return;
  }

  unsigned int addends_len = decomposition_get_addends_len(decomposition);
  unsigned long *addends = decomposition_get_addends(decomposition);

  if(number == 0) {
    strcpy(text, "zero");
  }

  for (int i = addends_len - 1; i >= 0; i--) {
    char *str = convert_three_or_less_digits_number(addends[i], dialect);

    if (text == NULL) {
      free(text);
      decomposition_destroy(decomposition);

      fprintf(stderr, "Memory allocation error.\n");

      return;
    }

    switch (i) {
      case 0:
        strcat(text, str);
        break;
      case 1:
        if (strcmp(str, "") != 0) {
          if (strcmp(str, "un") == 0) {
            strcat(text, "mille ");
          } else {
            strcat(text, str);
            strcat(text, " mille ");
          }
        }
        break;
      case 2:
        if (strcmp(str, "") != 0) {
          strcat(text, str);

          if (strcmp(str, "un") != 0) {
            strcat(text, " millions ");
          } else {
            strcat(text, " million ");
          }
        }
        break;
      case 3:
        if (strcmp(str, "") != 0) {
          strcat(text, str);

          if (strcmp(str, "un") != 0) {
            strcat(text, " milliards ");
          } else {
            strcat(text, " milliard ");
          }
        }
        break;
    }

    free(str);
  }

  if(text[strlen(text) - 1] == ' ') {
    text[strlen(text) - 1] = 0;
  }

  strcpy(dest, text);

  free(text);
  decomposition_destroy(decomposition);
}
