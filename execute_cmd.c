#include "main.h"
/**
* execute_cmd - Excute the command entered
* @args: array of strings user entered
* @input_cmd: string user entered
* @program_name: program name
*
*  Return: 1 if executed, 0 otherwise
*/

int execute_cmd(char **args, char *input_cmd, char *program_name)
{	pid_t pid;
	char **env = environ;
	int is_env_or_exit = false, status, i = 0, env_len = strlen(env[i]);
	/* check if the cmd is exit or env or not */
	if (!strcmp(*args, "exit"))
	{
		is_env_or_exit = true;
		free(input_cmd);
		free_2D_arr(args);
		exit(0);
	}
	else if (!strcmp(*args, "env"))
	{
		is_env_or_exit = true;
		while (env[i])
		{
			write(STDOUT_FILENO, "\n", 1);
			write(STDOUT_FILENO, (const void *) env[i], env_len);
			i++;
		}
	}
	if (is_env_or_exit)
		return (true);
	else if (**args == '/')
	{pid = fork();
		if (pid == 0) /*child*/
		{
			if (execve(args[i], args, env) == fail)
			{
				perror(program_name);
				free_2D_arr(args);
				exit(98);
			}
		}
		else if (pid > 0) /*parent*/
			wait(&status);
		else
			perror(program_name);
		return (true);
	}
	return (false);
}

