#include "main.h"

/**
* main - Entry point
* @argc: number of arguments
* @argv: arguments passsed
*
* Return: Always 0 (success)
*/

int main(void) {
    char *input = NULL;
    size_t input_size = 0;
    pid_t child_pid;
    int status;
    int len = 0;

    while (true) {

        // read line from user
        if (read_line(&input, &input_size) == 0)
            // handle CTRL + D
            break;

        // Remove newline character from input
        len = strcspn(input, "\n");
        input[len] = '\0';

        status = exec_cmd(input);
    }

    // Free allocated memory
    free(input);

    return 0;
}
