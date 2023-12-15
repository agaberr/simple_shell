#include "main.h"

/**
* built_in_functions - excute built in functions
* @args: arguments passed
* @cmd: command passed
* @status: status
*
* Return: 1 if excuted, 0 otherwise
*/

int built_in_functions(char **args, char *cmd, int status)
{
	int i;

	if (strcmp(cmd, "exit") == false)
	{
		free_2D_arr(args);
		exit(status);
	}
	else if (strcmp(cmd, "env") == false)
	{
		for (i = 0; environ[i]; i++)
		{
			write(STDOUT_FILENO, environ[i], strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);

		}
		free_2D_arr(args);
		return (true);
	}

	return (false);
}