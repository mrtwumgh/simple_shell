#include "main.h"

/**
  * _strcmp - compares two strings
  * @s1: first string
  * @s2: second string
  *
  * Return: 0 if equal, 1 or -1 if unequal
  */

int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int status = 0;

	if (s1 == NULL || s2 == NULL)
	{
		return (-1);
	}
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] < s2[i])
			{
				status = -1;
			}
			else
			{
				status = 1;
			}
		}
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
	{
		status = 0;
	}
	else
	{

		if (s1[i] == '\0')
		{
			status = -1;
		}
		else
		{
			status = 1;
		}
	}
	return (status);
}
