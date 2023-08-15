#include <stdio.h>

/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
	int n = 50;
	long int first = 1, second = 2, next;
	int i;

	printf("%ld, %ld", first, second);

	for (i = 2; i < n; i++)
	{
		next = first + second;
		printf(", %ld", next);
		first = second;
		second = next;
	}

	printf("\n");

	return (0);
}

