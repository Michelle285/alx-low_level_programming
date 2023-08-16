#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * op_add -  adds two integer numbers
 * @a: first integer
 * @b: second integer
 * Return: a + b.
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - subtracts two integer numbers
 * @a: first integer
 * @b: second integer
 * Return: a - b.
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - multiplies two integer numbers
 * @a: first integer
 * @b: second integer
 * Return: a * b.
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - divides two integer numbers
 * @a: first integer
 * @b: second integer
 * Return: a / b.
 */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a / b);
}

/**
 * op_mod - calculates the module of two integer numbers
 * @a: first integer
 * @b: second integer
 * Return: a % b.
 */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a % b);
}
