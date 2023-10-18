#include "shell.h"

/**
 * handle_builtin - Handles predefined built in commands
 * @cmd: Array of parsed command strings
 * @st: Status of last execution
 * Return: -1 Failure 0 Success
 */

int handle_builtin(char **cmd, int st)
{
	builtin built_in[] = {
		{"cd", change_directory},
		{"env", display_environment},
		{"help", display_help},
		{"echo", echo_bul},
		{"history", history_display},
		{NULL, NULL}
	};

	int k = 0;

	while ((built_in + k)->command)
	{
		if (_strcmp(cmd[0], (built_in + k)->command) == 0)
		{
			return ((built_in + k)->function(cmd, st));
		}
		k++;
	}
	return (-1);
}

/**
 * check_builtin - Checks if parsed command in built-in
 * @cmd: Parsed command to be check
 * Return: 0 Succes -1 Fail
 */

int check_builtin(char **cmd)
{
	builtin fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"env", NULL},
		{"history", NULL},
		{NULL, NULL}
	};

	int k = 0;

	if (*cmd == NULL)
	{
		return (-1);
	}
	while ((fun + k)->command)
	{
		if (_strcmp(cmd[0], (fun + k)->command) == 0)
			return (0);
		k++;
	}
	return (-1);
}

/**
 * exit_bul - Exit Status for built-in commands
 * @cmd: Array of parsed command strings
 * @input: Input recieved from user (to be freed)
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * @c: Shell execution count
 * @stat: Exit status
 */

void exit_bul(char **cmd, char *input, char **argv, int c, int stat)
{
	int status;
	int k = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(stat);
	}
	while (cmd[1][k])
	{
		if (_isalpha(cmd[1][k++]) != 0)
		{
			_prerror(argv, c, cmd);
			free(input);
			free(cmd);
			exit(2);
		}
		else
		{
			status = _atoi(cmd[1]);
			if (status == 2)
			{
				_prerror(argv, c, cmd);
				free(input);
				free(cmd);
				exit(status);
			}
			free(input);
			free(cmd);
			exit(status);

		}
	}
}
