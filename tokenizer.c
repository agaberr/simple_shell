#include "main.h"

/**
* tokenizer - split string into array of words
* @input_cmd: input string command from user
*
* Return: array of strings splitted by " "
*/

char **tokenizer(char *input_cmd)
{
	size_t i = 0;
	int len = 2, flag = 0;
	char **argv = NULL;
	char *cmd_cpy = NULL, *token = NULL, *ptr = NULL;

	cmd_cpy = _strdup(input_cmd);

	if (cmd_cpy == NULL)
		return (NULL);
	ptr = cmd_cpy;
	while (*ptr)
	{
		if (strchr(DELIM, *ptr) && !flag)
		{
			len++;
			flag = 1;
		}
		else if (!strchr(DELIM, *ptr) && flag)
			flag = 0;
		ptr++;
	}
	argv = malloc(sizeof(char *) * (len));
	token = strtok(cmd_cpy, DELIM);

	while (token)
	{
		argv[i] = _strdup(token);

		if (argv[i] == NULL)
		{
			free_2D_arr(argv);
			return (NULL);
		}
		token = strtok(NULL, DELIM);
		i++;
	}
	argv[i] = NULL;
	return (argv);
}
