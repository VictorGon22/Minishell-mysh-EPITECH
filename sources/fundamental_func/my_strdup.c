/*
** EPITECH PROJECT, 2022
** Fundamentalfunctions
** File description:
** mystrdup
*/

#include <unistd.h>
#include <stdlib.h>
#include "./../../includes/library.h"

char *my_strdup(char *str)
{
    char *result = malloc(sizeof(char) * my_strlen(str) + 1);
    int i = 0;

    while (str[i] != '\0') {
        result[i] = str[i];
        i++;
    }
    result[i] = '\0';
    return (result);
}
