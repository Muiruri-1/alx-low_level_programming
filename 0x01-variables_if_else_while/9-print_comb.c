#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all possible combinations of single-digit numbers
 * separated by ", " in ascending order using putchar four times maximum.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num1 = 0;

	while (num1 < 10)
	{
		int num2 = 0;

		while (num2 < 10)
		{
			putchar(num1 + '0');
			putchar(num2 + '0');

			if (num1 != 9 || num2 != 9)
			{
				putchar(',');
				putchar(' ');
			}

			num2++;
		}
		num1++;
	}

	putchar('\n');

	return (0);
}

