#include "main.h"

/**
  * my_getline - gets a line from stdin
  * @lineptr: pointer to buffer vectors
  * @n: pointer to length of buffer
  * @fd: file descriptor
  *
  * Return: the total number of characters read
  */

ssize_t my_getline(char **lineptr, size_t *n, int fd)
{
	char buffer[BUFFER_SIZE];
	size_t total_read = 0;
	ssize_t bytes_read;

	if (*lineptr == NULL || *n == 0)
	{
		*n = BUFFER_SIZE;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
		{
			return (-1);
		}
	}
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (total_read + bytes_read + 1 > *n)
		{
			*n *= 2;
			*lineptr = realloc(*lineptr, *n);
			if (*lineptr == NULL)
			{
				return (-1);
			}
		}

		_memcpy(*lineptr + total_read, buffer, bytes_read);
		total_read += bytes_read;

		if (_memchr(buffer, '\n', bytes_read))
		{
			break;
		}
	}

	if (bytes_read == -1)
	{
		return (-1);
	}
	(*lineptr)[total_read] = '\0';
	return (total_read);
}
