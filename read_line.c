#include "main.h"

/**
* read_line - Read input from user
* @input: array of strings (commands)
*
* Return: size of input if succeded, 0 otherwise
*/

int read_line(char *input)
{

	size_t input_size = 0;
	int size = 0;

	/*print $ in interactive mode*/
	/*if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))*/
	/*flags.interactive = 1;*/
	/*if (flags.interactive)*/
		/*write(STDERR_FILENO, "$ ", 2);*/

	/*read cmd from user and return number of */
	size = getline(&input, &input_size, stdin);
	printf("Input: %s\n", input);
	return (size);
}
