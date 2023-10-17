#include "shell.h"

/**
 * create_environment - creates an array of rnviroment variables
 * @envi: Array to store enviroment variables
 */

void create_environment(char **envi)
{
	int k;

	for (k = 0; environ[k]; k++)
		envi[k] = _strdup(environ[k]);
	envi[k] = NULL;
}

/**
 * free_envinronment - Free the memory of the created enviroment variables array
 * @env:  Array of environment variables
 */

void free_environment(char **env)
{
	int k;

	for (k = 0; env[k]; k++)
	{
		free(env[k]);
	}
}
