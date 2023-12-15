#include "main.h"
/**
* execute_cmd - Excute the command entered
* @args: array of strings user entered
* @program_name: program name
* @num: number of errors
*
*  Return: 1 if executed, 0 otherwise
*/

int execute_cmd(char **args, char *program_name, int num)
{
	pid_t pid;
	int status;


	char *cmd = find_path(args[0]);

	if (!cmd)
	{
		print_not_found(program_name, num, args[0]);
		free_2D_arr(args);
		return (127);
	}


	pid = fork();
	if (pid == 0) /*child*/
	{
		if (execve(args[0], args, environ) == fail)
		{
			free_2D_arr(args);
			free(cmd);
			cmd = NULL;
		}
	}
	else /*parent*/
	{
		waitpid(pid, &status, 0);
		free_2D_arr(args);
		free(cmd);
		cmd = NULL;
	}
	return (WEXITSTATUS(status));
}
