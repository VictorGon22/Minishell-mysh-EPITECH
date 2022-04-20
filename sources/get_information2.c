/*
** EPITECH PROJECT, 2021
** minishel1
** File description:
** main.c
*/

#include "./../includes/library.h"

char *get_params(char *str)
{
    char *comand = malloc(sizeof(char) * my_strlen(str));
    int i = 0;
    int n = 0;
    int word = 0;
    my_memset(comand, '\0', my_strlen(str));
    while (str[i] != '=' && str[i] != ' ' && str[i] != '\0')
        i++;
    if (str[i] == '\0')
        return (NULL);
    if (str[i] == '=')
        i++;
    while (str[i] != '\0') {
        comand[n] = str[i];
        n++;
        i++;
    }
    comand[n] = '\0';
    return (clean_string(comand));
}

char *get_command(char *str)
{
    char *comand = malloc(sizeof(char) * 100);
    int i = 0;
    int j = 0;
    my_memset(comand, '\0', 100);

    while (str[i] != '='  && str[i] != ' ' && str[i] != '\0') {
        comand[j++] = str[i];
        i++;
    } return (comand);
}

char **ext_get_env_params(char **comand)
{
    comand[0] = NULL;
    comand[1] = NULL;
    return (comand);
}

char **get_env_params(char *str)
{
    char **comand = malloc(sizeof(char *) * 3);
    int i = 0;
    int j = 0;
    int n = -1;

    if (str == NULL)
        return (ext_get_env_params(comand));
    while (str[i] != '\0') {
        if (str[i] == ' ' && n < 1 || i == 0) {
            n++;
            j = 0;
            comand[n] = malloc(sizeof(char) * my_strlen(str) + 1);
            my_memset(comand[n], '\0', my_strlen(str) + 1);
        }
        if (str[i] != ' ' || i == 0)
            comand[n][j++] = str[i];
        i++;
    }
    comand[n + 1] = NULL;
    return (comand);
}

char *get_info_linked(t_var *var, char *name)
{
    t_info_files *tmp = var->file->next;
    while (tmp != NULL) {
        if (my_strcmp(tmp->name, name) == 0) {
            return (tmp->info);
        }
        tmp = tmp->next;
    }
    return (NULL);
}


