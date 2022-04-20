/*
** EPITECH PROJECT, 2022
** Fundamental functions
** File description:
** my_nbrlen
*/

#include "./../../includes/library.h"

int my_nbrlen(int nb)
{
    int len = 0;

    if (nb == 0)
        return (1);
    while (nb > 0) {
        nb /= 10;
        len++;
    }
    return (len);
}
