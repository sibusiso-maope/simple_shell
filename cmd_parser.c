#include "shell.h"

/**
 * parse_command - Parses the command recieved from stdin
 * @input: String gathered from stdin
 * Return: Parsed strings to be used as arguments
 */

char **parse_command(char *input)
{
	char **args;
	char *arg;
	int k;
	int buffsize = BUFSIZE;

	if (input[0] == ' ' && input[_strlen(input)] == ' ')
		exit(0);

	if (input == NULL)
		return (NULL);

	args = malloc(sizeof(char *) * buffsize);

	if (!args)
	{
		free(args);
		perror("hsh");
		return (NULL);
	}
	arg = _strtok(input, "\n\t\r\a ");

	for (k = 0; arg; k++)
	{
		args[k] = arg;
		arg = _strtok(NULL, "\n\t\r\a ");
	}

	args[k] = NULL;

	return (args);
}
