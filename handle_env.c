#include "main.h"

/**
  * handle_env - handles environmental variables
  *
  * Return: 1
  */

int handle_env(void)
{
	int i = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		print_chars(environ[i]);
		print_chars("\n");
	}

	return (1);
}

