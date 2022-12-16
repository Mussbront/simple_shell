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
		char *split;

		prompt();
		str = input_string();
		split = split_line(str);


		free(str);
		free(split);
	}
	return (0);
}
