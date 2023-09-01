#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/**
 * check_num - string if they are digit
 * @str: array str
 * Return: Always 0 (success)
 */
int check_num(char *str)
{
	/*declaring variables*/
	unsigned int count;

	count = 0;
	while (count < strlen(str)) /*count string*/
	{
		if (!isdigit(str[count])) /*checks if str there are digit*/
		{
			return (0);
		}
		count++;
	}
	return (1);
}
/**
 * main - Prints the name of the program
 * @argc: count arguments
 * @argv: arguments
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	/*declaring variablea*/
	int count;
	int str_to_int;
	int sum = 0;

	count = 1;

	while (count < argc) /*goes through the whole array*/
	{
		if (check_num(argv[count]))
		{
			str_to_int = atoi(argv[count]); /*ATOI converts string to int*/
			sum += str_to_int;
		}
		else
		{
			printf("Error\n");
			return (1);
		}
		count++;
	}
	printf("%d\n", sum);
	return (0);
}

