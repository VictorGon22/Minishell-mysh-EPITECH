/*
** EPITECH PROJECT, 2021
** minishel1
** File description:
** main.c
*/

#include "./../includes/library.h"

char *clean_last_space(char *string)
{
    int i = my_strlen(string) - 1;
    if (string[i] == ' ' || string[i] == '\t') {
        while (string[i] == ' ' || string[i] == '\t')
            i--;
        string[i + 1] = '\0';
    }
    string[i + 1] = '\0';
    return (string);
}

char *clean_string(char *string)
{
    int i = 0;
    int j = 0;
    int words = 0;
    char *final = malloc(sizeof(char) * my_strlen(string) + 1);
    my_memset(final, '\0', my_strlen(string));

    while (string[i] != '\0') {
        if (string[i] != ' ' && string[i] != '\t')
            final[j++] = string[i];
        if ((string[i] != ' ' && string[i] != '\t') &&
        (string[i + 1] == ' ' || string[i + 1] == '\t')) {
            if (words <= 1)
                final[j++] = ' ';
        }
        i++;
    }
    final[j] = '\0';
    return (clean_last_space(final));
}

int get_line_function(t_var *var)
{
    int bytes_read;
    size_t size = 18;
    char *string = NULL;
    char *command = NULL;
    char *params = NULL;

    if (isatty(0) != 0)
        my_putstr("$> ");
    string = (char *) malloc (size);
    bytes_read = getline(&string, &size, stdin);
    if (bytes_read < 0)
        exit_func(var, command);
    string[my_strlen(string) - 1] = '\0';
    ext_get_line_function(var, clean_string(string), bytes_read);
    return (0);
}

void ext_get_line_function(t_var *var, char *string, int bytes_read)
{
    int i = 0;
    var->list_exec = save_word(string);

    if (bytes_read == -1)
        exit(84);
    else {
        while (var->list_exec[i] != NULL) {
            var->list_exec[i] = strdup(clean_string(var->list_exec[i]));
            func_pointer(var, get_params(var->list_exec[i]), get_command(var->list_exec[i]));
            i++;
        }
    }
}

char *get_path(t_var *var)
{
    t_info_files *tmp = var->file->next;

    while (tmp->next != NULL) {
        if (my_strcmp(tmp->name, "PATH") == 0)
            return (tmp->env);
        tmp = tmp->next;
    } return (NULL);
}
