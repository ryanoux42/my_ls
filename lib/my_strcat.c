/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** task02
*/
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int len = 0;
    char *str;

    str = malloc(sizeof(*str) * (my_strlen(dest) + my_strlen(src) + 1));
    while (dest[i] != '\0') {
        str[i] = dest[i];
        i++;
    }
    while (src[len] != '\0') {
        str[len + i] = src[len];
        len++;
    }
    str[len + i] = '\0';
    return str;
}
