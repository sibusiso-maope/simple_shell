#include "shell.h"

/**
 * _calloc - allocates memory for an array using malloc
 *@size: size
 *Return: void pointer
 */

void *_calloc(unsigned int size)
{
	char *c;
	unsigned int k;

	if (size == 0)
		return (NULL);

	c = malloc(size);

	if (c == NULL)
		return (NULL);
	for (k = 0; k < size; k++)
	{
		c[k] = '\0';
	}
	return (c);
}

/**
 * free_allocated - free memory allocated
 * @cmd: array pointer
 * @line: char pointer
 * Return: Void
 */

void free_allocated(char **cmd, char *line)
{
	free(cmd);
	free(line);
	cmd = NULL;
	line = NULL;
}

/**
 * _reallocate -  reallocates a memory block using malloc and free
 *@ptr: pointer
 *@old_size: previous Size Of The Pointer
 *@new_size: new size of the pointer
 *Return: Pointer to reallocated memory
 */

void *_reallocate(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	result = malloc(new_size);

	if (result == NULL)
	{
		free(result);
		return (NULL);
	}
	if (ptr == NULL)
	{
		fill_an_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, old_size);
		free(ptr);
	}
	return (result);
}


/**
 * fill_an_array - fill an array by constant byte
 *@a: void pointer
 *@el: int
 *@len: length for int
 *Return: void pointer
 */

void *fill_an_array(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int k = 0;

	while (k < len)
	{
		*p = el;
		p++;
		k++;
	}
	return (a);
}

/**
 * _memcpy - copy bytes of memory from source to destination
 *@dest: destination pointer
 *@src: source pointer
 *@n: size to be copied
 *Return: pointer to destination
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int k;

	for (k = 0; k < n; k++)
	{
		dest[k] = src[k];
	}
	return (dest);
}
