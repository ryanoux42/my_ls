/*
** EPITECH PROJECT, 2022
** basic_ls
** File description:
** my_ls
*/
#include "my.h"
#include "../ls.h"

int nothing(void)
{
    return 0;
}

int check_dir(char *str, struct flag pass)
{
    DIR *dir = opendir(str);
    int ok = 0;
    struct stat total;

    if (dir == NULL) {
        stat(str, &total);
        switch (total.st_mode & S_IFMT) {
        case S_IFREG: manage_file(str, pass);ok = 1;closedir(dir);break;
        }
        if (ok == 0) {
            mini_printf("ls: cannot access '%s'", str);
            my_putstr(": No such file or directory\n");
            closedir(dir);
            exit (84);
        }
        return 0;
    }
    closedir(dir);
    return 1;
}

int my_ls(DIR *dir)
{
    struct dirent *read;
    while ((read = readdir(dir)) != 0) {
        if (read->d_name[0] != '.') {
            mini_printf("%s\n",read->d_name);
        }
    }
    closedir(dir);
    return 0;
}
