#include "main.h"
#include <stdlib.h>
/**
 * _strdup - returns a pointer to a newly allocated space in memory.
 * @str: string.
 *
 * Return: pointer to the array or NULL.
 */

char *_strdup(char *str)
{
	int len = 0;
	char *new_str;
	int i;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	new_str = malloc(sizeof(char) * (len + 1));

	if (new_str == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		new_str[i] = str[i];

	return (new_str);

}
