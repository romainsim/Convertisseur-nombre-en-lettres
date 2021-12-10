#ifndef DATE_H_
#define DATE_H_

#include "./../decomposition/decomposition.h"

/**
 * Convert a number into a french date
 *
 * @param dest The string where you want to write the date
 * @param year The year you want to convert
 */
extern void convert_to_french_date(char *dest, unsigned long year);

#endif  // DATE_H_
