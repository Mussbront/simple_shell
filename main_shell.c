#include "shell.h"
/**
  * main - check code
  *
  *
  * Return: 0 always
  */

int main(void)
{
	while (true)
	{
		char *str;
		char **splits;

		prompt();
		str = input_string();
		splits = split_line(str);
		/* execve here */

		free(str);
		free(splits);
	}
	return (0);
}
