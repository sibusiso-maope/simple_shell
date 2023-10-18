#include "shell.h"

/**
 * build - Build command
 * @token: Executable command
 * @value: Directory conatining Command
 * Return: Parsed full path of command or NULL if failed
 */

char *build(char *token, char *value)
{
	char *command;
	size_t length;

	length = _strlen(value) + _strlen(token) + 2;

	command = malloc(sizeof(char) * length);

	if (command == NULL)
	{
		free(command);
		return (NULL);
	}

	memset(command, 0, length);

	command = _strcat((command, value));
	command = _strcat(command, "/");
	command = _strcat(command, token);

	return (command);
}

/**
 * path_command -  Search In $PATH for executable command
 * @cmd: Parsed input
 * Return: 0 on success or  1 on failure  0
 */

int path_command(char **cmd)
{
	char *path, *value;
	char *command_path;
	struct stat buf;

	path = _getenv("PATH");

	value = _strtok(path, ":");

	while (value != NULL)
	{
		command_path = build(*cmd, value);
		if (stat(command_path, &buf) == 0)
		{
			*cmd = _strdup(command_path);
			free(command_path);
			free(path);
			return (0);
		}
		free(command_path);
		value = _strtok(NULL, ":");
	}
	free(path);
	free(value);
	return (1);
}

/**
 * _getenv - Gets the value of environment variable by name
 * @name: Environment variable name
 * Return: The value of the environment variable or NULL if failed
 */

char *_getenv(char *name)
{
	size_t name_length, value_length;
	char *value;
	int k, l, m;

	name_length = _strlen(name);

	for (k = 0 ; environ[k]; k++)
	{
		if (_strncmp(name, environ[k], name_length) == 0)
		{
			value_length = _strlen(environ[k]) - name_length;

			value = malloc(sizeof(char) * value_length);

			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			l = 0;
			for (m = name_length + 1; environ[k][m]; m++, l++)
			{
				value[l] = environ[k][m];
			}
			value[l] = '\0';

			return (value);
		}
	}
	return (NULL);
}
