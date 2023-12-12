#include "main.h"



char ** tokenize(char *input)
{

    char *cmd_cpy = NULL, *token = NULL;

	int argc = 0, i = 0;

	char **argv = NULL;

	cmd_cpy = strdup(input);

	token = strtok(input, DELIM);

	while (token)
	{
		token = strtok(NULL, DELIM);
		argc++;
	}

	argv = malloc(sizeof(char *) * argc);
	token = strtok(cmd_cpy, DELIM);

	while (token)
	{
		argv[i] = token;
		token = strtok(NULL, DELIM);
		i++;
	}
	argv[i] = NULL;

	return (argv);
}

