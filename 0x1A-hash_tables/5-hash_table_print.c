#include "hash_tables.h"
#include <stdio.h>

/**
 * hash_table_print - Prints a hash table.
 * @ht: The hash table to print.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	int printed = 0; /* Flag to check if anything has been printed */

	if (ht == NULL)
		return;
	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		hash_node_t *temp = ht->array[i];

		while (temp != NULL)
		{
			/* Print comma and space before each key-value pair */
			if (printed)
				printf(", ");
			printf("'%s': '%s'", temp->key, temp->value);
			printed = 1;
			temp = temp->next;
		}
	}
	printf("}\n");
}
