#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to be converted and printed.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	int shift = 0;

	while ((n >> shift) > 0)
		shift++;

	shift--;

	if (shift > 0)
		mask <<= shift - 1;

	while (mask > 0)
	{
		if (n & mask)
			_putchar('1');
		else
			_putchar('0');
		mask >>= 1;
	}
	if (n == 0)
		_putchar('0');
}

