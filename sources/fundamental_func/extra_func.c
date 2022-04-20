/*
** EPITECH PROJECT, 2022
** Fundamentalfunctions
** File description:
** Extra_functions
*/

#include "./../../includes/library.h"

void revstr(char *str1)
{
    int i = 0;
    int len = my_strlen(str1);
    int temp = 0;

    for (i = 0; i < len / 2; i++) {
        temp = str1[i];
        str1[i] = str1[len - i - 1];
        str1[len - i - 1] = temp;
    }
}

void my_putchar(char letter)
{
    write(1, &letter, 1);
}

void my_putstr(char const *str)
{
    int len = 0;

    if (str) {
        len = my_strlen(str);
        if (len > 0)
            write(1, str, len);
    }
}
