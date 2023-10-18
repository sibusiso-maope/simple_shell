#include "shell.h"

/**
 * history - write file with user inputs
 * @input: user input
 * Return: 0 on success -1 if failed
 */

int history(char *input)
{
	char *filename = ".simple_shell_history";
	ssize_t fd, y;
	int length = 0;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);

	if (fd < 0)
		return (-1);
	if (input)
	{
		while (input[length])
			length++;
		y = write(fd, input, length);
		if (y < 0)
			return (-1);
	}
	return (1);
}
