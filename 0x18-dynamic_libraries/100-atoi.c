#include "main.h"
#include <limits.h>

/**
 * _atoi - Converts a string to an integer
 * @s: The string to be converted
 *
 * Return: The integer value of the converted string
 */
int _atoi(char *s)
{
	int result = 0;
	int neg_multiplier = 1;
	int digit_seen = 0;

	while (*s)
	{
		if (*s == '-')
		{
			neg_multiplier *= -1;
		}
		else if (*s >= '0' && *s <= '9')
		{
			digit_seen = 1;
			int digit_value = *s - '0';

			if (result > (INT_MAX - digit_value) / 10)
			{
				if (neg_multiplier == 1)
					return (INT_MAX);
				else
					return (INT_MIN);
			}

			result = (result * 10 + digit_value);
		}
		else if (digit_seen)
		{
			break;
		}
		s++;
	}

	return (result * neg_multiplier);
}

