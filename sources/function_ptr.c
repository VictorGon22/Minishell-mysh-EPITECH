/*
** EPITECH PROJECT, 2021
** minishel1
** File description:
** main.c
*/

#include "./../includes/library.h"

void type_comands(calculator *flags)
{
    flags[0].op = "my_pwd";
    flags[0].ptr = &my_pwdfunc;
    flags[1].op = "cd";
    flags[1].ptr = &cd_func;
    flags[2].op = "env";
    flags[2].ptr = &printenv_func;
    flags[3].op = "pwd";
    flags[3].ptr = &my_pwdfunc;
    flags[4].op = "setenv";
    flags[4].ptr = &setenv_func;
    flags[5].op = "unsetenv";
    flags[5].ptr = &unsetenv_func;
    flags[6].op = "exit";
    flags[6].ptr = &exit_func;
}

int func_pointer(t_var *var, char *params, char *type)
{
    int i = 0;
    int find = 0;
    var->counter_op++;
    calculator flags[7];
    type_comands(flags);
    while (i < 7) {
        if (my_strcmp(type, flags[i].op) == 0) {
            (*(flags[i].ptr))(var, params);
            find = 1;
        }
        i++;
    }
    if (find == 0)
        try_execute(var, params, type);
}
