#include "lists.h"
#include <stdio.h>

/**
 * listint_len - returns the number of elements in the list
 * @h: A pointer to listint_t
 * Return: number of elements.
 */

size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h)
	{
		h = h->next;
		count++;
	}
	return (count);
}
