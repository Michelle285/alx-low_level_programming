#include "lists.h"
#include <string.h>

/**
 * add_node - adds a new node to the beginning of linked list
 * @head: pointer to linked list
 * @str: pointer to string
 * Return: address of new element or NULL on failure
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	int len = 0;

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

	while (str[len])
		len++;

	new->str = strdup(str);
	new->len = len;
	new->next = *head;
	*head = new;
	return (new);
}
