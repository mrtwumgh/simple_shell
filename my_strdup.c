#include "main.h"

/**
  * _strdup - copies a string to malloc allocated pointer
  * @str: string to be copied
  *
  * Return: returns the pointer to the new string
  */


char *_strdup(char *str)
{
	char *s;
	int i;
	int len;

	if (str == NULL)
	{
		return (NULL);
	}

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}

	s = (char *)malloc(sizeof(*s) * len + 1);

	if (s == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < len; i++)
	{
		s[i] = str[i];
	}
	s[i] = '\0';

	return (s);
}
