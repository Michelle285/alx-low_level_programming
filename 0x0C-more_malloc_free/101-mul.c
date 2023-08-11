#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - Check the code
 * @argc: number of arguments
 * @argv: arguments
 * Return: 0
 */
int main(int argc, char **argv)
{
	int num1, num2, mul, len = 0, n;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	for (n = 1; n < argc; n++)
	{
		while (argv[n][len] != '\0')
		{
			if (!isdigit(argv[n][len]))
			{
				printf("Error\n");
				exit(98);
			}
			len++;
		}
	}
	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	mul = num1 * num2;
	printf("%d\n", mul);
	return (0);
}
