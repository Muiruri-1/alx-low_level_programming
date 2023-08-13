#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints the alphabet in lowercase, then in uppercase.
 * Only uses the putchar function three times.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char lowercase, uppercase;

	for (lowercase = 'a'; lowercase <= 'z'; lowercase++)
	{
		putchar(lowercase);
	}
	for (uppercase = 'A'; uppercase <= 'Z'; uppercase++)
	{
		putchar(uppercase);
	}

	putchar('\n');

	return (0);
}

