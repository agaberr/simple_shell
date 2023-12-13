#include "main.h"

/**
* main - Entry point
*
* Return: Always 0 (success)
*/

int main(void)
{
	char *input = NULL;
	size_t input_size = 0;
	int len = 0;

	while (true)
	{
		if (read_line(&input, &input_size) == 0)
			break;

		len = strcspn(input, "\n");
		input[len] = '\0';

		if (strcmp(input, "exit") == 0)
			exit(0);

		exec_cmd(input);
	}

	free(input);

	return (0);
}
