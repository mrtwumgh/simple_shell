#include "main.h"

/**
  * get_new_dir_home - gets new dir from home
  *
  * Return: new directory
  */

char *get_new_dir_home(void)
{
	char *new_dir;

	new_dir = my_getenv("HOME");
	if (new_dir == NULL)
	{
		perror("cd: error");
	}

	return (new_dir);
}

