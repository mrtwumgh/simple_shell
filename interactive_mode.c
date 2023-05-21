#include "main.h"

/**
  * interactive_mode - displays prompt and waits for user interaction
  *
  * Return: Void
  */

void interactive_mode(void)
{
	char *line;
	char **command;
	int stat;
	char *prompt = "$ ";

	do {
		print_chars(prompt);
		fflush(stdout);
		line = read_line();
		if (line[0] == '#')
		{
			free(line);
			continue;
		}
		command = split_line(line);
		stat = _exec(command);

		free(line);
		free(command);
	} while (stat);
}

