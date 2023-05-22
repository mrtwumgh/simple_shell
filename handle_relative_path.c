#include "main.h"

/**
  * handle_relative_path - handles the relative path
  * @path: the path
  * @path_command: the path command
  * @command: the command
  * @result: the result to returned
  *
  * Return: the result
  */

char **handle_relative_path(char *path, char *path_command,
				char *command, char **result)
{
	free(path);
	result[0] = path_command;
	result[1] = command;

	return (result);
}

