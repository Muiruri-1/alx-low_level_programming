#include "main.h"

/**
 * flip_bits - Returns the number of bits
 * needed to flip to get from one number to another.
 * @n: The first input number.
 * @m: The second input number.
 *
 * Return: The number of bits to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, count = 0;
	unsigned long int current;
	unsigned long int diff = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		current = diff >> 1;
		if (current & 1)
		count++;
	}

	return (count);
}

