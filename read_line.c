#include "main.h"

int read_line(char **input, size_t *input_size)
{
    if (isatty(STDIN_FILENO))
        printf("$ ");

    // Allocate memory for input
    *input_size = 0;
    *input = NULL;

    if (getline(input, input_size, stdin) == -1)
    {
        printf("\n");
        return (false);
    }
    return (true);
}