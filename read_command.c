#include "main.h"

/**
 * read_command - read command from user
 *
 * Return: input command entered
*/


char *read_command()
{
	size_t input_size = 0;
	char *input_cmd = NULL;

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
	if (getline(&input_cmd, &input_size, stdin) == fail)
	{
		free(input_cmd);
		return (NULL);
	}
	return (input_cmd);
}
