#include "main.h"

/**
  * handle_abs_path - handles the absolute path
  * @command: the command
  * @result: the result to be returned
  *
  * Return: the result
  */

char **handle_abs_path(char *command, char **result)
{
	result[0] = _strdup(command);
	result[1] = command;

	return (result);
}
