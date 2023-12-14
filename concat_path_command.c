#include "main.h"
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
		concated[l1] = '/';
		strcpy(concated + l1 + 1, command);
	}

	return (concated);
}
