#include "main.h"

/**
* handler - Handle interrupt
* @signum: signal number
*
* Return: None
*/

void handler(int signum)
{
	(void) signum;
	write(STDERR_FILENO, "$ ", 2);
	write(STDERR_FILENO, "\n", 1);
	raise(SIGKILL);
}

/**
* main - Entry point
* @argc: number of arguments
* @argv: arguments
* @envp: enviroment args
*
* Return: Always success (0)
*/

int main(int argc, char *argv[], char *envp[])
{
	char *input_cmd = NULL;
	size_t input_size = 0;
	int l_size = 0; /*index of \n in input_cmd*/
	char **args = NULL;
	(void) envp, (void) argv;
	signal(SIGINT, handler);

	if (argc < 1)
		return (-1);

	while (true)
	{
		/*read input from user*/
		if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
			write(STDERR_FILENO, "$ ", 2);

		if (getline(&input_cmd, &input_size, stdin) == fail)
			break;

		/*remove \n in end of input_cmd*/
		l_size = strcspn(input_cmd, "\n");
		input_cmd[l_size] = '\0';

		args = tokenizer(input_cmd);

		if (!args || !*args || **args == '\0')
			continue;

		if (execute_cmd(args, input_cmd))
			continue;
		/*if(execute_path(args, argv[0]))*/
			/*continue;*/

		/*no such file or directory*/
		write(STDERR_FILENO, argv[0], strlen(argv[0]));
		write(STDERR_FILENO, " No such file or directory\n", 27);
	}

	free(input_cmd);
	return (0);
}
