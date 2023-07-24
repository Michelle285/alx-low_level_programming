#include <stdio.h>
#include "main.h"

/**
 * puts_half - prints half of a string.
 * @str: input string.
 * Return: no return.
 */
void puts_half(char *str)
{
	int count = 0, i, j;

	while (count >= 0)
	{
		if (str[count] == '\0')
			break;
		printf("count[%d]: %c\n", count, str[count]);
		count++;
		
	}
	printf("count: %d\n", count);

	if (count % 2 == 0)
	{
		i = count / 2;
		printf("i: %d\n", i);
	}
	else
	{
		i = (count - 1) / 2;
		printf("i: %d\n", i);
	}
	for (j = i; j < count; j++)
		_putchar(str[j]);
	_putchar('\n');
}
