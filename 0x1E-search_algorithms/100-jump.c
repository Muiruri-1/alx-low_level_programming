#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array of integers using
 *               the Jump search algorithm
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: The first index where value is located,
 *         or -1 if value is not present in array or if array is NULL
 */
int jump_search(int *array, size_t size, int value)
{
	int step, prev;

	if (array == NULL)
		return (-1);
	step = sqrt(size);
	prev = 0;

	printf("Value checked array[%d] = [%d]\n", prev, array[prev]);

	while (array[prev] < value)
	{
		prev = step;
		step += sqrt(size);
		if (prev >= (int)size)
			break;
		printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
	}
	prev -= sqrt(size);
	printf("Value found between indexes [%d] and [%d]\n", prev, prev + step);
	while (array[prev] < value)
	{
		prev++;
		if (prev == fmin(size, step))
			return (-1);
		printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
	}
	if (array[prev] == value)
		return (prev);
	return (-1);
}
