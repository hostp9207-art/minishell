#include <string.h>
#include "parser.h"

int parse_input(char *input, char *argv[])
{
    int argc = 0;

    char *token = strtok(input, " \t\n");

    while (token != NULL && argc < MAX_ARGS - 1)
    {
        argv[argc] = token;
        argc++;

        token = strtok(NULL, " \t\n");
    }

    argv[argc] = NULL;

    return argc;
}