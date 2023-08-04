#include "main.h"

/**
 * times_table - Prints the 9 times table
 *
 * Return: void
 */
void times_table(void)
{
	int a, b, mul;

	for (a = 0; a <= 9; a++)
	{
		_putchar(48);
		for (b = 1; b <= 9; b++)
		{
			mul = a * b;
			_putchar(44);
			_putchar(32);
			if (mul <= 9)
			{
				_putchar(32);
				_putchar(mul + '0');
			}
			else
			{
				_putchar((mul / 10) + '0');
				_putchar((mul % 10) + '0');
			}
		}
		_putchar('\n');
	}
}
