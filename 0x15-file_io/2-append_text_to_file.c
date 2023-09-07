#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>

/**
 * append_text_to_file - appends text at the end to the  file
 * @filename: The name of the file to open and append in
 * @text_content: The NULL terminated string to add
 * Return: 1 on success, -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fo, len, fwr;

	if (!filename)
		return (-1);

	fo = open(filename, O_WRONLY | O_APPEND);

	if (fo == -1)
		return (-1);

	if (text_content)
	{
		for (len = 0; text_content[len]; len++)
			;

		fwr = write(fo, text_content, len);

		if (fwr == -1)
			return (-1);
	}

	close(fo);

	return (1);
}
