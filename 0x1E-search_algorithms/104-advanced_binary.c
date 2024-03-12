#include <stdio.h>
#include "search_algos.h"

/**
 * advanced_binary_recursive - Searches for a value in a sorted
 * array of integers using the Advanced Binary search algorithm recursively
 * @array: A pointer to the first element of the array to search in
 * @start: The starting index of the search range
 * @end: The ending index of the search range
 * @value: The value to search for
 *
 * Return: The index where value is located,
 *         or -1 if value is not present in array
 */
int advanced_binary_recursive(int *array, size_t start, size_t end, int value)
{
	size_t i;

	if (start <= end)
	{
		size_t mid = start + (end - start) / 2;

		printf("Searching in array:");
		for (i = start; i <= end; ++i)
			printf(" %d", array[i]);
		printf("\n");
		if (array[mid] == value)
		{
			if (mid == start || array[mid - 1] != value)
				return (mid);
			else
				return (advanced_binary_recursive(array, start, mid, value));
		}
		else if (array[mid] < value)
			return (advanced_binary_recursive(array, mid + 1, end, value));
		else
			return (advanced_binary_recursive(array, start, mid - 1, value));
	}
	return (-1);
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 *                   using the Advanced Binary search algorithm
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: The index where value is located,
 *         or -1 if value is not present in array or if array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);
	return (advanced_binary_recursive(array, 0, size - 1, value));
}
