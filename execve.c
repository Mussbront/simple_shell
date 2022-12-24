#include "shell.h"
/**
  * _exec - execute program by pathname
  * @args: array
  * Return: 0
  */
int _exec(char **args)
{
	int status;

	pid_t child_pid = fork();

	if (child_pid == 0)
	{
		if (args != NULL)
		{
			execve(args[0], args, NULL);
			perror("Jsh");
			exit(1);
		}
	}

	close(child_pid);
	if (child_pid != 0)
	{
		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
	{
		wait(NULL);
		perror("Jsh");
	}
	return (0);
}

