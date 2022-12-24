#ifndef SHELL_H
#define SHELL_H

/* LIBRARIES */

#include <stdio.h> /* for printf */
#include <unistd.h> /* for fork, execve*/
#include <sys/types.h> /* for type pid */
#include <sys/wait.h> /* for wait */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> /* for strtok */
#include <errno.h> /* for errno and perror */
#include <sys/stat.h> /* for use of stat function */
#include <signal.h> /* for signal management */
#include <fcntl.h> /* for open files */

/* MACROS */

#include "macros.h" /* for msg help and prompt */

/* STRUCTURES */

/**
  * struct info - struct for the program's data
  * @program_name: the name of the executable
  * @input_line: pointer to input read for _getline
  * @alias_list: array of pointers with aliases
  * @exec_counter: number of excecuted comands
  * @tokens: pointer to array of tokenized input
  * @command_name: pointer to the first command typed by the user
  * @file_descriptor: file descriptor to the input of commands
  * @env: copy of the environ
 */
typedef struct info
{
	char *program_name;
	char *input_line;
	char **alias_list;
	int exec_counter;
	char **tokens;
	char *command_name;
	int file_descriptor;
	char **env;
} data_of_program;

/**
  * struct builtins - struct for the builtins
  * @builtin: the name of the builtin
  * @function: the associated function to be called for each builtin
  */
typedef struct builtins
{
	char *builtin;
	int (*function)(data_of_program *data);
} builtins;



/* PROTOTYPES */

/*Inicialize the struct with the info of the program */
void inic_data(data_of_program *data, int arc, char *argv[], char **env);
/* Makes the infinite loop that shows the prompt */
void prompt(char *prompt, data_of_program *data);
/*Print the prompt in a new line */
void ctrl_c(int opr UNUSED);
/* Read one line of the standar input */
int _getline(data_of_program *data);
/* split each line for logical operators if they exist */
int logic_ops(char *array_commands[], int i, char array_operators[]);
/* expand variables */
void expand_variables(data_of_program *data);
/*expand aliases */
void expand_alias(data_of_program *data);
/* append the string to the end of the buffer */
int buffer_add(char *buffer, char *str_to_add);
/* Separate the string in tokens using a designed delimiter */
void tokenize(data_of_program *data);
/* Create a pointer to part of a string */
char *_strtok(char *line, char *delim);
/* Execute a command with its entire path */
void exec(data_of_program *data);
/* executes builtin if matched */
int builtins_list(data_of_program *data);
/* Creates aaray of path directories */
char **tokenize_path(data_of_program *data);
/* Search for program in path */
int find_prog(data_of_program *data);

#endif
