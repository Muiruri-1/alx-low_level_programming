#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, otherwise exit status
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	int num_bytes = atoi(argv[1]);

	if (num_bytes < 0)
	{
		printf("Error\n");
		return (2);
	}
	char *main_ptr = (char *)main;
	int i;

	for (i = 0; i < num_bytes - 1; i++)
	{
		printf("%02hhx ", main_ptr[i]);
	}
	printf("%02hhx\n", main_ptr[i]);
	return (0);
}

