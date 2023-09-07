#include "main.h"
#include <stdlib.h>

/**
 * *array_range - creates an array of integers
 * @min: minimum range of values stored
 * @max: maximum range of valoes stored
 * Return: pointer to the new array
 */
int *array_range(int min, int max)
{
	int *bcd;
	int i, size;

	if (min > max)
		return (NULL);
	size = max - min + 1;

	bcd = malloc(sizeof(int) * size);

	if (bcd == NULL)
		return (NULL);

	for (i = 0; min <= max; i++)
		bcd[i] = min++;
	return (bcd);
}
