#include "main.h"

/**
  * _memcpy - copies the memory area
  * @dest: the target
  * @src: the source string
  * @n: the number of bytes to copy
  *
  * Return: the pointer to dest
  */

char *_memcpy(char *dest, const char *src, unsigned int n)
{
	unsigned int i = 0;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}
