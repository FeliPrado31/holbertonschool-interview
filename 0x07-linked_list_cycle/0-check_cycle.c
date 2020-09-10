#include "lists.h"

/**
 * check_cycle -  checks if a singly linked list has a count in it.
 * @list: is the linked list
 * return: 0 if it does not have count in it. 1 in otherwise
 */
int check_cycle(listint_t *list)
{
  int count = 0;
  listint_t *node = NULL, *lastNode = NULL;

  if (!list)
    return (count);

  node = list, lastNode = node->next;
  while (lastNode && lastNode->next && lastNode->next->next)
  {
    if (node == lastNode)
      return (1);
    node = node->next;
    lastNode = lastNode->next->next;
  }
  return (count);
}