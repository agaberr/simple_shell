#include "main.h"

/**
* built_in_functions - excute built in functions
* @args: arguments passed
* @cmd: command passed
* @exit_stat: exit status of shell
* @status: status
* @program_name: program name
* @cmd_num: number of commands entered
*
* Return: 1 if excuted, 0 otherwise
*/

int built_in_functions(char **args, int exit_stat, char *cmd,
int *status, char *program_name, int cmd_num)
{
	int i;

	if (strcmp(cmd, "exit") == false)
	{

		if (exit_stat <= 0)
		{
			print_not_found(program_name, cmd_num, args[1]);
			return (true);
		}
		free_2D_arr(args);
		exit(exit_stat);
	}
	else if (strcmp(cmd, "env") == false)
	{
		for (i = 0; environ[i]; i++)
		{
			write(STDOUT_FILENO, environ[i], strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);

		}
		free_2D_arr(args);
		(*status) = 0;
		return (true);
	}

	return (false);
}
