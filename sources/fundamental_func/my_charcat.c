/*
** EPITECH PROJECT, 2022
** Fundamentalfunctions
** File description:
** my_charcat
*/

#include "./../../includes/library.h"

char *my_charcat(char *dest, char src)
{
    int i = 0;
    int n = 0;

    while (dest[i] != '\0') {
        i++;
    }
    dest[i] = src;
    dest[i + 1] = '\0';
    return (dest);
}
