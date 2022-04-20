/*
** EPITECH PROJECT, 2022
** Fundamentalfunctions
** File description:
** returnchar
*/

char *my_strcpy(char *destination, char *source)
{
    char *copy = destination;

    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
    return (copy);
}
