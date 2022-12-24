#include "shell.h"
/**
  * exec - Executes command
  * @data: a pointer to the program's data
  * Return: Success (0)
  */
void exec(data_of_program *data)
{
	int retval = 0, status;
	pid_t pid;

	/* check for program in built ins */
	retval = builtins_list(data);
	if (retval != -1)/* if program was found in built ins */
		return (retval);
	
	/* check for program file system */
	retval = find_program(data);
	if (retval)
	{/* if program not found */
		return (retval);
	}
	else
	{/* if program was found */
		pidd = fork(); /* create a child process */
		if (pidd == -1)
		{/* if the fork call failed */
			perror(data->command_name);
			exit(EXIT_FAILURE);
		}
		if (pidd == 0)
		{/* I am the child process, I execute the program*/
			retval = execve(data->tokens[0], data->tokens, data->env);
			if (retval == -1) /* if error when execve*/
				perror(data->command_name), exit(EXIT_FAILURE);
		}
		else 
		{/* This is the parent */
			wait(&status);
			if (WIFEXITED(status))
				errno = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				errno = 128 + WTERMSIG(status);
		}
	}
	return (0);
}
