#include "main.h"

/**
  * get_new_dir_oldpwd - gets directory from old pwd
  *
  * Return: the new directory
  */

char *get_new_dir_oldpwd(void)
{
	char *new_dir;

	new_dir = my_getenv("OLDPWD");
	if (new_dir == NULL)
	{
		perror("cd: error");
	}
	else
	{
		printf("%s\n", new_dir);
	}

	return (new_dir);
}

