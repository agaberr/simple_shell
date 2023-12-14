#include "main.h"
/**
* GET_VALID_PATH - return the path concated with cmd
* @TOKEN_PATH: string of all paths
* @command: command input by user
*
* Return: path concated with cmd, NULL otherwise
*/

char *GET_VALID_PATH(char **TOKEN_PATH, char *command)
{
	int i = 0;
	int l_size;

	char *FULL_PATH = NULL;

	for (i = 0; TOKEN_PATH[i]; i++)
	{
		FULL_PATH = concat_path_command(TOKEN_PATH[i], command);
		if (access(FULL_PATH, F_OK | X_OK) == 0)
			return (FULL_PATH);
		free(FULL_PATH);
	}

	return (NULL);

}
