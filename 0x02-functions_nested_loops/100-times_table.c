#include "main.h"

/**
 * print_times_table - Prints the n times table.
 * @n: The value for which the times table is printed.
 */
void print_times_table(int n)
{
	int row, col, result;

	if (n >= 0 && n <= 15)
	{
		for (row = 0; row <= n; row++)
		{
			for (col = 0; col <= n; col++)
			{
				result = row * col;

				if (col != 0)
				{
					_putchar(',');
					_putchar(' ');
				}

				if (result < 10)
				{
					if (col != 0)
						_putchar(' ');
					_putchar('0' + result);
				}
				else if (result >= 10 && result < 100)
				{
					_putchar(' ');
					_putchar('0' + result / 10);
					_putchar('0' + result % 10);
				}
				else if (result >= 100)
				{
					_putchar('0' + result / 100);
					_putchar('0' + (result / 10) % 10);
					_putchar('0' + result % 10);
				}
			}
			_putchar('\n');
		}
	}
}

