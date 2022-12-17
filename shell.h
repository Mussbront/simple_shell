#ifndef _shell_h
#define _shell_h

/* LIBRARIES */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



/* PROTOTYPES */

char *input_string(void);
char **split_line(char *string);
int *prompt(void);


#endif
