/*
** EPITECH PROJECT, 2022
** Fundamentalfunctions
** File description:
** my_charcat
*/

#include "./../../includes/library.h"

int my_isdigit(char c)
{
    if (c >= '0' && c <= '9')
        return (0);
    return (1);
}

int my_ischar(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (0);
    return (1);
}