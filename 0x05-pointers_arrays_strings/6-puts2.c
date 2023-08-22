#include "main.h"

/**
 * _putchar - Writes a character to stdout
 * @c: The character to print
 *
 * Return: On success, 1. On error, -1 is returned,
 * and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * puts2 - Prints every other character of a string, followed by a new line
 * @str: The input string
 */
void puts2(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (i % 2 == 0)
		{
			_putchar(str[i]);
		}
		i++;
	}
	_putchar('\n');
}

