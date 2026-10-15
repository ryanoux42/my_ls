/*
** EPITECH PROJECT, 2022
** basic_ls
** File description:
** my_ls
*/
#include "my.h"

int get_nbdir(DIR *dir)
{
    struct dirent *read;
    int nb = 0;
    while ((read = readdir(dir)) != 0) {
        if (read->d_name[0] != '.') {
            nb += 1;
        }
    }
    closedir(dir);
    return nb;
}

int basic_ls(void)
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
    tab = bring_order(tab,nb);
    my_put_tab(tab);
    free(tab);
    closedir(dir);
    return 0;
}
