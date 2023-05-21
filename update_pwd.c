#include "main.h"

/**
  * update_pwd - sets the new pwd
  * @new_path: the new pwd
  *
  * Return: Void
  */

void update_pwd(char *new_path)
{
	if (my_setenv("PWD", new_path, 1) != 0)
	{
		perror("update_pwd: error updating PWD");
	}
}
