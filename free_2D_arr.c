#include "main.h"

/**
* free_2D_arr - free array of strings
* @args: array of strings
*
* Return: None
*/

void free_2D_arr(char **args)
{
	int i = 0;

	if (args == NULL)
		return;

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}

	free(args);
}
