#include "search.h"

/**
 * linear_skip - Write a function that searches for a value in a sorted skip list of integers.
 * @list: is the given list
 * @value: is the value to be searched
 * Return: the node with the value or null if no found.
 **/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *current = list, *data = NULL, *lastOne = NULL;

    while (current)
    {
        data = current->data;

        if (!data)
        {
            lastOne = current;
            while (lastOne->next)
                lastOne = lastOne->next;
            printf("Value found between indexes [%ld] and [%ld]\n",
                   current->index,
                   lastOne->index);
        }
        else
        {
            printf("Value checked at index [%ld] = [%d]\n", data->index, data->n);
            if (value > data->n)
            {
                current = data;
                continue;
            }
            else
                printf("Value found between indexes [%ld] and [%ld]\n",
                       current->index,
                       data->index);
        }

        while (current)
        {
            printf("Value checked at index [%ld] = [%d]\n", current->index, current->n);
            if (value == current->n)
                return (current);

            current = current->next;
        }
    }

    return (NULL);
}