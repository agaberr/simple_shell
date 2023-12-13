#include "main.h"

/**
* _strdup - duplicate string
* @s: string to duplicate
*
* Return: duplicated string, NULL if error
*/

char *_strdup(char *s)
{
	char *str_dup;
	int i, l;

	if (s == NULL)
		return (NULL);

	l = strlen(s);

	str_dup = malloc(sizeof(char) * (l + 1));

	if (str_dup == NULL)
		return (NULL);

	for (i = 0; *s; i++, s++)
	{
		str_dup[i] = s[0];
	}
	i++;

	str_dup[i] = '\0';

	return (str_dup);
}
