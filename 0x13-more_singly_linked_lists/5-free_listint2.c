#include "lists.h"

/**
 * free_listint2 - frees a list and sets the head to NULL
 * @head: A pointer to listint_t
 * Return: void
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (!head)
		return;

	temp = *head;
	while (*head)
	{
		temp = *head;
		(*head) = (*head)->next;
		free(temp);
	}

	*head = NULL;
}
