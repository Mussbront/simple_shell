#include "shell.h"
/**
  * split_line - tokenize input
  * @string: pointer to string
  * Return: split
  *
  */
char* split_line(char *str)
{
	char delim[] = " \n\t\r";
	char *split = strtok(str, delim);

	while (split != NULL)
	{
		split = strtok(NULL, delim);
	}


	return (split);
}
