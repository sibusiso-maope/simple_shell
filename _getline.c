#include "shell.h"

/**
 * enter - Handles newline character input
 * @string: String to be handled
 * Return: Empty string
 */

char *enter(char *string)
{
	free(string);
	return ("\0");
}

/**
 * hashtag_handler - function that removes everything after '#'
 * @buff: input buffer
 * Return: nothing
 */

void hashtag_handler(char *buff)
{
	int k;

	for (k = 0; buff[k] != '\0'; k++)
	{
		if (buff[k] == '#' && buff[k - 1] == ' ' && buff[k + 1] == ' ')
		{
			buff[k] = '\0';
		}
	}
}

/**
 * _getline - read input from standard input by user
 * Return: the input on a buffer
 */
char *_getline()
{
	int k, rd, buffsize = BUFSIZ;
	char c = 0, *buffer, *buf;

	buffer = malloc(buffsize);

	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	for (k = 0; c != EOF && c != '\n'; k++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);

		if (rd == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		buffer[k] = c;
		if (buffer[0] == '\n')
			return (enter(buffer));
		if (k >= buffsize)
		{
			buffer = realloc(buffer, (buffsize + 2));
			if (buffer == NULL)
			{
				free(buffer);
				return (NULL);
			}
		}
	}
	buffer[k] = '\0';
	buf = space(buffer);
	free(buffer);
	hashtag_handler(buf);
	return (buf);
}

/**
 * space - Modifies the input string to remove preceeding whitespaces
 * @str: Input to be modifies
 * Return: Returns the modified string
 */

char *space(char *str)
{
	int k, l = 0;
	char *buff;

	buff = malloc(sizeof(char) * (_strlen(str) + 1));

	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}
	for (k = 0; str[k] == ' '; k++)
		;
	for (; str[k + 1] != '\0'; k++)
	{
		buff[l] = str[k];
		l++;
	}
	buff[l] = '\0';
	if (buff[0] == '\0' || buff[0] == '#')
	{
		free(buff);
		return ("\0");
	}
	return (buff);
}
