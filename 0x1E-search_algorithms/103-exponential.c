#include <stdio.h>
#include "search_algos.h"

/**
 * exponential_search - Searches for a value in a sorted array of integers
 *                       using the Exponential search algorithm
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: The first index where value is located,
 *         or -1 if value is not present in array or if array is NULL
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound, start, end;

	if (array == NULL || size == 0)
		return (-1);

	bound = 1;

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}
	start = bound / 2;
	end = (bound < size - 1) ? bound : size - 1;

	printf("Value found between indexes [%lu] and [%lu]\n", start, end);
	return binary_search_range(array, start, end, value);
}

/**
 * binary_search_range - Searches for a value in a sorted array of integers
 *                 using the Binary search algorithm
 * @array: A pointer to the first element of the array to search in
 * @start: The starting index of the search range
 * @end: The ending index of the search range
 * @value: The value to search for
 *
 * Return: The index where value is located,
 *         or -1 if value is not present in array
 */
int binary_search_range(int *array, size_t start, size_t end, int value)
{
	size_t mid;
	size_t i;

	while (start <= end)
	{
		mid = start + (end - start) / 2;

		printf("Searching in array:");
		for (i = start; i <= end; ++i)
			printf(" %d", array[i]);
		printf("\n");
		if (array[mid] == value)
			return (mid);
		if (array[mid] < value)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return (-1);
}
