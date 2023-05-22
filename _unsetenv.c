#include "main.h"

/**
  * _unsetenv - unsets a variable
  * @name: variable name
  *
  * Return: 0 on success
  */

int _unsetenv(const char *name)
{
	char **ep, **sp;
	size_t len;

	if (name == NULL || *name == '\0' || strchr(name, '=') != NULL)
	{
		return (-1);
	}

	len = strlen(name);

	for (ep = environ; *ep != NULL; )
	{
		if (strncmp(*ep, name, len) == 0 && (*ep)[len] == '=')
		{
			for (sp = ep; *sp != NULL; sp++)
				*sp = *(sp + 1);
		}
		else
		{
			ep++;
		}
	}

	return (0);
}

