/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** functionstrcat
*/

#include "./../../includes/library.h"

char *my_strcat(char *dest, char *src)
{
    char *temp = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src))
    + 1);
    int i = 0;
    int n = 0;

    while (dest[i] != '\0') {
        temp[i] = dest[i];
        i++;
    }
    while (src[n] != '\0') {
        temp[i] = src[n];
        i++;
        n++;
    }
    temp[i] = '\0';
    return (temp);
}
