#include "./decomposition.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "./decomposition.inc"

unsigned int get_number_of_digits(unsigned long n) {
  unsigned int i = 0;

  while (n != 0) {
    n /= 10;

    i++;
  }

  return i;
}

Decomposition *decompose(unsigned long n) {
  unsigned int number_of_digits = get_number_of_digits(n);

  Decomposition *decomposition = malloc(sizeof(Decomposition));

  if (decomposition == NULL) {
    return NULL;
  }

  unsigned int addends_len = 0;
  unsigned long *addends = malloc(sizeof(unsigned long) * number_of_digits);

  if (addends == NULL) {
    decomposition_destroy(decomposition);

    return NULL;
  }

  unsigned long number = n;
  unsigned long ten_power = 0;
  unsigned int digit = 0;

  for (int i = number_of_digits; i > 0; i--) {
    ten_power = (long)pow(10, i - 1);
    digit = (int)(number / ten_power);

    if (digit != 0) {
      addends[addends_len] = digit * ten_power;

      addends_len++;

      number -= digit * ten_power;
    }
  }

  decomposition->number = n;
  decomposition->addends_len = addends_len;
  decomposition->addends = realloc(addends, sizeof(unsigned long) * addends_len);

  return decomposition;
}

Decomposition *decompose_by_three(unsigned long n) {
  unsigned int number_of_digits = get_number_of_digits(n);

  Decomposition *decomposition = malloc(sizeof(Decomposition));

  if (decomposition == NULL) {
    return NULL;
  }

  unsigned int addends_len = 0;
  unsigned long *addends = malloc(sizeof(unsigned long) * number_of_digits);

  if (addends == NULL) {
    free(decomposition);

    return NULL;
  }

  for (unsigned int i = 1; i <= number_of_digits; i++) {
    if (i % 3 == 0 || i == number_of_digits) {
      addends[addends_len] = (long)(n % (long)pow(10, 3 * (addends_len + 1))) / (long)pow(10, (addends_len * 3));

      addends_len++;
    }
  }

  decomposition->number = n;
  decomposition->addends_len = addends_len;
  decomposition->addends = realloc(addends, sizeof(unsigned long) * addends_len);

  return decomposition;
}

void decomposition_destroy(Decomposition *decomposition) {
  free(decomposition->addends);
  free(decomposition);
}

unsigned long *decomposition_get_addends(Decomposition *decomposition) {
  return decomposition->addends;
}

unsigned int decomposition_get_addends_len(Decomposition *decomposition) {
  return decomposition->addends_len;
}

unsigned long decomposition_get_number(Decomposition *decomposition) {
  return decomposition->number;
}
