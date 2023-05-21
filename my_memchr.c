#include "main.h"

/**
  * _memchr - returns the first occurence of c
  * @str: string to be processed
  * @c: character to be found
  * @n: number of characters
  *
  * Return: Void
  */

void *_memchr(const void *str, int c, size_t n)
{
	const unsigned char *ptr = str;

	while (n-- != 0)
	{
		if ((unsigned char)c == *ptr++)
		{
			return ((void *)(ptr - 1));
		}
	}

	return (NULL);
}
