#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: A pointer to the head of the skip list to search in.
 * @value: The value to search for.
 *
 * Return: If the value is not present in list or head is NULL, return NULL.
 * Otherwise, return a pointer to the first node where value is located.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *express;

	if (list == NULL)
		return (NULL);
	express = list->express;
	printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
	while (express && express->n < value)
	{
		list = express;
		express = express->express;
		if (!express)
			break;
		printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
	}
	printf("Value between index [%lu] and [%lu]\n", list->index, express->index);
	while (list && list->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
		list = list->next;
		if (!list)
			break;
	}
	if (!list)
		return (NULL);
	printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
	if (list->n == value)
		return (list);
	return (NULL);
}
