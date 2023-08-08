#include "main.h"
#include <stdlib.h>
/**
 * create_array - creates an array of chars.
 *
 * @size: size of the array.
 * @c: stored char.
 *
 * Return: pointer to the array or NULL.
 */

char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *ar;

	ar = malloc(sizeof(c) * size);

	if (size == 0 || ar == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		ar[i] = c;

	return (ar);

}
