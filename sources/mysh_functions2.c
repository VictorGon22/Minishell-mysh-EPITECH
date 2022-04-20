/*
** EPITECH PROJECT, 2022
** minishel1
** File description:
** main.c
*/

#include "./../includes/library.h"

char *pwd_func(void)
{
    char cwd[PATH_MAX];

    if (getcwd(cwd, sizeof(cwd)) != NULL)
        return (my_strdup(cwd));
    else
        return ("-1");
}

void my_pwdfunc(t_var *var, char *params)
{
    char *cwd = pwd_func();
    if (my_strcmp(cwd, "-1") != 0) {
        my_putstr(cwd);
        my_putstr("\n");
    } else
        my_putstr("ERROR\n");
}

void pwdfunc(t_var *var, char *params)
{
    char *env = get_path(var);
    char **path = paths(env);
    pid_t pid = fork();
    char **params1 = malloc(sizeof(char *));

    params1[0] = "./pwd";
    params1[1] = params;
    params1[2] = NULL;
    if (pid == -1) {
        return;
    } else if (pid == 0) {
        if (execve(find_func(path, "pwd"), params1 , NULL) < 0)
            my_putstr("\nCould not execute command..\n");
        exit(0);
    } else {
        wait(NULL);
        return;
    }
}

void exit_func(t_var *var, char *params)
{
    exit(0);
}
