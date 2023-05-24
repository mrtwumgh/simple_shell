#include "main.h"

/**
  * split_line - tokenizes the command
  * @line: the line to be tokenized
  *
  * Return: the token
  */

char **split_line(char *line)
{
	int buffer_size = TOK_BUFSIZE;
	int pos = 0;
	char **tokens;
	char *token;

	tokens = (char **)malloc(sizeof(char *) * buffer_size);
	if (tokens == NULL)
	{
		perror("split_line: allocation error");
		exit(EXIT_FAILURE);
	}
	if (line == NULL)
		return (tokens);

	token = my_strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		tokens[pos] = token;
		pos++;

		if (pos >= buffer_size)
		{
			buffer_size += TOK_BUFSIZE;
			tokens = realloc(tokens, sizeof(char *) * buffer_size);
			if (tokens == NULL)
			{
				perror("split_line: reallocation error");
				exit(EXIT_FAILURE);
			}
		}

		token = my_strtok(NULL, TOK_DELIM);
	}
	tokens[pos] = NULL;

	return (tokens);
}
