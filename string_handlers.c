#include "shell.h"

/**
 * _strlen - function that counts the length of a string
 * @s: string input
 * Return: length of string
 */

int _strlen(char *s)
{
	int k;

	for (k = 0; s[k] != '\0'; k++)
		continue;

	return (k);
}

/**
 * _putchar - function that writes the character
 * @c: The character to print
 * Return: character to standard output
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - function that prints a string
 * @str: pointer to string
 * Return: void
 */
void _puts(char *str)
{
	int k;

	for (k = 0; str[k] != '\0'; k++)
	{
		_putchar(str[k]);
	}
	_putchar('\n');
}

/**
 * _atoi - function to convert string to an integer
 * @s: string input
 * Return: converted integer
 */

int _atoi(char *s)
{
	int k = 0;
	int l = 1;
	int m;
	unsigned int n = 0;

	while (s[k] != '\0')
	{
		if (s[k] == '-')
		{
			return (2);
		}
		m = s[k] - '\0';

		if (n > 0 && !(m >= 0 && k <= 9))
			break;

		if (m >= 0 && k <= 9)
			n = n * 10 + m;

		k++;
	}
	n *= l;
	return (n);
}

/**
 * _strncpy - function that copies a string
 * @dest: destination string
 * @src: source string
 * @n: number of charaters to be copied
 * Return: copied strings
 */
char *_strncpy(char *dest, char *src, int n)
{
	int k = 0;

	while (k < n && *(src + k))
	{
		*(dest + k) = *(src + k);
		k++;
	}
	while (k < n)
	{
		*(dest + k) = '\0';
		k++;
	}
	return (dest);
}

/**
 * _strcpy - function that copies a string
 * @dest: destination
 * @src: source
 * Return: destination
 */

char *_strcpy(char *dest, char *src)
{
	int k = 0;

	while (src[k])
	{
		dest[k] = src[k];
		k++;
	}
	dest[k] = '\0';
	return (dest);
}

/**
 * _strdup - duplicate a string
 * @str: string
 * Return: duplicated string or Null if failed
 */
char *_strdup(char *str)
{
	size_t len, k;
	char *str2;

	len = _strlen(str);

	str2 = malloc(sizeof(char) * (len + 1));

	if (!str2)
	{
		return (NULL);
	}
	for (k = 0; k <= len; k++)
	{
		str2[k] = str[k];
	}
	return (str2);
}

/**
 * _strncmp - function that compares n amount of characters of two strings
 * @s1: first string
 * @s2: second string
 * @n: amount of characters to compare
 * Return: 1 if the strings don't match otherwise 0
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t k;

	if (s1 == NULL)
		return (-1);

	for (k = 0; k < n && s2[k]; k++)
	{
		if (s1[k] != s2[k])
		{
			return (1);
		}
	}
	return (0);
}
