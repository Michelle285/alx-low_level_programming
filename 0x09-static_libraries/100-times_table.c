#include "main.h"

/**
 * print_times_table - Prints the n times table
 *
 * @n: integer number of range 0 to 15
 *
 * Return: void
 */
void print_times_table(int n)
{
	int a, b, mul;

	if (n >= 0 && n <= 15)
	{
		for (a = 0; a <= n; a++)
		{
			_putchar(48);
			for (b = 1; b <= n; b++)
			{
				mul = a * b;
				_putchar(44);
				_putchar(32);
				if (mul <= 9)
				{
					_putchar(32);
					_putchar(32);
					_putchar(mul + '0');
				}
				else if (mul <= 99)
				{
					_putchar(32);
					_putchar((mul / 10) + '0');
					_putchar((mul % 10) + '0');
				}
				else
				{
					_putchar(((mul / 100) % 10) + '0');
					_putchar(((mul / 10) % 10) + '0');
					_putchar((mul % 10) + '0');
				}
			}
			_putchar('\n');
		}
	}
}

