#ifndef ITOX_H
#define ITOX_H
// -------------------------------------------------------------------------- //

/**
 * Represents a byte as two heximal digits. Chars are upper-case.
 *
 * @param byte  A value to convert.
 * @param buff  A pointer to a string buffer to store the result of conversion.
 *              Must be at least 2 chars long.
 *
 * @return  Returns a pointer to the specified buffer increased by 2. This
 *          allows chaining the function call.
 */
char *btox(unsigned char byte, char *buff);

/**
 * Represents a word (16-bit) as four heximal digits. Chars are upper-case.
 *
 * @param word  A value to convert.
 * @param buff  A pointer to a string buffer to store the result of conversion.
 *              Must be at least 4 chars long.
 *
 * @return  Returns a pointer to the specified buffer increased by 4. This
 *          allows chaining the function call.
 */
char *wtox(unsigned short word, char *buff);

// -------------------------------------------------------------------------- //
# endif // End of Include Guard //
