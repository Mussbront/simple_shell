#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
char* input_string(void);
/**
  * input_string - read string from stdin
  * @str: array pointer to string
  *
  * Return: str
  *
  */
char* input_string(void)
{
	char *str = NULL;
	size_t string_len = 10;

	str = malloc(sizeof(char) * string_len);

	getline(&str, &string_len, stdin);


	return (str);
}

