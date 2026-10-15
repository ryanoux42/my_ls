/*
** EPITECH PROJECT, 2022
** manage
** File description:
** ls
*/
#include "ls.h"
#include <pwd.h>
#include <grp.h>
#include <time.h>

int manage(int ac, char** av, struct flag pass)
{
    int i = 1;
    while (i < ac) {
        if (av[i][0] != '-' && pass.a == 0 && pass.l == 0 && pass.upr == 0)
            (check_dir(av[i], pass) == 1) ? my_ls(opendir(av[i])) : nothing();
        if (av[i][0] != '-' && pass.a == 1 && pass.l == 0 && pass.upr == 0)
            (check_dir(av[i], pass) == 1) ? flag_a(opendir(av[i])) : nothing();
        if (av[i][0] != '-' && pass.a == 0 && pass.l == 1 && pass.upr == 0)
            (check_dir(av[i], pass) == 1) ? flag_l(av[i]) : nothing();
        if (av[i][0] != '-' && pass.a == 1 && pass.l == 1 && pass.upr == 0)
            (check_dir(av[i], pass) == 1) ? flag_la(av[i]) : nothing();
        if (av[i][0] != '-' && pass.a == 0 && pass.l == 0 && pass.upr == 1)
            (check_dir(av[i], pass) == 1) ? flag_upr(av[i], 0) : nothing();
        if (av[i][0] != '-' && pass.a == 0 && pass.l == 1 && pass.upr == 1)
            (check_dir(av[i], pass) == 1) ? flag_uprl(av[i], 0) : nothing();
        i += 1;
    }
    return 0;
}

int print_infofile(char *str)
{
    struct passwd *user;
    struct group *group;
    struct stat total;

    stat(str, &total);
    user = getpwuid(total.st_uid);
    group = getgrgid(total.st_gid);
    permission(total);
    mini_printf(". %d %s ", total.st_nlink, user->pw_name);
    mini_printf("%s %d ", group->gr_name, total.st_size);
    print_time(ctime(&total.st_mtime));
    mini_printf(" %s\n", str);
    return 0;
}

int manage_file(char *str, struct flag pass)
{
    if (pass.a == 0 && pass.l == 0 && pass.upr == 0)
        mini_printf("%s\n", str);
    if (pass.a == 1 && pass.l == 0 && pass.upr == 0)
        mini_printf("%s\n",str);
    if (pass.a == 0 && pass.l == 0 && pass.upr == 1)
        mini_printf("%s\n", str);
    if (pass.a == 0 && pass.l == 1 && pass.upr == 1)
        print_infofile(str);
    if (pass.a == 0 && pass.l == 1 && pass.upr == 0)
        print_infofile(str);
    if (pass.a == 1 && pass.l == 1 && pass.upr == 0)
        print_infofile(str);
    return 0;
}
