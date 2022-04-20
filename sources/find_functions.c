/*
** EPITECH PROJECT, 2022
** minishel1
** File description:
** main.c
*/

#include "./../includes/library.h"

int find_in_linked(t_var *var, char *name)
{
    t_info_files *tmp = var->file->next;
    int find = -1;
    while (tmp != NULL) {
        if (my_strcmp(tmp->name, name) == 0)
            find = 1;
        tmp = tmp->next;
    } return (find);
}

int find_str_array(t_var *var, char *to_find)
{
    int i = 0;
    int instr = 0;

    while (var->envp[i] != NULL) {
        if (find_in_str(var->envp[i], to_find) == 0)
            return (i);
        i++;
    } return (-1);
}

int find_in_str(char *str, char *to_find)
{
    int i = 0;
    int n = 0;

    while (str[n] == to_find[n] && to_find[n] != '\0')
        n++;
    if (n == my_strlen(to_find))
        return (0);
    return (-1);
}

char *find_func(char **paths, char *function)
{
    char *temp = NULL;
    int i = 0;
    int fd = -1;

    while (paths[i] != NULL) {
        temp = malloc(sizeof(char) * (my_strlen(paths[i])
        + my_strlen(function)) + 2);
        my_memset(temp, '\0', (my_strlen(paths[i]) + my_strlen(function)) + 2);
        temp = my_strcat(paths[i], "/");
        temp = my_strcat(temp, function);
        fd = access(temp, F_OK);
        if (fd != -1)
            return (temp);
        i++;
    } return ("-1");
}
