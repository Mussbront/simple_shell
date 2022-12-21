#include "shell.h"
/**
  * _exec - execute program by pathname
  * @args: array
  * Return: 0
  */
int _exec(char **args)
{
	int status;
	pid_t child = fork();

	if (child == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Jsh");
		}
	}
	else if (child > 0)
	{

		waitpid(child, &status, WUNTRACED);
	}

	else
	{
		perror("Jsh");
	}

	return (0);
}
