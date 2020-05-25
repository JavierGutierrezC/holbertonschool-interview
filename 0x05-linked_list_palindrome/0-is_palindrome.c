#include "lists.h"

/**
 * is_palindrome - checks if linked list is a plaindrome
 * @head: pointer to head of the linked list
 * Return: if the linked list is not a palindrome 0, if it is 1
 */
int is_palindrome(listint_t **head)
{
listint_t *frw;
listint_t *rev;
listint_t *wid;
listint_t *mid;
int len;

if (*head == NULL || head == NULL)
return (1);

frw = *head;
rev = *head;
len = 0;
while (frw->next)
{
len++;
if (frw->next->next)
{
frw = frw->next;
len++;
}
frw = frw->next;
rev = rev->next;
}
if (frw)
len++;
mid = reverse_listint(&rev);
wid = mid;
rev = *head;
while (wid)
{
if (wid->n != rev->n)
return (0);
wid = wid->next;
rev = rev->next;
}
return (1);
}

/**
 * reverse_listint - reverses a linked list
 * @head: Pointer of head of linked list
 * length of list: Length of the list
 * Return: reveresed link list
 */
listint_t *reverse_listint(listint_t **head)
{
listint_t *nxt;
listint_t *prev;
listint_t *count;

count = *head;
prev = NULL;
while (count)
{
nxt = count->next;
count->next = prev;
prev = count;
if (nxt == NULL)
break;
count = nxt;
}
return (count);
}

