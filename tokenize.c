#include "main.h"

/**
* tokenize - split string into array of words
* @input_cmd: input string command from user
*
* Return: array of strings splitted by " "
*/

char **tokenize(char *input_cmd)
{
	size_t i = 0, len = 1;
	char **argv = NULL;
	char *cmd_cpy = NULL, *token = NULL;

	if (input_cmd == NULL)
		return (NULL);
	cmd_cpy = strdup(input_cmd);
	token = strtok(cmd_cpy, DELIM);
	if (!token)
	{
		free(input_cmd);
		input_cmd = NULL;
		free(cmd_cpy);
		cmd_cpy = NULL;
		return (NULL);
	}
	while (token)
	{
		token = strtok(NULL, DELIM);
		len++;
	}
	free(cmd_cpy);
	cmd_cpy = NULL;
	argv = malloc(sizeof(char *) * (len));
	if (!argv)
	{
		free(input_cmd);
		return (NULL);
	}
	token = strtok(input_cmd, DELIM);
	while (token)
	{
		argv[i] = strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	argv[i] = NULL;
	free(input_cmd);
	input_cmd = NULL;
	return (argv);
}
