#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings.
 * @s1: first string.
 * @s2: second string.
 * @n: amount of bytes.
 *
 * Return: pointer to the allocated memory.
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *new_str;
	unsigned int len1 = 0, len2 = 0, i;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	while (s1[len1] != '\0')
		len1++;

	while (s2[len2] != '\0')
		len2++;

	if (n >= len2)
		n = len2;

	new_str = malloc(len1 + n + 1);

	if (new_str == NULL)
		return (NULL);

	for (i = 0; i < len1 + n; i++)
	{
		if (i < len1)
			new_str[i] = s1[i];
		else
			new_str[i] = s2[i - len1];
	}

	new_str[i] = '\0';

	return (new_str);
}
