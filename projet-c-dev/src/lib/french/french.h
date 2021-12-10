#ifndef FRENCH_H_
#define FRENCH_H_

#include <stdbool.h>

#include "./../decomposition/decomposition.h"

/**
 * Test if a dialect exists
 *
 * @param dialect A dialect to test
 *
 * @return True if  the dialect exists, false otherwise
 */
extern bool is_french_dialect(char *dialect);

/**
 * Convert a digit into the respective french word
 *
 * @param number A digit to convert
 *
 * @return A string containing the french word
 */
extern char *convert_units(unsigned long number);

/**
 * Convert a tens into their respective word(s)
 *
 * @param number A number to convert
 * @param dialect The dialect you want the number to be converted into
 *
 * @return A string containing the word(s)
 */
extern char *convert_tens(unsigned long number, char *dialect);

/**
 * Convert a two digit number, that is not a tens, into their respective word(s)
 *
 * @param number A number to convert
 * @param dialect The dialect you want the number to be converted into
 *
 * @return A string containing the word(s)
 */
extern char *convert_not_round_two_digits_number(unsigned long number, char *dialect);

/**
 * Used to get the correct spelling of 2 digits numbers
 *
 * @param number A number to convert
 * @param dialect The dialect you want the number to be converted into
 *
 * @return A string containing the word(s)
 */
extern char *convert_two_digits_number(unsigned long number, char *dialect);

/**
 * Used to get the correct spelling for 3 or less digits numbers
 *
 * @param number A number to convert
 * @param dialect The dialect you want the number to be converted into
 *
 * @return A string containing the word(s)
 */
extern char *convert_three_or_less_digits_number(unsigned long number, char *dialect);

/**
 * Convert a number into a string of one of the french's dialects
 *
 * @param dest A string that will contain the converted number
 * @param number A number to convert
 * @param dialect The dialect you want the number to be converted into
 */
extern void convert_to_french(char *dest, unsigned long number, char *dialect);

#endif  // FRENCH_H_
