#include <stdio.h>
#include <math.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long int num = 612852475143;
	unsigned long int divisor = 2;
	unsigned long int largest_prime;

	while (num != 0)
	{
		if (num % divisor != 0)
			divisor = divisor + 1;
		else
		{
			largest_prime = num;
			num = num / divisor;
			if (num == 1)
			{
				printf("%lu\n", largest_prime);
				break;
			}
		}
	}
	return (0);
}

