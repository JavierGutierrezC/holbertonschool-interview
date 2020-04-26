#include "lists.h"

/**
 * insert_node - insert new node
 * @head: first element of the list
 * @number: number to be added
 * Return: New node
 */

listint_t *insert_node(listint_t **head, int number)
{
listint_t *act, *new;

act = *head;
new = malloc(sizeof(listint_t));

if (new == NULL)
return (NULL);
new->n = number;

if (act == NULL || (act)->n >= new->n)
{
new->next = act;
act = new;
return (new);
}

/*act = *head;*/

while (act->next && act->next->n < new->n)
{
act = act->next;
}
new->next = act->next;
act->next = new;
return (new);
}
