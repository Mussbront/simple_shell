#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "shell.h"

/**
  * _exec - Executes program
  * @args: arguments to be passed
  * Return: Success (0)
  */

void _exec(char **args)
{
	int status;
	pid_t pid = fork();

	if (pid == 0)
	{
		if ((execve(args[0], args, NULL)) < 0)
		{
			perror("\nCould not fork");
			exit(1);
		}
	}
	else
	{
		do waitpid(pid, &status, 0);
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
