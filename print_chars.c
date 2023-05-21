#include "main.h"

/**
  * print_chars - prints characters
  * @str: string to be printed
  *
  * Return: void
  */

void print_chars(char *str)
{
	int i = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
}
