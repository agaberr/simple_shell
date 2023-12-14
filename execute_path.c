#include "main.h"
/**
* execute_path - execute command using path
* @args: command user input
* @program_name: current program name
*
*  Return: 1 if excuted, 0 otherwise
*/

int execute_path(char **args, char *program_name)
{
	char *PATH = NULL;

	char **TOKEN_PATH = NULL;

	char *full_path = NULL;

	PATH = get_path();
	TOKEN_PATH = tokenizer(PATH);


	full_path = GET_VALID_PATH(TOKEN_PATH, args[0]);

	if (full_path != NULL)
	{
		execute_cmd_fork(full_path, args);
		return (true);
	}
	perror(program_name);
	return (false);
}
