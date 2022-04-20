/*
** EPITECH PROJECT, 2021
** minishel1
** File description:
** main.c
*/

#include "./../includes/library.h"

t_info_files *ini_linked_envp(char *envp)
{
    t_info_files *file = malloc(sizeof(t_info_files) * 1);

    if (file == NULL)
        perror("error\n");
    file->name = get_command(envp);
    file->info = my_strdup(get_params(envp));
    file->env = my_strdup(envp);
    file->next = NULL;
    return file;
}

void create_new(t_info_files *file, char *envp)
{
    t_info_files *tmp = file;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = ini_linked_envp(envp);
}

void save_envplinked(t_info_files *file, char **envp)
{
    int i = 0;

    while (envp[i] != NULL) {
        create_new(file, envp[i]);
        i++;
    }
}

void change_oldpwd(t_var *var)
{
    int no_oldpwd = 0;
    t_info_files *tmp = var->file->next;

    while (tmp != NULL) {
        if (my_strcmp(tmp->name, "OLDPWD") == 0) {
            tmp->info = var->old_pwd;
            tmp->env = my_strcat(tmp->name, tmp->info);
            no_oldpwd = 1;
        }
        tmp = tmp->next;
    }
    if (no_oldpwd == 0)
        create_new(var->file, "OLDPWD=");
}

void change_pwdenv(t_var *var)
{
    t_info_files *tmp = var->file->next;
    while (tmp != NULL) {
        if (my_strcmp(tmp->name, "PWD") == 0) {
            tmp->info = pwd_func();
            tmp->env = my_strcat(tmp->name, tmp->info);
            var->old_pwd = my_strdup(tmp->info);
        }
        tmp = tmp->next;
    }
}
