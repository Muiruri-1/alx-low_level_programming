#include <unistd.h>

/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
	int limit = 1024;
	int sum = 0;
	int i, digit;

	for (i = 3; i < limit; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}
	}

	while (sum > 0)
	{
		digit = sum % 10;
		_putchar(digit + '0');
		sum /= 10;
	}

	_putchar('\n');

	return (0);
}

