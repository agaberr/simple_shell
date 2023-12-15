#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <ctype.h>


extern char **environ;
#define DELIM " :\t\r\n"

#define true 1
#define false 0
#define fail -1

char *read_command();
char **tokenize(char *input_cmd);
int execute_cmd(char **args, char *program_name, int num);
void free_2D_arr(char **args);
char *concat_path_command(char *PATH, char *command);
char *find_path(char *input_cmd);
void print_not_found(char *program_name, int cmd_num, char *input_cmd);
int built_in_functions(char **args, int exit_stat, char *cmd,
int *status, char *program_name, int cmd_num);


#endif
