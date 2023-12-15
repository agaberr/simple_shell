#include "main.h"

/**
* print_not_found - print error msg when cmd not found
*
* @program_name: program name
* @cmd_num: number of cmds
* @input_cmd: cmd entered
*
*/

void print_not_found(char *program_name, int cmd_num, char *input_cmd)
{
	char cmd_num_str[20];

	sprintf(cmd_num_str, "%d", cmd_num);

	write(STDERR_FILENO, program_name, strlen(program_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd_num_str, strlen(cmd_num_str));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, input_cmd, strlen(input_cmd));
	write(STDERR_FILENO, ": not found", 11);

}
