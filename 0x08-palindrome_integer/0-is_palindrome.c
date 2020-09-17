#include "palindrome.h"

/**
* is_palindrome - Write a function that checks whether 
* or not a given unsigned integer is a palindrome.
* @n: is the number to be checked
* Return: Your function must return 1 
* if n is a palindrome, and 0 otherwise
*/
int is_palindrome(unsigned long n)
{
    int count1 = 0, count2 = 0;
    unsigned long array[1024];
    unsigned long num = n;

    while (num != 0)
    {
        array[count1++] = num % 10;
        num = num / 10;
    }

    count1--;
    for (; count1 > count2; count1--, count2++)
    {
        if (array[count1] != array[count2])
            return (0);
    }

    return (1);
}