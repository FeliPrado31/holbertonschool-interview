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
	int arr[20] = {0};
	int i = 0, lenOfNumber = 0;
	unsigned long numberToCheck = n;

	do {
		numberToCheck /= 10, lenOfNumber++;
	} while (numberToCheck);

	if (lenOfNumber == 1)
		return (1);

	for (i = 0; i < lenOfNumber; i++)
		arr[lenOfNumber - 1 - i] = n % 10, n /= 10;

	for (i = 0; i < lenOfNumber; i++)
	{
		if (i > lenOfNumber / 2)
			break;
		else if (arr[i] == arr[lenOfNumber - 1 - i])
			continue;
		else
			return (0);
	}
	return (1);
}