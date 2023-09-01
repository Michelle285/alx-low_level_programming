#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: The number to get bit from
 * @index: The index of the bit
 * Return: The value of the bit or -1 on error
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int num = 0x01;

	num <<= index;
	if (num == 0)
		return (-1);

	if ((n & num))
		return (1);
	else
		return (0);
}
