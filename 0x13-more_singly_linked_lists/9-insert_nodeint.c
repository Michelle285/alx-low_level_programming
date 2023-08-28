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

	temp = *head;

	if (idx != 0)
	{
		for (i = 0; i < idx - 1 && temp; i++)
		{
			temp = temp->next;
		}
	}

	if (!temp && idx != 0)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		new->next = temp->next;
		temp->next = new;
	}

	return (new);

}
