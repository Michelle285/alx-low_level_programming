#include "lists.h"
#include <string.h>

/**
 * add_nodeint - adds a new node at the begining of a list
 * @head: A pointer to listint_t list
 * @n: An integer
 * Return: the address of the new element or NULL on failure
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = *head;
	*head = malloc(sizeof(listint_t));

	if (!*head)
		return (NULL);
	(*head)->n = n;
	(*head)->next = new;

	return (*head);
}
