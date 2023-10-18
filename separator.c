#include "shell.h"

/**
 * separator - Separates command recieved from stdin by ;
 * @input: String gathered from stdin
 * Return: Parsed strings to be used as commands
 */

char **separator(char *input)
{
	char **commands;
	char *command;
	int k;
	int buffsize = BUFSIZ;

	if (input[0] == ' ' && input[_strlen(input)] == ' ')
		exit(0);
	if (input == NULL)
		return (NULL);
	commands = malloc(sizeof(char *) * buffsize);
	if (!commands)
	{
		free(commands);
		perror("hsh");
		return (NULL);
	}
	command = _strtok(input, ";&");
	for (k = 0; command; k++)
	{
		commands[k] = command;
		command = _strtok(NULL, ";&");
	}
	commands[k] = NULL;

	return (commands);
}
