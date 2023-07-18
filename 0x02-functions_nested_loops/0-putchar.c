#include <unistd.h>
#include "main.h"

/**
 * main - Prints _putchar followed by a new line as a message.
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int i;
	char word[8] = "_putchar";

	for (i = 0; i < 8; i++)
		_putchar(word[i]);
	_putchar('\n');

	return (0);
}
