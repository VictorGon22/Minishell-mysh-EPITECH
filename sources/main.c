/*
** EPITECH PROJECT, 2021
** minishel1
** File description:
** main.c
*/

#include "./../includes/library.h"

char **save_exec_params(t_var *var, char *params, char *type)
{
    char **params1 = malloc(sizeof(char *) * 4);

    if (params != NULL)
        params1 = str_word_array(type, params, " ");
    else {
        params1[0] = my_strdup(type);
        params1[1] = NULL;
    }
    return (params1);
}

char **paths(char *str)
{
    char **result = malloc(sizeof(char *) * 1000);
    int i = 5;
    int n = 0;
    int j = 0;
    while (str[i] != '\0') {
        result[n] = malloc(sizeof(char) * my_strlen(str));
        j = 0;
        my_memset(result[n], '\0', my_strlen(str));
        while (str[i] != ':' && str[i] != '\0') {
            result[n][j++] = str[i++];
        }
        i++;
        n++;
    }
    result[n] = NULL;
    return (result);
}

void print_arg(char ** arg)
{
    int i = 0;

    while (arg[i] != NULL) {
        my_putstr(arg[i]);
        i++;
    }
}

t_info_files *init_file(void)
{
    t_info_files *res = malloc(sizeof(t_info_files));
    res->name = NULL;
    res->info = NULL;
    res->env = NULL;
    res->next = NULL;
    return res;
}

int valid_chars(char n)
{
    if (n == '\0' || n == '\n' || n == '|' 
    || n == '<')
        return 1;
    return 0;
}

int quantity_sentences(int size_text, char *str)
{
    int i = 1;
    int num_sentences = 1;

    while (i < size_text) {
        if (valid_chars(str[i]))
            num_sentences++;
        i++;
    } return (num_sentences);
}

int len_sentence(char *arraytext)
{
    int i = 0;
    while (!valid_chars(arraytext[i]))
        i++;
    return (i);
}

char **save_word(char *arraytext)
{
    int len = 0;
    int i = 0;
    int k = 0;
    int j = 0;
    char **sentences;

    sentences = calloc(quantity_sentences(strlen(arraytext), arraytext) * 2, sizeof(char *));
    while (i < strlen(arraytext)) {
        len = len_sentence(arraytext);
        sentences[j] = calloc(len * 2 + 10, sizeof(char));
        k = 0;
        while (!valid_chars(arraytext[i]))
            sentences[j][k++] = arraytext[i++];
        j++;
        i++;
    }
    sentences[j] = NULL;
    return (sentences);
}

void save_list_exec(t_var *var, char* string)
{
    var->list_exec = save_word(string);

}

int main(int argc, char **argv, char **envp)
{
    t_var var;
    var.argv = argv;
    var.argc = argc;
    var.envp = envp;
    var.old_pwd = pwd_func();
    char *prova;
    var.counter_op = 0;
    t_info_files *file = init_file();
    var.file = file;
    //save_list_exec(&var);
    save_envplinked(file, envp);
    change_oldpwd(&var);
    change_pwdenv(&var);
    while (1) {
        get_line_function(&var);
    } return (0);
}
