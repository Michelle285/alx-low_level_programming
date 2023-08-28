#include "lists.h"
/**
 * insert_nodeint_at_index - inserts a new node at a given position.
 * @head: A pointer to listint_t
 * @idx: The index of the list
 * @n: An integer data
 * Return: The address of the new node or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i = 1;
	listint_t *new, *temp;

	if (!head)
		return (NULL);
	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	if (*head == NULL)
	{
		*head = new;
		new->next = NULL;
		new->n = n;
		return (new);
	}
	if (idx == 0)
	{
		new->next = *head;
		new->n = n;
		*head = new;
		return (new);
	}
	temp = *head;
	if (!temp && idx != 0)
		return (NULL);
	while (i < idx)
	{
		temp = temp->next;
		i++;
	}
	new->n = n;
	new->next = temp->next;
	temp->next = new;
	return (new);
}
