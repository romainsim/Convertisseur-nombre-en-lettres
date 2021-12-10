#ifndef SPELLNUMBER_DECOMPOSITION_H_
#define SPELLNUMBER_DECOMPOSITION_H_

typedef struct _Decomposition Decomposition;

/**
 * Used to get the number of digits in a specified number
 *
 * @param n The number you want to know the number of digits
 *
 * @return The number of digits
 */
extern unsigned int get_number_of_digits(unsigned long n);

/**
 * Used to decompose the number in 3 parts :
 * - the number you want to decompose
 * - the array that contains the number decomposed
 * - the size of the array
 *
 * @param n The number you want to decompose
 *
 * @return The structure containing your decomposed number
 */
extern Decomposition *decompose(unsigned long n);

/**
 * Cut a number in packages of three digits
 *
 * @param n A number to decompose
 *
 * @return The structure containing the decomposed number
 */
extern Decomposition *decompose_by_three(unsigned long n);

/**
 * Used to free the memory space used by a structure
 *
 * @param decomposition The structure you want to remove
 */
extern void decomposition_destroy(Decomposition *decomposition);

/**
 * Used to get the array of numbers of a specified structure
 *
 * @param decomposition The structure you want to get the array from
 *
 * @return The array of numbers
 */
extern unsigned long *decomposition_get_addends(Decomposition *decomposition);

/**
 * Used to get the size of an array of a specified structure
 *
 * @param decomposition The structure you want to get the size of an array from
 *
 * @return The size of the array
 */
extern unsigned int decomposition_get_addends_len(Decomposition *decomposition);

/**
 * Used to get the original number of a structure
 *
 * @param decomposition The structure of which you want to know the number
 *
 * @return The original number
 */
extern unsigned long decomposition_get_number(Decomposition *decomposition);

#endif  // SPELLNUMBER_DECOMPOSITION_H_
