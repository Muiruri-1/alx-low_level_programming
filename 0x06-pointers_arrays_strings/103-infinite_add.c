#include "main.h"

/**
 * infinite_add - Adds two numbers
 * @n1: First number as a string
 * @n2: Second number as a string
 * @r: Buffer to store the result
 * @size_r: Size of the result buffer
 *
 * Return: Pointer to the result or 0 if result cannot be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int carry = 0;
	int sum;
	int i, j, k;

	for (i = 0, j = 0, k = 0; n1[i] != '\0' || n2[j] != '\0'; i++, j++, k++)
	{
		sum = carry;
		if (n1[i] != '\0')
			sum += n1[i] - '0';
		if (n2[j] != '\0')
			sum += n2[j] - '0';
		carry = sum / 10;
		if (k >= size_r - 1 || (n1[i] == '\0' && n2[j] == '\0' && carry > 0))
			return (0);
		r[k] = sum % 10 + '0';
	}
	r[k] = '\0';
	for (i = 0, j = k - 1; i < j; i++, j--)
	{
		char temp = r[i];

		r[i] = r[j];
		r[j] = temp;
	}
	return (r);
}

