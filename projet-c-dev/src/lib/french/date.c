#include "./date.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./french.h"

#include "./../decomposition/decomposition.inc"

void convert_to_french_date(char *dest, unsigned long year) {
  strcpy(dest, "");

  if (year >= 1000 && year < 2000) {
    unsigned long divide = (long)(year / 100);
    unsigned long modulo = (long)(year % 100);

    char *strDivide = malloc(50 * sizeof(char));

    if (strDivide == NULL) {
      fprintf(stderr, "Memory allocation error.\n");

      return;
    }

    convert_to_french(strDivide, divide, "--fr_FR");

    char *strModulo = malloc(50 * sizeof(char));

    if (strModulo == NULL) {
      free(strDivide);

      fprintf(stderr, "Memory allocation error.\n");

      return;
    }

    convert_to_french(strModulo, modulo, "--fr_FR");

    if (modulo == 0) {
      strcat(dest, strDivide);
      strcat(dest, " cents");
    } else {
      strcat(dest, strDivide);
      strcat(dest, " cent ");
      strcat(dest, strModulo);
    }

    free(strDivide);
    free(strModulo);
  } else {
    char *str = malloc(150 * sizeof(char));

    if (str == NULL) {
      fprintf(stderr, "Memory allocation error.\n");

      return;
    }

    convert_to_french(str, year, "--fr_FR");

    strcat(dest, str);

    free(str);
  }
}
