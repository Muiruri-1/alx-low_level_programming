#include "main.h"

/**
 * reset_to_98 - Update the value pointed to by a pointer to 98
 * @n: Pointer to an integer
 */
void reset_to_98(int *n)
{
    *n = 98;
}
/* _putchar.c */

#include <unistd.h>
#include "main.h"

/**
 * _putchar - Write a character to stdout
 * @c: The character to write
 * Return: On success, return the number of characters written, otherwise -1
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

