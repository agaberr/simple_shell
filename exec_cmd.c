#include "main.h"


int exec_cmd(char *input)
{

	pid_t pid;
	int status;

    // Fork a child process
    char ** args = tokenize(input);
    
    pid = fork();
    if (pid == -1) {
        perror("error in fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) // child
    {

        // tokenize args

        if (execve(args[0], args, NULL) == fail)
        {
            perror(args[0]);
            exit(EXIT_FAILURE);
        }
    }
    else // parent
    {

        // Wait for the child to complete
        waitpid(pid, &status, 0);

        // Free memory allocated for arguments

        // for (int i = 0; args[i] != NULL; i++) {
        //     free(args[i]);
        // }
        // free(args);

        return (WEXITSTATUS(status));

    }
}

