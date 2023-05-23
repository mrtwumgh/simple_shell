#include "main.h"

/**
  * _unsetenv - unsets a variable
  * @name: variable name
  *
  * Return: 0 on success
  */

int _unsetenv(const char *name)
{
	char **env_p, **shift_p;
	size_t length;

	if (name == NULL || *name == '\0' || strchr(name, '=') != NULL)
	{
		return (-1);
	}

	length = _strlen(name);

	for (env_p = environ; *env_p != NULL; )
	{
		if (strncmp(*env_p, name, length) == 0 && (*env_p)[length] == '=')
		{
			for (shift_p = env_p; *shift_p != NULL; shift_p++)
				*shift_p = *(shift_p + 1);
		}
		else
		{
			env_p++;
		}
	}

	return (0);
}

