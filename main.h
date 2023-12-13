#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include<signal.h>

#define true 1
#define false 0
#define fail -1
#define DELIM " :\t\r\n"

extern char **environ;


char *_strdup(char *s);


void free_2D_arr(char **args);


int read_line(char *input);
char **tokenizer(char *input_cmd);
char *get_path(void);
int execute_cmd(char **args, char *input_cmd);
/*void execute_path(char **args, char *program_name);*/





#endif
