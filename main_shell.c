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
		pid_t new_pid = fork();
		char *str;
		char **splits;

		if (new_pid == 0)
		{
		prompt();
		}
		str = input_string();
		splits = split_line(str);
		_exec(splits);

		free(str);
		free(splits);
	}
	return (0);
}
