#include "main.h"

/**
 * set_bit - sets the value of a bit to 1
 * at a given index.
 * @n: pointer to an unsigned long integer
 * @index: index of the bit.
 * Return: 1 on success, -1 on error
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int num;

	if (index > 63)
		return (-1);

	num = 1 << index;
	*n = (*n | num);

	return (1);
}
