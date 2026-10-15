/*
** EPITECH PROJECT, 2022
** basic_ls
** File description:
** my_ls
*/
#include "my.h"
#include <time.h>

char **compare_time(char **tab, int nb)
{
    int i = 0;
    int j = 0;
    char **temp = tab;
    char *temp_time;
    struct stat total;

    while (i < nb - 1) {
        stat(tab[i], &total);
        temp_time = ctime(&total.st_mtime);
        stat(tab[i + 1], &total);
        if (temp_time[j] == ctime(&total.st_mtime)[j]) {
            j += 1;
        }
        if (temp_time[j] < ctime(&total.st_mtime)[j]) {
            my_swap(&temp[i], &temp[i + 1]);
            i = 0;
        }
        i = i + 1;
    }
    return temp;
}

int flag_t(void)
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
    tab = compare_time(tab,nb);
    my_put_tab(tab);
    free(tab);
    closedir(dir);
    return 0;
}
