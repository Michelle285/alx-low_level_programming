#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index
 * of a linked list.
 * @head: pointer to listint_t list.
 * @index: index of the node to be deleted.
 *
 * Return: 1 on success, -1 on failure.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *pnode;
	listint_t *nnode;

	pnode = *head;

	if (index != 0)
	{
		for (i = 0; i < index - 1 && pnode; i++)
		{
			pnode = pnode->next;
		}
	}

	if (!pnode || (pnode->next == NULL && index != 0))
	{
		return (-1);
	}

	nnode = pnode->next;

	if (index != 0)
	{
		pnode->next = nnode->next;
		free(nnode);
	}
	else
	{
		free(pnode);
		*head = nnode;
	}

	return (1);
}
