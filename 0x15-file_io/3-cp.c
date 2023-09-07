#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * file_check - checks if files can be opened
 * @file_in: file from
 * @file_out: file to
 * @argv: arguments array
 * Return: void
 */
void file_check(int file_in, int file_out, char *argv[])
{
	if (file_in == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_out == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - check the code
 * @argc: number of arguments
 * @argv: arguments array
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int file_in, file_out, f_close;
	ssize_t len, fwr;
	char buff[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_in = open(argv[1], O_RDONLY);
	file_out = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	file_check(file_in, file_out, argv);

	len = 1024;
	while (len == 1024)
	{
		len = read(file_in, buff, 1024);
		if (len == -1)
			file_check(-1, 0, argv);

		fwr = write(file_out, buff, len);
		if (fwr == -1)
			file_check(0, -1, argv);
	}

	f_close = close(file_in);
	if (f_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_in);
		exit(100);
	}

	f_close = close(file_out);
	if (f_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_in);
		exit(100);
	}

	return (0);
}
