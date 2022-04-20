/*
** EPITECH PROJECT, 2022
** Fundamentalfunctions
** File description:
** my_charcat
*/

#include "./../../includes/library.h"

void *my_memset(void *s, int c, int n)
{
    char *tmp = NULL;
    int	i = 0;

    tmp = s;
    i = 0;
    while (i < n)
        tmp[i++] = c;
    return (tmp);
}

void *my_calloc(int nmemb, int size)
{
    void *ptr = NULL;

    if (!(ptr = malloc(nmemb * size)))
        return (NULL);
    ptr = my_memset(ptr, 0, nmemb * size);
    return (ptr);
}
