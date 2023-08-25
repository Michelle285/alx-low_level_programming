#include "lists.h"
#include <string.h>

/**
 * add_node_end - adds a new node at the
 * end of a list_t list.
 * @head: pointer to linked list.
 * @str: pointer to string
 * Return: address of the new element
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *temp;
	size_t len;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	while (str[len])
		len++;

	new->len = len;
	new->str = strdup(str);

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

