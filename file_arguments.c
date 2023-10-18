#include "shell.h"

/**
 * treat_file - Parse commands and handle their execution
 * @line: Line from file
 * @count: Error counter
 * @fp: File descriptor
 * @argv: Command line arguments
 */

void treat_file(char *line, int count, FILE *fp, char **argv)
{
	char **command;
	int stat = 0;

	command = parse_command(line);

	if (_strncmp(command[0], "exit", 4) == 0)
		exit_bul_for_file(command, line, fp);

	else if (check_builtin(command) == 0)
	{
		stat = handle_builtin(command, stat);
		free(command);
	}

	else
	{
		stat = check_command(command, line, count, argv);
		free(command);
	}
}

/**
 * exit_bul_for_file - Exit status handler for file input
 * @line: Line from a file
 * @cmd: Parsed command
 * @fd: File Descriptor
 */

void exit_bul_for_file(char **cmd, char *line, FILE *fd)
{
	int status;
	int k = 0;

	if (cmd[k] == NULL)
	{
		free(line);
		free(cmd);
		fclose(fd);
		exit(errno);
	}
	while (cmd[1][k])
	{
		if (_isalpha(cmd[1][k++]) < 0)
			perror("Illegal number");
	}

	status = _atoi(cmd[1]);
	free(line);
	free(cmd);
	fclose(fd);
	exit(status);
}

/**
 * read_file - Reads commands from the argument File
 * @file: File containing commands
 * @argv: Arguments passed
 * Return: -1 or 0
 */

void read_file(char *file, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t length = 0;
	int count = 0;

	fp = fopen(file, "r");

	if (fp == NULL)
	{
		error_file(argv, count);
		exit(127);
	}
	while ((getline(&line, &length, fp)) != -1)
	{
		count++;
		treat_file(line, count, fp, argv);
	}
	if (line)
		free(line);
	fclose(fp);
	exit(0);
}
