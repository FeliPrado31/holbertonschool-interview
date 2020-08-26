#include "lists.h"
/**
 * is_palindrome - check list is a palindrome
 * @head: pointer to the head
 *
 * Return: 0 if it is not a palindrome, 1 if is a palindrome
 */
int is_palindrome(listint_t **head)
{
  listint_t *node = *head;
  int arr[2048];
  int i = 0, j = 0;

  if (*head == NULL || head == NULL || node->next == NULL)
    return (1);

  for (i = 0; node != NULL; i++)
  {
    arr[i] = node->n;
    node = node->next;
  }
  i--;
  for (; j <= i; j++, i--)
  {
    if (arr[j] != arr[i])
      return (0);
  }
  return (1);
}