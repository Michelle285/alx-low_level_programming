#include "lists.h"
#include <stdio.h>

/**
 * print_listint - prints all the elements in a listint_t list
 * @h: A pointer to listint_t
 * Return: the number of nodes.
 */

size_t print_listint(const listint_t *h)
{
	size_t count = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}
	return (count);
}
