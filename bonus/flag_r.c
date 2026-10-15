/*
** EPITECH PROJECT, 2022
** basic_ls
** File description:
** my_ls
*/
#include "my.h"

char **reverse_order(char **tab, int nb)
{
    int i = 0;
    int j = 0;
    char **temp = tab;
    while (i < nb - 1) {
        while (tab[i][j] == tab[i + 1][j]) {
            j += 1;
        }
        if (tab[i][j] < tab[i + 1][j]) {
            my_swap(&temp[i], &temp[i + 1]);
            i = 0;
        }
        if (temp[i][j] < temp[i + 1][j]) {
            i -= 1;
        }
        j = 0;
        i = i + 1;
    }
    return temp;
}

int flag_r(void)
{
    DIR *dir = opendir("./");
    struct dirent *read;
    int i = 0;
    int nb = get_nbdir(opendir("./"));
    char **tab = malloc(sizeof(char*) * (nb + 1));
    while ((read = readdir(dir)) != 0) {
        if (read->d_name[0] != '.') {
            tab[i] = read->d_name;
            i += 1;
        }
    }
    tab[nb] = 0;
    tab = reverse_order(tab,nb);
    my_put_tab(tab);
    free(tab);
    closedir(dir);
    return 0;
}
