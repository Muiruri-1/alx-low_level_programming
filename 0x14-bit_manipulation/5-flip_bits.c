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
	unsigned long int count = 0;
	unsigned long int diff = n ^ m;

	while (diff > 0)
	{
		count += diff & 1;
		diff >>= 1;
	}

	return (count);
}

