#include "./roman.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./roman.inc"

Symbols *get_roman_symbols(void) {
  Symbols *symbols = malloc(sizeof(Symbols));

  if (symbols == NULL) {
    return NULL;
  }

  symbols->number_of_symbols = 7;
  symbols->key_values = malloc(symbols->number_of_symbols * sizeof(unsigned long));

  if (symbols->key_values == NULL) {
    free(symbols);

    return NULL;
  }

  symbols->data = malloc(symbols->number_of_symbols * sizeof(char));

  if (symbols->data == NULL) {
    free(symbols);

    return NULL;
  }

  symbols->key_values[0] = 1;
  symbols->data[0] = 'I';

  symbols->key_values[1] = 5;
  symbols->data[1] = 'V';

  symbols->key_values[2] = 10;
  symbols->data[2] = 'X';

  symbols->key_values[3] = 50;
  symbols->data[3] = 'L';

  symbols->key_values[4] = 100;
  symbols->data[4] = 'C';

  symbols->key_values[5] = 500;
  symbols->data[5] = 'D';

  symbols->key_values[6] = 1000;
  symbols->data[6] = 'M';

  return symbols;
}

void symbols_destroy(Symbols *symbols) {
  free(symbols->key_values);
  free(symbols->data);
  free(symbols);
}

bool is_in_roman_range(const unsigned long number) {
  return ROMAN_MIN <= number && number <= ROMAN_MAX;
}

void get_symbol(char *dest, const unsigned long value, const Symbols *symbols) {
  strcpy(dest, "");

  for (unsigned int i = 0; i < symbols->number_of_symbols; i++) {
    if (symbols->key_values[i] == value) {
      dest[0] = symbols->data[i];
      dest[1] = 0;
    }
  }
}

bool is_key_value(const unsigned long value, const Symbols *symbols) {
  bool is_key_value = false;

  for (unsigned int i = 0; i < symbols->number_of_symbols; i++) {
    if (symbols->key_values[i] == value) {
      is_key_value = true;
    }
  }

  return is_key_value;
}

unsigned long find_low_key_bound_value(const unsigned long value, const Symbols *symbols) {
  unsigned int i = 0;
  unsigned long low_bound = 0;

  while (i < symbols->number_of_symbols && symbols->key_values[i] < value) {
    if (low_bound < symbols->key_values[i]) {
      low_bound = symbols->key_values[i];
    }
    i++;
  }

  return low_bound;
}

unsigned long find_high_key_bound_value(const unsigned long value, const Symbols *symbols) {
  int i = symbols->number_of_symbols - 1;
  unsigned long high_bound = symbols->key_values[i];

  while(i >= 0 && symbols->key_values[i] > value) {
    if(high_bound > symbols->key_values[i]) {
      high_bound = symbols->key_values[i];
    }

    i--;
  }

  return high_bound;
}

void convert_decomposition_addend_to_roman_substractive(char *dest, const unsigned long value, const Symbols *symbols) {
  unsigned long low_bound = find_low_key_bound_value(value, symbols);
  unsigned long high_bound = find_high_key_bound_value(value, symbols);

  strcpy(dest, "");

  while (low_bound != 0) {
    if (value == high_bound - low_bound) {
      char *sub_str = malloc(6 * sizeof(char));

      if (sub_str == NULL) {
        fprintf(stderr, "Memory allocation error.\n");

        return;
      }

      get_symbol(dest, low_bound, symbols);
      get_symbol(sub_str, high_bound, symbols);

      strcat(dest, sub_str);

      free(sub_str);
    }

    low_bound = find_low_key_bound_value(low_bound, symbols);
  }
}

void convert_decomposition_addend_to_roman_additive(char *dest, const unsigned long value, const Symbols *symbols) {
  int low_bound = find_low_key_bound_value(value, symbols);

  strcpy(dest, "");

  if (value % low_bound == 0) {
    for (unsigned long i = 0; i < value / low_bound; i++) {
      char *sub_str = malloc(6 * sizeof(char));

      if (sub_str == NULL) {
        fprintf(stderr, "Memory allocation error.\n");

        return;
      }

      get_symbol(sub_str, low_bound, symbols);
      strcat(dest, sub_str);

      free(sub_str);
    }
  } else {
    char *sub_str = malloc(18 * sizeof(char));

    if (sub_str == NULL) {
      fprintf(stderr, "Memory allocation error.\n");

      return;
    }

    convert_decomposition_addend_to_roman(sub_str, value - low_bound, symbols);

    get_symbol(dest, low_bound, symbols);
    strcat(dest, sub_str);

    free(sub_str);
  }

}

void convert_decomposition_addend_to_roman_no_key(char *dest, const unsigned long value, const Symbols *symbols) {
  strcpy(dest, "");
  convert_decomposition_addend_to_roman_substractive(dest, value, symbols);

  if (strlen(dest) == 0) {
    convert_decomposition_addend_to_roman_additive(dest, value, symbols);
  }
}

void convert_decomposition_addend_to_roman(char *dest, const unsigned long value, const Symbols *symbols) {
  if (is_key_value(value, symbols)) {
    get_symbol(dest, value, symbols);
  } else {
    convert_decomposition_addend_to_roman_no_key(dest, value, symbols);
  }
}

void convert_to_roman(char *dest, unsigned long number) {
  strcpy(dest, "");

  Symbols *symbols = get_roman_symbols();

  if (symbols == NULL) {
    fprintf(stderr, "Memory allocation error.\n");

    return;
  }

  Decomposition *decomposition = decompose(number);

  if (decomposition == NULL) {
    symbols_destroy(symbols);

    fprintf(stderr, "Memory allocation error.\n");

    return;
  }

  if (number == 0 || number >= 5000) {
    symbols_destroy(symbols);
    decomposition_destroy(decomposition);

    return;
  }

  for (unsigned int i = 0; i < decomposition_get_addends_len(decomposition); i++) {
    if (decomposition_get_addends(decomposition)[i] != 0) {
      char *sub_str = malloc(18 * sizeof(char));

      if (sub_str == NULL) {
        symbols_destroy(symbols);
        decomposition_destroy(decomposition);

        fprintf(stderr, "Memory allocation error.\n");

        return;
      }

      convert_decomposition_addend_to_roman(sub_str, decomposition_get_addends(decomposition)[i], symbols);
      strcat(dest, sub_str);

      free(sub_str);
    }
  }

  symbols_destroy(symbols);
  decomposition_destroy(decomposition);
}
