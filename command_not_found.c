#include "main.h"

/**
  * handle_command_not_found - error handling
  * @args: argument vectors
  *
  * Return: (1);
  */

int handle_command_not_found(char **args)
{
	char *error_msg = ": 1: %s: not found\n";

	write(STDERR_FILENO, args[0], _strlen(args[0]));
	write(STDERR_FILENO, error_msg, _strlen(error_msg));

	return (1);
}
