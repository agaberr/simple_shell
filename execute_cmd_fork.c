#include "main.h"
/**
* execute_cmd_fork - Excute the command entered (forked)
* @command: command
* @args: arguments passed
*
*  Return: None
*/

void execute_cmd_fork(char *command, char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0) /*child*/
	{

		execve(command, args, environ);
		free_2D_arr(args);
		perror(args[0]);
		exit(98);
	}
	else if (pid > 0) /*parent*/
		wait(&status);
	else
		perror(args[0]);
}
