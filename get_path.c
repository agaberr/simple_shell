#include "main.h"
/**
* get_path - get the path in enviroment
*
* Return: Path,  NULL otherwise
*/

char *get_path(void)
{

	char *PATH = getenv("PATH");

	return (PATH);

}
