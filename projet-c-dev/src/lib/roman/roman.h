#ifndef ROMAN_H_
#define ROMAN_H_

#include <stdbool.h>

#include "./../decomposition/decomposition.h"

#define ROMAN_MIN 1
#define ROMAN_MAX 4999

typedef struct _Symbols Symbols;

/**
 * Get the symbols of roman dialect
 *
 * @return The symbols
 */
extern Symbols *get_roman_symbols(void);

/**
 * Symbols destructor
 *
 * @param symbols The symbols to destroy
 */
extern void symbols_destroy(Symbols *symbols);

/**
 * Test if a number can be converted into roman
 *
 * @param number A number to convert
 *
 * @return true if the number can be converted, false otherwise
 */
extern bool is_in_roman_range(const unsigned long number);

/**
 * Get the symbol that corresponds to the value in roots.
 *
 * @param dest The destination of the symbol
 * @param value The value to convert
 * @param symbols The symbols
 */
extern void get_symbol(char *dest, const unsigned long value, const Symbols *symbols);

/**
 * Test if the value is a key value
 *
 * @param value The value to test
 * @param symbols The symbols
 *
 * @return Desc
 */
extern bool is_key_value(const unsigned long value, const Symbols *symbols);

/**
 * Get the closest lower key from value
 *
 * @param value The value we need to find a bound
 * @param symbols The symbols
 *
 * @return The low bound
 */
extern unsigned long find_low_key_bound_value(const unsigned long value, const Symbols *symbols);

/**
 * Get the closest higher key from value
 *
 * @param value The vlaue we need to find a bound
 * @param symbols The symbols
 *
 * @return The high bound
 */
extern unsigned long find_high_key_bound_value(const unsigned long value, const Symbols *symbols);

/**
 * Convert a decomposition's addend to roman in additive way
 *
 * @param dest The destination of the representation ("" if no substractions are possible)
 * @param value The value to represent
 * @param symbols The symbols
 */
extern void convert_decomposition_addend_to_roman_substractive(char *dest, const unsigned long value, const Symbols *symbols);

/**
 * Convert a decomposition's addend to roman in additive way
 *
 * @param dest The destination of the representation
 * @param value The value to represent
 * @param symbols The symbols
 */
extern void convert_decomposition_addend_to_roman_additive(char *dest, const unsigned long value, const Symbols *symbols);

/**
 * Convert a decomposition's addend to roman (the addend mustn't be a key value)
 *
 * @param dest The destination of the representation
 * @param value The value to represent
 * @param symbols The symbols
 */
extern void convert_decomposition_addend_to_roman_no_key(char *dest, const unsigned long value, const Symbols *symbols);

/**
 * Convert a decomposition's addend to roman
 *
 * @param dest The destination of the representation
 * @param value The value to represent
 * @param symbols The symbols
 */
extern void convert_decomposition_addend_to_roman(char *dest, const unsigned long value, const Symbols *symbols);

/**
 * Convert a number into roman language
 *
 * @param dest A string that will contain the number converted
 * @param number A number to convert
 */
extern void convert_to_roman(char *dest, const unsigned long number);

#endif  // ROMAN_H_
