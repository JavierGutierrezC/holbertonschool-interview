#include "lists.h"
/**
 * check_cycle - checks if a single link list has a cycle in it
 * @list: list to check for cycle
 * Return: 0 if no cycle 1 if there is a cycle
 *
 */
int check_cycle(listint_t *list)
{
	listint_t *n1;
	listint_t *n2;

	if (list == NULL)
		return (0);
	n1 = list;
	n2 = list;
	while (n1->next != NULL && n2->next != NULL && n2->next->next != NULL)
	{
		n1 = n1->next;
		n2 = n2->next->next;
		if (n1 == n2)
			return (1);
	}
	return (0);
}
