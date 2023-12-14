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
	write(STDIN_FILENO, "\n$ ", 3);
	signal(SIGINT, handler);
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
	int flag = 0, l_size = 0; /*index of \n in input_cmd*/
	char **args = NULL;
	(void) envp, (void) argv;
	signal(SIGINT, handler);

	if (argc < 1)
		return (-1);

	while (true)
	{
		/*read input from user*/
		if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
		{
			flag == true;
			write(STDERR_FILENO, "$ ", 2);
		}
		if (getline(&input_cmd, &input_size, stdin) == fail)
			break;

		/*remove \n in end of input_cmd*/
		l_size = strcspn(input_cmd, "\n");
		input_cmd[l_size] = '\0';

		args = tokenizer(input_cmd);
		if (!args || !*args || **args == '\0')
			continue;


		if (execute_cmd(args, input_cmd, argv[0]))
			continue;
		if (execute_path(args, argv[0]))
			continue;

	}
	if (l_size == fail && flag)
		write(STDERR_FILENO, "\n", 1);
	free(input_cmd);
	return (0);
}
