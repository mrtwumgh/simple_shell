#include "main.h"

/**
  * read_line - reads the commandline
  *
  * Return: the line
  */

char *read_line(void)
{
	char *line = NULL;
	size_t buffer_size = 0;
	ssize_t bytes_read;

	bytes_read = my_getline(&line, &buffer_size, STDIN_FILENO);

	if (bytes_read == -1)
	{
		if (feof(stdin))
		{
			print_chars("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}

	return (line);
}
