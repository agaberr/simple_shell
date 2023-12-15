#include "main.h"

/**
* built_in_functions - excute built in functions
* @args: arguments passed
* @cmd: command passed
* @status: status
*
* Return: 1 if excuted, 0 otherwise
*/

int built_in_functions(char **args, char *cmd, int status)
{
	int i;

	if (strcmp(cmd, "exit") == false)
	{
		free_2D_arr(args);
		exit(status);
	}
	else if (strcmp(cmd, "env") == false)
	{
		for (i = 0; environ[i]; i++)
		{
			write(STDOUT_FILENO, environ[i], strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);

		}
		free_2D_arr(args);
		return (true);
	}
	else if (strcmp(cmd, "cd") == false)
	{
		change_dir(args);
		return (true);
	}
	else if (strcmp(cmd, "setenv") == false || strcmp(cmd, "unsetenv") == false)
	{
		set_unset_env(args);
		return (true);
	}
	return (false);
}

/**
 * set_unset_env - handle setenv & unsetenv
 * @args: args provided
 *
 * Return: None
*/

void set_unset_env(char **args)
{
	(void) args;
}

/**
 * change_dir - change directory
 * @args: args provided
 *
 * Return: None
*/

void change_dir(char **args)
{
	char cd[100];

	if (!args[1]) /*no destination provided*/
	{
		if (chdir(getenv("HOME")) == fail) /*error*/
		{
			perror("hsh");
			return;
		}
	}

	else if (strcmp(args[1], "-") == false) /*old directory*/
	{
		if (chdir(getenv("OLDPWD")) == fail) /*error*/
		{
			perror("hsh");
			return;
		}
	}

	else /*change directory*/
	{
		if (chdir(args[1]) == fail) /*error*/
		{
			perror("hsh");
			return;
		}
	}

	/*change PWD*/
	getcwd(cd, sizeof(cd));
	setenv("OLDPWD", getenv("PWD"), 1);
	setenv("PWD", cd, 1);
}
