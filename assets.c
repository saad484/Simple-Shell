#include"shell.h"

/**
 * free_array_of_strings - Frees dynamically allocated strings in an array
 * @arr: Array of dynamically allocated strings
 *
 * This function takes an array of dynamically allocated strings and frees each
 * string individually, then frees the array itself. It helps prevent memory
 * leaks when you're done with the array.
 */
void free_array_of_strings(char **arr)
{
	int i;

	if (!arr)
		return;

	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}

	free(arr);
	arr = NULL;
}
/**
 * intlen - Calculate the length of an integer
 * @n: Integer to find the length of
 * Return: Length of the integer
 */
int intlen(unsigned int n)
{
	int len = 0;

	if (n == 0)
	{
		return (1);
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

/**
 * array_rev - Reverse a character array
 * @s: Character array to reverse
 * @len: Length of the character array
 */
void array_rev(char *s, int len)
{
	int i, j;
	char temp;

	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

/**
 * _itoa - Convert Integer To Char
 * @n: Int To Convert
 * Return: Char Pointer
 */
char *_itoa(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	len = intlen(n);
	s = (char *)malloc(len + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	s[i] = (n % 10) + '0';
	array_rev(s, len);
	s[i + 1] = '\0';
	return (s);
}
