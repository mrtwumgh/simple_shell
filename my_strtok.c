#include "main.h"

/**
  * my_strtok - tokenizes strings
  * @str: string to be tokenized
  * @delim: delimiter
  *
  * Return: tokens
  */

char *my_strtok(char *str, const char *delim)
{
	static char *next_token;
	int i = 0;
	char *current_token;

	if (str)
		next_token = str;
	if (!next_token || !*next_token)
		return (NULL);
	while (*next_token)
	{
		for (i = 0; delim[i]; i++)
			if (*next_token == delim[i])
				break;
		if (!delim[i])
			break;
		next_token++;
	}
	current_token = next_token;
	while (*next_token)
	{
		for (i = 0; delim[i]; i++)
			if (*next_token == delim[i])
				break;
		if (delim[i])
		{
			*next_token++ = '\0';
			break;
		}
		next_token++;
	}
	return (current_token);
}
