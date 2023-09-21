#include <stdio.h>

void __attribute__ ((constructor)) print_message(void);

/**
 * print_message - Prints the specified lines before main is executed.
 */
void print_message(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}

