#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "builtins.h"

int handle_builtin(char *argv[])
{
    if (argv[0] == NULL)
    {
        return 1;
    }

    /*
     * exit
     */
    if (strcmp(argv[0], "exit") == 0)
    {
        exit(0);
    }

    /*
     * cd
     */
    if (strcmp(argv[0], "cd") == 0)
    {
        if (argv[1] == NULL)
        {
            fprintf(stderr, "cd: missing argument\n");
            return 1;
        }

        if (chdir(argv[1]) != 0)
        {
            perror("cd");
        }

        return 1;
    }

    /*
     * pwd
     */
    if (strcmp(argv[0], "pwd") == 0)
    {
        char cwd[1024];

        if (getcwd(cwd, sizeof(cwd)) != NULL)
        {
            printf("%s\n", cwd);
        }
        else
        {
            perror("pwd");
        }

        return 1;
    }

    /*
     * help
     */
    if (strcmp(argv[0], "help") == 0)
    {
        printf("\n");
        printf("MiniShell commands:\n");
        printf("  cd <directory>  Change directory\n");
        printf("  pwd             Show current directory\n");
        printf("  help            Show this help\n");
        printf("  exit            Exit shell\n");
        printf("\n");
        printf("External commands:\n");
        printf("  ls\n");
        printf("  cat\n");
        printf("  echo\n");
        printf("  mkdir\n");
        printf("  gcc\n");
        printf("  etc...\n");
        printf("\n");

        return 1;
    }

    /* add a comment*/

    /*
     * Not a builtin
     */
    return 0;
}