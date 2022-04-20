/*
** EPITECH PROJECT, 2022
** minishel1
** File description:
** main.c
*/

#include "./../includes/library.h"

void change_value_linked(t_var *var, char *name, char *value)
{
    t_info_files *tmp = var->file->next;

    while (tmp != NULL) {
        if (my_strcmp(tmp->name, name) == 0) {
            tmp->info = my_strdup(value);
            name = my_strcat(name, "=");
            tmp->env = my_strcat(name, value);
        }
        tmp = tmp->next;
    }
}

void supres_value_linked(t_var *var, char *name)
{
    t_info_files *tmp = var->file->next;
    int finded = 0;

    while (tmp != NULL && finded == 0) {
        if (my_strcmp(tmp->next->name, name) == 0) {
            tmp->next = tmp->next->next;
            finded = 1;
        }
        tmp = tmp->next;
    }
}

char *supres_dot_path(char *string)
{
    int i = 0;
    int j = 0;

    while (string[i] != '\0') {
        if (string[i] != '.' && string[i] != '/') {
            string[j] = string[i];
            j++;
        }
        i++;
    }
    string[j] = '\0';
    return (string);
}

char *supres_char(char *string, char sup_char)
{
    int i = 0;
    int j = 0;

    while (string[i] != '\0') {
        if (string[i] != sup_char && string[i] != sup_char) {
            string[j] = string[i];
            j++;
        }
        i++;
    }
    string[j] = '\0';
    return (string);
}

char *supres_notalphanum(char *string)
{
    int i = 0;
    int j = 0;

    while (string[i] != '\0') {
        if (isalnum(string[i]) != 0) {
            string[j] = string[i];
            j++;
        }
        i++;
    }
    string[j] = '\0';
    return (string);
}
