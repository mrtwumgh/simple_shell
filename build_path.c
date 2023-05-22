#include "main.h"

/**
  * build_path_command - builds the path
  * @path_command: path command
  * @dir: directory
  * @command: command
  *
  * Return: void
  */

void build_path_command(char *path_command, char *dir, char *command)
{
	_strcpy(path_command, dir);
	_strcat(path_command, "/");
	_strcat(path_command, command);
}
