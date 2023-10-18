#include "shell.h"

/**
 * history_display - display history of user input on simple_shell
 * @c: parsed command
 * @st: status of last command executed
 * Return: 0 success or -1 if fail
 */

int history_display(__attribute__((unused))char **c, __attribute__((unused))int st)
{
	char *file_name = ".simple_shell_history";
	FILE *fp;
	char *line = NULL;
	size_t length = 0;
	int counter = 0;
	char *er;

	fp = fopen(file_name, "r");

	if (fp == NULL)
	{
		return (-1);
	}
	while ((getline(&line, &length, fp)) != -1)
	{
		counter++;
		er = _itoa(counter);
		PRINT(er);
		free(er);
		PRINT(" ");
		PRINT(line);
	}
	if (line)
		free(line);
	fclose(fp);
	return (0);
}

/**
 * display_environment - Display enviroment variable
 * @cmd: parsed command
 * @st: status of last command executed
 * Return: Always 0
 */

int display_environment(__attribute__((unused)) char **cmd, __attribute__((unused)) int st)
{
	size_t k;
	int length;

	for (k = 0; environ[k] != NULL; k++)
	{
		length = _strlen(environ[k]);
		write(1, environ[k], length);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
 * change_directory - Changes directory
 * @cmd: Parsed command
 * @st: Status of last command executed
 * Return: 0 on success 1 if failed (For OLDPWD Always 0 incase of no OLDPWD)
 */
int change_directory(char **cmd, __attribute__((unused))int st)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
		value = chdir(getenv("HOME"));

	else if (_strcmp(cmd[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
		value = chdir(cmd[1]);

	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}

	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}

/**
 * echo_bul - execute echo cases
 * @st: statue of last command executed
 * @cmd: parsed command
 * Return: Always 1 Or execute normal echo
 */

int echo_bul(char **cmd, int st)
{
	char *path;
	unsigned int pid = getppid();

	if (_strncmp(cmd[1], "$?", 2) == 0)
	{
		print_number_int(st);
		PRINT("\n");
	}

	else if (_strncmp(cmd[1], "$$", 2) == 0)
	{
		print_number(pid);
		PRINT("\n");
	}

	else if (_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		PRINT(path);
		PRINT("\n");
		free(path);
	}

	else
		return (print_echo(cmd));

	return (1);
}
