#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "shell.h"
#include "parser.h"
#include "builtins.h"

static void execute_command(char *argv[])
{
    pid_t pid;
    int status;

    pid = fork();

    /*
     * fork failed
     */
    if (pid < 0)
    {
        perror("fork");
        return;
    }

    /*
     * Child process
     */
    if (pid == 0)
    {
        execvp(argv[0], argv);

        /*
         * Haddii execvp uu soo noqdo,
         * command-ku wuu fashilmay.
         */
        perror("minishell");

        exit(EXIT_FAILURE);
    }

    /*
     * Parent process
     */
    waitpid(pid, &status, 0);
}

void shell_loop(void)
{
    char input[MAX_INPUT];
    char *argv[MAX_ARGS];

    while (1)
    {
        /*
         * Prompt
         */
        printf("minishell$ ");
        fflush(stdout);

        /*
         * Read input
         */
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("\n");
            break;
        }

        /*
         * Empty command
         */
        if (input[0] == '\n')
        {
            continue;
        }

        /*
         * Parse input
         */
        int argc = parse_input(input, argv);

        if (argc == 0)
        {
            continue;
        }

        /*
         * Builtins
         */
        if (handle_builtin(argv))
        {
            continue;
        }

        /*
         * External command
         */
        execute_command(argv);
    }
}