#include "main.h"

/**
 * puts2 - prints one char out of 2 of a string.
 * @str: input string.
 * Return: no return.
 */

void puts2(char *str)
{
	int count = 0;

	while (count >= 0)
	{
		if (str[count] != '\0')
		{
			_putchar(str[count]);
			count = count + 2;
		}
		else
		{
			_putchar('\n');
			break;
		}
	}
}
