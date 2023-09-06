#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>

/**
 * create_file - creates a file
 * @filename: The name of the file to create
 * @text_content: A NULL terminated string to write to the file
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int fo, len, fwr;

	if (!filename)
		return (-1);

	if (!text_content)
		text_content = "";

	fo = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fo == -1)
		return (-1);

	for (len = 0; text_content[len]; len++)
		;

	fwr = write(fo, text_content, len);

	if (fwr == -1)
		return (-1);

	close(fo);

	return (1);
}
