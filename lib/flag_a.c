/*
** EPITECH PROJECT, 2022
** basic_ls
** File description:
** my_ls
*/
#include "my.h"

int flag_a(DIR *dir)
{
    struct dirent *read;

    while ((read = readdir(dir)) != 0) {
        mini_printf("%s\n", read->d_name);
    }
    closedir(dir);
    return 0;
}
