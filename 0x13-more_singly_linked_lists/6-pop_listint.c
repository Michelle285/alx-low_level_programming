#include "lists.h"

/**
 * pop_listint - deletes the head node of a linked list
 * and returns the head node's data (n)
 * @head: A pointer to listint_t
 * Return: The head node's data
 */
int pop_listint(listint_t **head)
{
	listint_t *new;
	int h;

	if (*head == NULL)
		return (0);

	h = (*head)->n;
	new = (*head)->next;

	free(*head);
	*head = new;

	return (h);
}
