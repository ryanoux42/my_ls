/*
** EPITECH PROJECT, 2022
** basic_ls
** File description:
** my_ls
*/
#include "my.h"
#include <pwd.h>
#include <grp.h>
#include <time.h>

int print_time(char *str)
{
    int i = 4;

    while (i < 16) {
        my_putchar(str[i]);
        i += 1;
    }
    return 0;
}

int permission(struct stat total)
{
    switch (total.st_mode & S_IFMT) {
    case S_IFBLK: my_putchar('b');break;
    case S_IFCHR: my_putchar('c');break;
    case S_IFIFO: my_putchar('p');break;
    case S_IFREG: my_putchar('-');break;
    case S_IFDIR: my_putchar('d');break;
    case S_IFLNK: my_putchar('l');break;
    case S_IFSOCK: my_putchar('s');break;
    }
    (total.st_mode & S_IRUSR) ? my_putchar('r') : my_putchar('-');
    (total.st_mode & S_IWUSR) ? my_putchar('w') : my_putchar('-');
    (total.st_mode & S_IXUSR) ? my_putchar('x') : my_putchar('-');
    (total.st_mode & S_IRGRP) ? my_putchar('r') : my_putchar('-');
    (total.st_mode & S_IWGRP) ? my_putchar('w') : my_putchar('-');
    (total.st_mode & S_IXGRP) ? my_putchar('x') : my_putchar('-');
    (total.st_mode & S_IROTH) ? my_putchar('r') : my_putchar('-');
    (total.st_mode & S_IWOTH) ? my_putchar('w') : my_putchar('-');
    (total.st_mode & S_IXOTH) ? my_putchar('x') : my_putchar('-');
    return 0;
}

int flag_l(char *str)
{
    DIR *dir = opendir(str);
    struct dirent *read;
    struct passwd *user;
    struct group *group;
    struct stat total;char *new;
    while ((read = readdir(dir)) != 0) {
        if (read->d_name[0] != '.') {
            new = my_strcat(my_strcat(str, "/"), read->d_name);
            stat(new , &total);
            user = getpwuid(total.st_uid);
            group = getgrgid(total.st_gid);
            permission(total);
            mini_printf(". %d %s ", total.st_nlink, user->pw_name);
            mini_printf("%s %d ", group->gr_name, total.st_size);
            print_time(ctime(&total.st_mtime));
            mini_printf(" %s\n", read->d_name);
        }
    }
    closedir(dir);
    return 0;
}

int flag_la(char *str)
{
    DIR *dir = opendir(str);
    struct dirent *read;
    struct passwd *user;
    struct group *group;
    struct stat total;
    char *new;

    while ((read = readdir(dir)) != 0) {
        new = my_strcat(my_strcat(str, "/"), read->d_name);
        stat(new , &total);
        user = getpwuid(total.st_uid);
        group = getgrgid(total.st_gid);
        permission(total);
        mini_printf(". %d %s ", total.st_nlink, user->pw_name);
        mini_printf("%s %d ", group->gr_name, total.st_size);
        print_time(ctime(&total.st_mtime));
        mini_printf(" %s\n", read->d_name);
    }
    closedir(dir);
    return 0;
}
