#include "search_algos.h"
#include <math.h>

/**
 * jump_list - Searches for a value in a sorted list of integers using Jump
 *             search algorithm.
 * @list: Pointer to the head of the list to search in.
 * @size: Number of nodes in the list.
 * @value: Value to search for.
 *
 * Return: Pointer to the first node where value is located, or NULL if not
 *         found or if list is NULL.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step = sqrt(size), prev = 0;
	size_t i;
	listint_t *current = list, *block = NULL;

	if (list == NULL)
		return (NULL);
	while (current->n < value && current->next != NULL)
	{
		block = current;
		for (i = 0; current->next != NULL && i < step; i++)
			current = current->next;
		printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
	}
	printf("Value found between indexes [%lu] and [%lu]\n", prev, current->index);
	printf("Value checked at index [%lu] = [%d]\n", block->index, block->n);
	while (block->index < current->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", block->index, block->n);
		if (block->n == value)
			return (block);
		block = block->next;
	}
	return (NULL);
}
