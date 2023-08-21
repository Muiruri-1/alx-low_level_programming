#include "main.h"

/**
 * rev_string - Reverses a string
 * @s: Pointer to the input string
 */
void rev_string(char *s)
{
	if (s == NULL)
		return;
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}
	int start = 0;
	int end = length - 1;

	while (start < end)
	{
		char temp = s[start]
			s[start] = s[end];
		s[end] = temp;
		start++;
		end--;
	}
}

