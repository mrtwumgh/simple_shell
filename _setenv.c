#include "main.h"

/**
  * my_setenv - sets environmental variable
  * @name: name of variable
  * @value: value of variable
  * @overwrite: overwrite value
  *
  * Return: 0 on success
  */

int my_setenv(const char *name, const char *value, int overwrite)
{
	char *env_value;
	size_t name_len;
	char *new_env;
	size_t value_len;

	if (name == NULL || value == NULL || name[0] == '\0')
	{
		return (-1);
	}

	env_value = my_getenv(name);
	if (env_value != NULL && overwrite == 0)
	{
		return (0);
	}

	name_len = _strlen(name);
	value_len = _strlen(value);
	new_env = malloc(name_len + value_len + 2);
	if (new_env == NULL)
	{
		return (-1);
	}

	_memcpy(new_env, name, name_len);
	new_env[name_len] = '=';
	_memcpy(new_env + name_len + 1, value, value_len);
	new_env[name_len + value_len + 1] = '\0';

	if (putenv(new_env) != 0)
	{
		return (-1);
	}

	return (0);
}
