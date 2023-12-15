#include "main.h"

/**
* main - Entry point
* @argc: number of arguments
* @argv: arguments
* @envp: enviroment args
*
* Return: Always success (0)
*/

int main(int argc, char **argv, char **envp)
{

	char *input_cmd = NULL;
	char **args = NULL;
	int stat = 0, i = 0, exit_stat;
	(void)argc, (void) envp;

	while (true)
	{
		input_cmd = read_command();

		if (!input_cmd)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			return (stat);
		}
		i++;

		args = tokenize(input_cmd);

		if (!args)
			continue;

		if (argv[1])
			exit_stat = atoi(argv[1]);

		if (!built_in_functions(args, exit_stat, args[0], &stat, argv[0], i))
			stat = execute_cmd(args, argv[0], i);

	}
}
