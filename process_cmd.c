#include <stdlib.h>
#include "main.h"

char *skip_quotes(char *str) {
    int i = 0, j = 0;
    char temp[1000];
    while (str[i++] != '\0') {
        if (str[i - 1] != '"')
            temp[j++] = str[i - 1];
    }
    temp[j] = '\0';
    str = _strdup(temp);

    return str;
}

/**
 * is_space - checks if a character is a whitespace.
 * @c: the character to check.
 * Return: 1 if character is a whitespace, 0 otherwise.
 */
int is_space(int c) {
    return (c == '\t' || c == '\n' ||
            c == '\v' || c == '\f' || c == '\r' || c == ' ' ? 1 : 0);
}

char *skip_whitespaces(char *s) {
    while (is_space(*s)) ++s;
    return s;
}

int split(char *cmdExec, int input, int first, int last) {
    char *new_cmd_exec1;
    new_cmd_exec1 = _strdup(cmdExec);
    {
        int m = 1;
        args[0] = _strtok(cmdExec, " ");
        while ((args[m] = _strtok(NULL, " ")) != NULL)
            m++;
        args[m] = NULL;
        if (args[0] != NULL) {

            if (_strcmp(args[0], "exit") == 0)
                ex_it(0);
            if (_strcmp(args[0], "echo") != 0) {
                cmdExec = skip_quotes(new_cmd_exec1);
                int n = 1;
                args[0] = _strtok(cmdExec, " ");
                while ((args[n] = _strtok(NULL, " ")) != NULL)
                    n++;
                args[n] = NULL;

            }
            if (_strcmp("cd", args[0]) == 0) {
                change_directory();
                return 1;
            } else if (_strcmp("pwd", args[0]) == 0) {
                parent_directory();
                return 1;
            }

        }
    }
    return command(input, first, last, new_cmd_exec1);
