/*
** EPITECH PROJECT, 2022
** Fundamentalfunctions
** File description:
** functionmy_strlen
*/

#include "./../../includes/library.h"

int my_strlen(char const *str)
{
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }
    return (length);
}
