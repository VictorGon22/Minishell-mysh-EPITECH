/*
** EPITECH PROJECT, 2021
** my revstr
** File description:
** funcrevstr
*/

#include "./../../includes/library.h"

char *my_revstr(char *str)
{
    int i = 0;
    int n = my_strlen(str);
    char *temp = malloc(sizeof(char) * n + 1);

    while (str[i] != '\0') {
        temp[n] = str[i];
        i++;
        n--;
    }
    while (n != i) {
        str[n] = temp[n];
        n++;
    }
    str[n] = '\0';
    return (str);
}
