#include "lists.h"

/**
 * add_nodeint_end - adds a new node to the end of list
 * @head: A pointer to listint_t list
 * @n: An integer data
 * Return: The address of the new element, or NULL on failure
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new, *temp;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	if (*head == NULL)
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		new->next = NULL;
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}

	return (new);
}
