#include "shell.h"

int main(void)
{
	while (true)
	{
		char *str;
		char *split;

		printf("$ ");
		str = input_string();
		split = split_line(str);


		free(str);
		free(split);
	}
	return (0);
}
