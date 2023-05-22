#include "main.h"

/**
  * handle_cd - handles change directory
  * @args: argument vectors
  *
  * Return: 1
  */

int handle_cd(char **args)
{
	char *new_dir;
	char cwd[PATH_MAX];

	if (args[1] == NULL)
	{
		new_dir = get_new_dir_home();
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		new_dir = get_new_dir_oldpwd();
	}
	else
	{
		new_dir = args[1];
	}
	if (new_dir == NULL)
	{
		return (1);
	}
	if (chdir(new_dir) != 0)
	{
		perror("cd");
	}
	else if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		update_pwd(cwd);
	}
	else
	{
		perror("cd: error");
	}

	return (1);
}

