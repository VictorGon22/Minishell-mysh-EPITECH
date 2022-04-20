/*
** EPITECH PROJECT, 2022
** minishel1
** File description:
** main.c
*/

#include "./../includes/library.h"

char *ext_cd_goback(t_var *var, char *path, char *current_folder)
{
    int i =  my_strlen(current_folder);

    if (my_strcmp("..", path) == 0) {
        if (i == 1)
            current_folder[0] = '\0';
        while (current_folder[i - 1] != '/')
            i--;
        current_folder[i] = '\0';
    } else if (my_strcmp("-", path) == 0) {
        current_folder = get_info_linked(var, "OLDPWD");
        my_putstr(current_folder);
        my_putchar('\n');
    } return (current_folder);
}

char *ext_cd_func(t_var *var, char * path, char *current_folder)
{
    if (my_strcmp("..", path) == 0 || my_strcmp("-", path) == 0)
        current_folder = ext_cd_goback(var, path, current_folder);
    else {
        if (path[0] == '/')
            current_folder = my_strdup(path);
        else {
            current_folder = my_strcat(current_folder, "/");
            current_folder = my_strcat(current_folder, path);
        }
    } return (current_folder);
}

char *ext_cd_null(t_var *var, char *current_folder)
{
    int i = 0;
    int j = 0;
    while (j <= 2) {
        if (current_folder[i] == '/' || current_folder[i] == '\0')
            j++;
        i++;
    }
    current_folder[i] = '\0';
    return (current_folder);
}

void access_cd(t_var *var, char *current_folder, char *prova)
{
    if (chdir(current_folder) == -1) {
        my_putstr(my_strdup(prova));
        if (access(current_folder, R_OK) == 0)
            my_putstr(": Not a directory.\n");
        else
            my_putstr(": No such file or directory.\n");
    } else {
        change_oldpwd(var);
        change_pwdenv(var);
    }
}

void cd_func(t_var *var, char *path)
{
    int i = 0;
    char *current_folder = pwd_func();

    if (path == NULL)
        current_folder = ext_cd_null(var, current_folder);
    else
        current_folder = ext_cd_func(var, path, current_folder);
    access_cd(var, current_folder, path);
}
