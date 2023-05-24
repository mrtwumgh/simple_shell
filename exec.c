#include "main.h"

/**
  * _exec - executes arguments
  * @args: arguments to be executed
  *
  * Return: 1
  */

int _exec(char **args)
{
	pid_t pid;
	int stat;
	char **command_path;

	if (strcmp(args[0], "exit") == 0)
	{
		return (handle_exit(args));
	}
	if (strcmp(args[0], "env") == 0)
	{
		return (handle_env());
	}

	if (strcmp(args[0], "cd") == 0)
	{
		return (handle_cd(args));
	}
	command_path = check_command(args[0]);
	if (command_path == NULL)
	{
		return (handle_command_not_found(args));
	}
	pid = fork();
	if (pid == 0)
	{
		handle_child_process(command_path, args);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork");
		free(command_path[0]);
		free(command_path);
		return (-1);
	}
	else
		waitpid(pid, &stat, 0);
	free(command_path[0]);
	free(command_path);
	return (1);
}
