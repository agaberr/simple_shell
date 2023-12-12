#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>

#define true 1
#define false 0
#define fail -1
#define DELIM " "



int read_line(char **input, size_t *input_size);
char ** tokenize(char *input);
int exec_cmd(char *input);


#endif
