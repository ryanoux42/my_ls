/*
** EPITECH PROJECT, 2022
** my_swap
** File description:
** task01
*/
#include "my.h"

void my_swap(char **a, char **b)
{
    char *c;
    c = *a;
    *a = *b;
    *b = c;
}

char **bring_order(char **tab, int nb)
{
    int i = 0;
    int j = 0;
    char **temp = tab;
    while (i < nb - 1) {
        while (tab[i][j] == tab[i + 1][j]) {
            j += 1;
        }
        if (tab[i][j] > tab[i + 1][j]) {
            my_swap(&temp[i], &temp[i + 1]);
            i = 0;
        }
        if (temp[i][j] > temp[i + 1][j]) {
            i -= 1;
        }
        j = 0;
        i = i + 1;
    }
    return temp;
}

int my_put_tab(char **tab)
{
    for (int i = 0; tab[i] != 0; i++) {
        mini_printf("%s\n", tab[i]);
    }
    return (0);
}
