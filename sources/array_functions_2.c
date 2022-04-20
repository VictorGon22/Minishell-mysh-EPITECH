/*
** EPITECH PROJECT, 2022
** minishel1
** File description:
** main.c
*/

#include "./../includes/library.h"

int quantity_words(char *str)
{
    int i = 1;
    int num_words = 1;

    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\0')
            num_words++;
        i++;
    } return (num_words);
}

char **str_word_array(char *type, char *str, char *delimitador)
{
    int num_words = quantity_words(str);
    char **final = malloc(sizeof(char *) * num_words + 2);
    char *word = strtok(str, delimitador);
    int i = 1;

    final[0] = type;
    if (word != NULL) {
        while (word != NULL) {
            final[i] = malloc(sizeof(char) * my_strlen(word));
            final[i] = word;
            word = strtok(NULL, delimitador);
            i++;
        }
    }
    final[i] = NULL;
    return (final);
}

int my_isalnum(char *string)
{
    int i = 0;

    while (string[i] != '\0') {
        if (my_isdigit(string[i]) != 0 && my_ischar(string[i]) != 0)
            return (1);
        i++;
    } return (0);
}