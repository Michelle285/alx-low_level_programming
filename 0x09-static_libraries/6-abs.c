#include <unistd.h>
#include "main.h"

/**
 * _abs - computes the absolute value of an integer.
 *
 * @i: input number as an integer.
 *
 * Return: absolute value
 */

int _abs(int i)
{
	int abs_value = i * -1;

	if (i >= 0)
		return (i);
	else
		return (abs_value);
}
