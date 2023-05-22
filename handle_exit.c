#include "main.h"

/**
  * handle_exit - handles exit
  * @args: argument vectors
  *
  * Return: Void
  */

void handle_exit(char **args)
{
	int exit_status;

	if (args[1] != NULL)
	{
		exit_status = atoi(args[1]);
		exit(exit_status);
	}
	exit(EXIT_SUCCESS);
}
