#include "main.h"

/**
* tokenizer - split string into array of words
* @input_cmd: input string command from user
*
* Return: array of strings splitted by " "
*/

char **tokenizer(char *input_cmd)
{size_t tokens = 1, token_start = 0, token_len, i;
char *ptr = input_cmd;
char **args;
while (*ptr)
{
	while (*ptr && strchr(DELIM, *ptr))
	ptr++;
	if (*ptr)
	tokens++;
	while (*ptr && !strchr(DELIM, *ptr))
	ptr++;
}
args = malloc(sizeof(char *) * (tokens + 1));
if (!args)
	return (NULL);
ptr = input_cmd;
for (i = 0; i < tokens - 1; i++)
{
	while (*ptr && strchr(DELIM, *ptr))
	{
	ptr++;
	token_start++;
	}
	token_len = 0;
	while (*ptr && !strchr(DELIM, *ptr))
	{
	ptr++;
	token_len++;
	}
	args[i] = malloc(token_len + 1);
	if (!args[i])
	{
	free_2D_arr(args);
	return (NULL);
	}
	strncpy(args[i], input_cmd + token_start, token_len);
	args[i][token_len] = '\0';
	token_start += token_len;
}
args[tokens] = NULL;
return (args);
}
