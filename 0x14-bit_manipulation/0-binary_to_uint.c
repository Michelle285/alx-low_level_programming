#include "main.h"

/**
 * binary_to_uint - converts a binary number to
 * an unsigned integer
 * @b: A pointer to a string of 0 & 1 chars
 * Return: converted number or 0
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int conv_num = 0;
	int num = 1, len = 0;

	if (!b)
		return (0);

	while (b[len])
		len++;

	while (len)
	{
		if (b[len - 1] != '0' && b[len - 1] != '1')
			return (0);

		if (b[len - 1] == '1')
			conv_num += num;
		num *= 2;
		len--;
	}

	return (conv_num);
}
