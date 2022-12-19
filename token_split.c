#include "shell.h"
/**
  * split_line - tokenize input
  * @string: pointer to string
  * Return: split
  *
  */
#define BUF_LEN 1024
char **split_line(char *str)
{
	char **splits = malloc(sizeof(char *) * BUF_LEN);


	char delim[] = " \n\t\r";
	char *split = strtok(str, delim);

	while (split != NULL)
	{
		splits[0] = split;
		split = strtok(NULL, delim);
	}


	return (splits);

}
