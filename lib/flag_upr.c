/*
** EPITECH PROJECT, 2022
** flag_upr
** File description:
** my_ls
*/
#include "my.h"

int good_dir(struct stat total)
{
    switch (total.st_mode & S_IFMT) {
    case S_IFBLK: return 0;
    case S_IFCHR: return 0;
    case S_IFIFO: return 0;
    case S_IFREG: return 0;
    case S_IFDIR: return 1;
    case S_IFLNK: return 0;
    case S_IFSOCK: return 0;
    }
}

int flag_upr(char *str, int nb)
{
    struct dirent *read;
    DIR *dir;
    struct stat total;
    char *new;
    if (nb == 0)
        mini_printf("%s:\n", str);
    nb += 1;
    my_ls(opendir(str));
    dir = opendir(str);
    while ((read = readdir(dir)) != 0) {
        new = my_strcat(my_strcat(str, "/"), read->d_name);
        stat(new , &total);
        if (good_dir(total) == 1 && read->d_name[0] != '.') {
            mini_printf("\n./%s:\n", read->d_name);
            flag_upr(new, nb);
        }
    }
    closedir(dir);
    return 0;
}

int flag_uprl(char *str, int nb)
{
    struct dirent *read;
    DIR *dir;
    struct stat total;
    char *new;
    if (nb == 0)
        mini_printf("%s:\n", str);
    nb += 1;
    flag_l(str);
    dir = opendir(str);
    while ((read = readdir(dir)) != 0) {
        new = my_strcat(my_strcat(str, "/"), read->d_name);
        stat(new, &total);
        if (good_dir(total) == 1 && read->d_name[0] != '.') {
            mini_printf("\n./%s:\n", read->d_name);
            flag_uprl(new, nb);
        }
    }
    closedir(dir);
    return 0;
}
