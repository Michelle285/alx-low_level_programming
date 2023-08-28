#include "lists.h"

/**
 * get_nodeint_at_index -  returns the nth node of a listint_t list.
 * @head: A pointer to listint_t
 * @index: The index of the node
 * Return: A pointer to nth node, or NULL if not exist
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;

	if (!head)
		return (NULL);

	while (head)
	{
		if (i == index)
			return (head);
		head = head->next;
		i++;
	}

	return (NULL);
}
