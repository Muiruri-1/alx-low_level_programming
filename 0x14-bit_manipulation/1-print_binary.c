#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to be converted and printed.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask;
	int i, shift = 0;

	for (i = 63; i >= 0; i--)
	{
		mask = n >> i;

		if (mask & 1)
		{
			_putchar('1');
			shift++;
		}
		else if (shift)
			_putchar('0');
	}
	if (!shift)
		_putchar('0');
}
