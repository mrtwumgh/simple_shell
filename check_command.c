#include "main.h"

/**
  * check_command - checks if a command exists in the path
  * @command: command to be checked
  *
  * Return: 0 if command is not found
  */

char **check_command(char *command)
{
	char *path, *dir, *path_command;
	struct stat buffer;
	size_t path_len;
	char **result = (char **)malloc(sizeof(char *) * 2);

	if (result == NULL || (command[0] == '/' && stat(command, &buffer) != 0))
		return (NULL);
	if (stat(command, &buffer) == 0)
	{
		return (handle_abs_path(command, result));
	}
	path = my_getenv("PATH");
	if (path == NULL)
		return (NULL);
	path_len = _strlen(path);
	path = _strdup(path);
	if (path == NULL)
		return (NULL);
	path_command = (char *)malloc(path_len + strlen(command) + 2);
	if (path_command == NULL)
		return (NULL);
	dir = my_strtok(path, ":");
	while (dir != NULL)
	{
		build_path_command(path_command, dir, command);
		if (stat(path_command, &buffer) == 0)
		{
			return (handle_relative_path(path, path_command, command, result));
		}
		dir = my_strtok(NULL, ":");
	}
	free(path);
	free(path_command);
	return (NULL);
}
