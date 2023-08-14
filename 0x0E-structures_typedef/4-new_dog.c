#include "dog.h"
#include <stdlib.h>

/**
 * new_dog - creates a new dog struct
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 * Return: returns pointer to new dog stuct
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog;
	char *new_name, *new_owner;
	int nlen = 0, olen = 0, i;

	if (name == NULL || owner == NULL)
		return (NULL);

	while (name[nlen])
		nlen++;
	while (owner[olen])
		olen++;

	new_dog = malloc(sizeof(dog_t));
	if (new_dog == NULL)
		return (NULL);

	new_name = malloc(nlen + 1);
	new_owner = malloc(olen + 1);

	if (new_name == NULL || new_owner == NULL)
	{
		free(new_name);
		free(new_owner);
		free(new_dog);
		return (NULL);
	}

	for (i = 0; name[i]; i++)
		new_name[i] = name[i];
	new_name[i] = '\0';

	for (i = 0; owner[i]; i++)
		new_owner[i] = owner[i];
	new_owner[i] = '\0';

	new_dog->name = new_name;
	new_dog->age = age;
	new_dog->owner = new_owner;
	return (new_dog);
}
