#include "main.h"

/**
  * main - entry point into shell program
  * @argc: argument count
  * @argv: argument vector
  *
  * Return: 0 always success
  */

int main(int __attribute__((unused)) argc, char *argv[])
{
	int fd;

	if (isatty(STDIN_FILENO))
	{
		interactive_mode();
	}
	else if (argv[1])
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror("Error reading file");
			return (1);
		}
		non_interactive_mode(fd);
	}
	else
	{

		non_interactive_mode(STDIN_FILENO);
	}

	return (0);
}
