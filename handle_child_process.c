#include "main.h"

/**
  * handle_child_process - handles child processes
  * @command_path: command path
  * @args: argument vectors
  *
  * Return: Void
  */

void handle_child_process(char **command_path, char **args)
{
	args[0] = command_path[0];
	if (execve(args[0], args, environ) == -1)
	{
		perror("execute");
	}
	exit(EXIT_FAILURE);
}
