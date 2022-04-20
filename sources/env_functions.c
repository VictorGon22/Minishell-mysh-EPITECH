/*
** EPITECH PROJECT, 2022
** minishel1
** File description:
** main.c
*/

#include "./../includes/library.h"

void printenv_func(t_var *var, char *params)
{
    t_info_files *tmp = var->file->next;
    while (tmp != NULL) {
        my_putstr(tmp->name);
        my_putchar('=');
        my_putstr(tmp->info);
        my_putchar('\n');
        tmp = tmp->next;
    }
    free(tmp);
}

void external_setenv(t_var *var, char **param, int i)
{
    if (i == -1) {
        param[0] = my_strcat(param[0], "=");
        if (param[1] != NULL)
            param[0] = my_strcat(param[0], param[1]);
        create_new(var->file, param[0]);
    } else {
        if (param[1] == NULL)
            param[1] = "\0";
        change_value_linked(var, param[0], param[1]);
    }
}

void setenv_func(t_var *var, char *params)
{
    char **param = get_env_params(params);
    int i = -1;

    if (param[0] == NULL)
        printenv_func(var, params);
    else if (my_isalnum(param[0]) != 0) {
        if ((my_ischar(param[0][0]) && my_isdigit(param[0][0])) == 1)
            my_putstr("setenv: Variable name must begin with a letter.\n");
        else {
            my_putstr("setenv: Variable name must contain ");
            my_putstr("alphanumeric characters.\n");
        }
    } else {
        i = find_in_linked(var, param[0]);
        external_setenv(var, param, i);
    }
}

void unsetenv_func(t_var *var, char *params)
{
    char **param = get_env_params(params);

    if (param[0] != NULL) {
        if (find_in_linked(var, param[0]) == 1)
            supres_value_linked(var, param[0]);
    }
}
