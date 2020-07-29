#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint - prints all elements of node listint_t list
 * @h: pointer to head of list
 * Return: number of nodes
 */
listint_t *insert_node(listint_t **head, int number)
{
  listint_t *node = malloc(sizeof(listint_t)), *tmp = *head;
  int i = 0;

  if (node == NULL)
  {
    return (NULL);
  }
  node->n = number;
  node->next = *head;
  while (tmp)
  {
    if (node->n > tmp->n)
    {
      i = node->n;
      node->n = tmp->n;
      tmp->n = i;
    }
    if (tmp->next && tmp->n > tmp->next->n)
    {
      i = tmp->n;
      tmp->n = tmp->next->n;
      tmp->next->n = i;
    }
    tmp = tmp->next;
  }
  *head = node;
  return (node);
}
