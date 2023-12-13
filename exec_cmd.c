#include "main.h"

/**
* exec_cmd - fork and execute the command
* @input: command entered
*
* Return: status
*/

int exec_cmd(char *input)
{

	pid_t pid;
	int status;

	char **args = tokenize(input);

	pid = fork();
	if (pid == -1)
	{
		perror("error in fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0) /*child*/
	{

		if (execve(args[0], args, NULL) == fail)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else /*parent*/
	{

		waitpid(pid, &status, 0);

		return (WEXITSTATUS(status));

	}

	return (WEXITSTATUS(status));
}

