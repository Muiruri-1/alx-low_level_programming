#include "function_pointers.h"
#include <stddef.h>

/**
 * int_index - Searches for an integer in an array.
 * @array: Pointer to the array.
 * @size: Size of the array.
 * @cmp: Pointer to the comparison function.
 *
 * Return: Index of the first matching element,
 * or -1 if no match or invalid size.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);
	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}
	return (-1);
}

