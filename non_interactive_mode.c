#include "main.h"

/**
  * non_interactive_mode - non_interactive mode for the shell
  * @fd: file descriptor
  *
  * Return: Void
  */

void non_interactive_mode(int fd)
{
	char *command = NULL;
	size_t buffer_size = 0;
	ssize_t bytes_read;
	int stat;
	char **args;

	while ((bytes_read = my_getline(&command, &buffer_size, fd)) != -1)
	{
		if (bytes_read > 0)
		{
			command[bytes_read - 1] = '\0';
		}
		if (command[0] == '\0')
		{
			free(command);
			continue;
		}
		args = split_line(command);
		if (args == NULL)
		{
			free(command);
			continue;
		}
		stat = _exec(args);

		free(args);

		if (!stat)
		{
			break;
		}
		command = NULL;
		buffer_size = 0;
	}
	free(command);
}
