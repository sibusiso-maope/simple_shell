#include "shell.h"

/**
 * _strchr - function that locates character in a string
 * @s: string to be searched
 * @c: character to be located
 * Return: pointer to character
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
		{
			break;
		}
	} while (*s++);
	return (s);
}

/**
 * _strcat - function that concatenates two strings
 * @dest: first string
 * @src: second string
 * Return: first string + second string
 */

char *_strcat(char *dest, char *src)
{
	char *d = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';
	return (d);
}

/**
 * _strncmp - function that compares n amount of characters of two strings
 * @s1: first string
 * @s2: second string
 * @n: amount of characters to compare
 * Return: 1 if the strings don't match otherwise 0
 */

/**
 * _strcmp - function that compares two string
 * @s1: first string
 * @s2: second string
 * Return: 0 if identical otherwise how much diffrent
 */

int _strcmp(char *s1, char *s2)
{
	int cmp = 0, k;
	int length1, length2;

	length1 = _strlen(s1);
	length2 = _strlen(s2);

	if (s1 == NULL || s2 == NULL)
		return (1);

	if (length1 != length2)
		return (1);

	for (k = 0; s1[k]; k++)
	{
		if (s1[k] != s2[k])
		{
			cmp = s1[k] - s2[k];
			break;
		}
		else
			continue;

	}
	return (cmp);
}

/**
 * intlen - function that determine length of integer
 * @num: given integer
 * Return: length of integer
 */

int intlen(int num)
{
	int length = 0;

	while (num != 0)
	{
		length++;
		num /= 10;
	}
	return (length);
}

/**
 * _isalpha - function to check if c is alphabet
 * @c: character to check
 * Return: 1 if true 0 if false
 */

int _isalpha(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * array_rev - function reverse an array
 * @arr: array to reverse
 * @len: length of array
 */

void array_rev(char *arr, int len)
{
	int k;
	char tmp;

	for (k = 0; k < (len / 2); k++)
	{
		tmp = arr[k];
		arr[k] = arr[(len - 1) - k];
		arr[(len - 1) - k] = tmp;
	}
}

/**
 * _itoa - function that convert integer to character
 * @n: integer to convert
 * Return: character pointer
 */
char *_itoa(unsigned int n)
{
	int length = 0;
	int k = 0;
	char *s;

	length = intlen(n);

	s = malloc(length + 2);

	if (!s)
	{
		free(s);
		return (NULL);
	}
	*s = '\0';

	while (n / 10)
	{
		s[k] = (n % 10) + '0';
		n /= 10;
		k++;
	}

	s[k] = (n % 10) + '0';
	array_rev(s, length);
	s[k + 1] = '\0';

	return (s);
}
