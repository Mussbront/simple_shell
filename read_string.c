#include "shell.h"
/**
  * input_string - read string from stdin
  *
  * Return: str
  *
  */
char *input_string(void)
{
	char *str;
	size_t string_len = 10;

	str = NULL;

	getline(&str, &string_len, stdin);


	return (str);
}

