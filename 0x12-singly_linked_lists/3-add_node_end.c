#include "lists.h"

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

	new->str = strdup(str);

	if (str == NULL)
	{
		free(new);
		return (NULL);
	}


	while (str[len])
		len++;

	new->len = len;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}
