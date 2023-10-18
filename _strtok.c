#include "shell.h"

/**
 * check_delim - function that checks if a character matchs any character
 * @c: character to check
 * @str: string of delimiters
 * Return: 1 on success, 0 on failure
 */

unsigned int check_delim(char c, const char *str)
{
	unsigned int k;

	for (k = 0; str[k] != '\0'; k++)
	{
		if (c == str[k])
			return (1);
	}
	return (0);
}

/**
 * _strtok - function that extracts tokens of a string
 * @str: string
 * @delim: delimiter
 * Return: pointer to the next token or NULL
 */

char *_strtok(char *str, const char *delim)
{
	static char *token;
	static char *new_token;
	unsigned int k;

	if (str != NULL)
		new_token = str;

	token = new_token;

	if (token == NULL)
		return (NULL);

	for (k = 0; token[k] != '\0'; k++)
	{
		if (check_delim(token[k], delim) == 0)
			break;
	}

	if (new_token[k] == '\0' || new_token[k] == '#')
	{
		new_token = NULL;
		return (NULL);
	}

	token = new_token + k;

	new_token = token;

	for (k = 0; new_token[k] != '\0'; k++)
	{
		if (check_delim(new_token[k], delim) == 1)
			break;
	}

	if (new_token[k] == '\0')
		new_token = NULL;
	else
	{
		new_token[k] = '\0';
		new_token = new_token + k + 1;
		if (*new_token == '\0')
			new_token = NULL;
	}
	return (token);
}
