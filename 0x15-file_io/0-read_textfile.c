#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>

/**
 * read_textfile - reads a text file and prints it
 * to the POSIX standard output
 * @filename: The name of the file to open
 * @letters: The number of letters to read and print
 * Return: The actual number of letters read and printed
 * or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fo;
	ssize_t frd, fwr;
	char *buff;

	if (!filename)
		return (0);

	buff = malloc(sizeof(char) * (letters));
	if (!buff)
		return (0);

	fo = open(filename, O_RDONLY);

	if (fo < 0)
		return (0);

	frd = read(fo, buff, letters);
	fwr = write(STDOUT_FILENO, buff, frd);

	close(fo);

	free(buff);

	return (fwr);
}
