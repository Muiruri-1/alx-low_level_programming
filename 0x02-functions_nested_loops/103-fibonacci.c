#include <stdio.h>

/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
	long int first = 1, second = 2, next;
	long int sum = 2;

	while (1)
	{
		next = first + second;

		if (next > 4000000)
			break;

		if (next % 2 == 0)
			sum += next;

		first = second;
		second = next;
	}

	printf("%ld\n", sum);

	return (0);
}

