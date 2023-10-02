#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

/**
 * exit_with_error - prints error message and exits with specified error code
 * @error_code: error code to exit with
 * @message: error message to print
 */
void exit_with_error(int error_code, char *message)
{
	dprintf(2, "%s\n", message);
	exit(error_code);
}

/**
 * main - copies the content of a file to another file
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, otherwise exit with specified error codes
 */
int main(int argc, char *argv[])
{
	int from_fd, to_fd;
	char buf[1024];
	ssize_t rd, wr;

	if (argc != 3)
		exit_with_error(97, "Usage: cp file_from file_to");
	from_fd = open(argv[1], O_RDONLY);
	if (from_fd == -1)
		exit_with_error(98, "Error: Can't read from file");
	to_fd = open(argv[2],
			O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (to_fd == -1)
	{
		close(from_fd);
		exit_with_error(99, "Error: Can't write to file");
	}
	while ((rd = read(from_fd, buf, 1024)) > 0)
	{
		wr = write(to_fd, buf, rd);
		if (wr == -1 || wr != rd)
		{
			close(from_fd);
			close(to_fd);
			exit_with_error(99, "Error: Can't write to file");
		}
	}
	if (rd == -1)
	{
		close(from_fd);
		close(to_fd);
		exit_with_error(98, "Error: Can't read from file");
	}
	close(from_fd);
	close(to_fd);
	return (0);
}

