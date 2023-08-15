#include <stdio.h>

/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
	int n = 98;
	unsigned int first = 1, second = 2, next;
	int count;

	printf("%u, %u", first, second);

	for (count = 2; count < n; count++)
	{
		next = first + second;
		printf(", %u", next);

		first = second;
		second = next;
	}

	printf("\n");

	return (0);
}

