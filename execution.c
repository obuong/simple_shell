#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

void echo_calling(char *echo_val) {
    int i, index = 0;
    environ_flag = 0;
    char new_args[1024], env_val[1000], *str[10];
    str[0] = _strtok(echo_val, " ");
    str[1] = _strtok(NULL, "");
    _strcpy(env_val, args[1]);
    if (str[1] == NULL) {
        printf("\n");
        return;
    }
    if (_strchr(str[1], '$')) {
        environ_flag = 1;
    }

    _memset(new_args, '\0', sizeof(new_args));
    i = 0;
    while (str[1][i] != '\0') {
        if (str[1][i] == '"') {
            index = 0;
            while (str[1][i] != '\0') {
                if (str[1][i] != '"') {
                    new_args[index] = str[1][i];
                    flag = 1;
                    index++;
                }
                i++;
            }
        } else if (str[1][i] == 39) {
            index = 0;
            while (str[1][i] != '\0') {
                if (str[1][i] != 39) {
                    new_args[index] = str[1][i];
                    flag = 1;
                    index++;
                }
                i++;
            }
        } else if (str[1][i] != '"') {
            new_args[index] = str[1][i];
            index++;
            i++;
        } else i++;
    }


    new_args[index] = '\0';
    if ((_strcmp(args[1], new_args) == 0) && (environ_flag == 0))
        printf("%s\n", new_args);
    else {
        _strcpy(args[1], new_args);
        if (environ_flag == 1) {
            environ_ment();
        } else if (environ_flag == 0) {
            printf("%s\n", new_args);
        }
    }
}

void history_execute_with_constants() {
    int num, i, start_index;
    if (bang_flag == 1) {
        for (i = 0; i < no_of_lines; i++)
            printf("%s\n", history_data[i]);
    } else if (args[1] == NULL) {
        for (i = 0; i < no_of_lines - 1; i++)
            printf("%s\n", history_data[i]);
        printf(" %d %s\n", no_of_lines, his_var);
    } else {
        if (args[1] != NULL)
            num = _atoi(args[1]);
        if (num > no_of_lines) {
            for (i = 0; i < no_of_lines - 1; i++)
                printf("%s\n", history_data[i]);
            printf(" %d %s\n", no_of_lines, his_var);
        }
        start_index = no_of_lines - num;
        for (i = start_index; i < no_of_lines - 1; i++)
            printf("%s\n", history_data[i]);
        printf(" %d %s\n", no_of_lines, his_var);
    }

}

