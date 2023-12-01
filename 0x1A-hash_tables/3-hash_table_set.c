#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_set - Adds an element to the hash table.
 * @ht: The hash table to add or update the key/value to.
 * @key: The key (cannot be an empty string).
 * @value: The value associated with the key
 * (duplicated; can be an empty string).
 *
 * Return: 1 if it succeeds, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node, *temp;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);
	/* Compute the index for the given key using the hash function */
	index = hash_djb2((unsigned char *)key) % ht->size;
	/* Check if the key already exists, update the value */
	temp = ht->array[index];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			/* Duplicate the value and free the old one if needed */
			free(temp->value);
			temp->value = strdup(value);
			if (temp->value == NULL)
				return (0);
			return (1);
		}
		temp = temp->next;
	}
	/* Allocate memory for the new node */
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);
	/* Duplicate the key and value */
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	if (new_node->key == NULL || new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (0);
	}
	/* Insert the new node at the beginning of the list (collision handling) */
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
