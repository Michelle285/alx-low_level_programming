#include "main.h"
/**
 * swap_int - swaps the values of two integers
 *@a: first integer pointer variable
 *@b: second integer pointer variable
 *
 * Return: void
 */

void swap_int(int *a, int *b)
{
	int c;
	int d;

	c = *a;
	d = *b;
	*a = d;
	*b = c;
}
