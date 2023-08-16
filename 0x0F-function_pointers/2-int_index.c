#include "function_pointers.h"
#include <stdlib.h>

/**
 * int_index - a function that searches for an integer.
 * @array: array of integers
 * @size: Size of the array
 * @cmp: pointer to function
 *
 * Return: The index of the first element for which the cmp function
 * does not return 0 or -1 if no elements matches or size <= 0.
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	if (cmp == NULL || array == NULL || size <= 0)
		return (-1);

	for (; i < size; i++)
		if (cmp(array[i]))
			return (i);

	return (-1);
}
