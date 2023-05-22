#include "main.h"

/**
  * my_getenv - gets environmental variable
  * @name: name of variable
  *
  * Return: the value of variable
  */

char *my_getenv(const char *name)
{
	int i = 0;
	size_t len = 0;

	len = _strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{
			return (&environ[i][len + 1]);
		}
	}

	return (NULL);
}
