#include "main.h"
/**
* find_path - finds path of the user and
* return it concated with the command
*
* @input_cmd: command input by user
*
* Return: path/command
*/

char *find_path(char *input_cmd)
{
	char *token;
	char *FULL_PATH, *PATH;
	struct stat status;
	int i;

	/*remove it from here*/
	for (i = 0; input_cmd[i]; i++)
	{
		if (input_cmd[i] == '/')
		{
			if (stat(input_cmd, &status) == 0)
			{
				return (strdup(input_cmd));
			}
			return (NULL);
		}
	}
	PATH = getenv("PATH");

	if (!PATH)
		return (NULL);
	token = strtok(PATH, DELIM);
	while (token)
	{
		FULL_PATH = concat_path_command(PATH, input_cmd);

		if (access(FULL_PATH, F_OK | X_OK) == 0)
		{
			/*free(PATH);*/
			return (FULL_PATH);
		}
		free(FULL_PATH);
		FULL_PATH = NULL;
		token = strtok(NULL, DELIM);
	}
	return (NULL);
}

/**
* concat_path_command - cancat path with command (path/command)
* @PATH: path
* @command: command input by user
*
* Return: path/command
*/

char *concat_path_command(char *PATH, char *command)
{
	size_t l1 = strlen(PATH), l2 = strlen(command);

	char *concated = malloc(l1 + l2 + 2);

	if (concated)
	{
		strcpy(concated, PATH);
		strcat(concated, "/");
		strcat(concated, command);
	}

	return (concated);
}
