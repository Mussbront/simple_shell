#include "shell.h"
/**
  * split_line - tokenize input
  * @str: pointer to string
  * Return: split
  *
  */
char **split_line(char *str)
{
	int len = 32;
	char **splits = malloc(sizeof(char *) * len);


	char delim[] = " \n\t\r";
	char *split = strtok(str, delim);

	while (split != NULL)
	{
		splits[0] = split;
		split = strtok(NULL, delim);
	}


	return (splits);

}
