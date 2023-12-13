#include "main.h"

/**
* read_line - Read input from user
* @input: array of strings (commands)
* @input_size: size the input string
*
* Return: 1 if succeded, 0 otherwise
*/

int read_line(char **input, size_t *input_size)
{
	if (isatty(STDIN_FILENO))
		printf("$ ");

	*input_size = 0;
	*input = NULL;

	if (getline(input, input_size, stdin) == -1)
	{
		printf("\n");
		return (false);
	}
	return (true);
}
