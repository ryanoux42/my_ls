/*
** EPITECH PROJECT, 2022
** bsmyls
** File description:
** bs
*/
#include "ls.h"

struct flag check_flag(char *str, struct flag pass)
{
    int j = 1;

    while (j < my_strlen(str)) {
        if (str[j] == 'a')
            pass.a = 1;
        if (str[j] == 'l')
            pass.l = 1;
        if (str[j] == 'R')
            pass.upr = 1;
        if (str[j] != 'a' && str[j] != 'l' && str[j] != 'R'
            && str[j] != 'd' && str[j] != 'r' && str[j] != 't')
            pass.error = 1;
        j += 1;
    }
    return pass;
}

struct flag find(int ac, char **av)
{
    int i = 0;
    struct flag pass;
    pass.a = 0;
    pass.l = 0;
    pass.error = 0;

    while (i < ac) {
        if (av[i][0] == '-') {
            pass = check_flag(av[i], pass);
        }
        i += 1;
    }
    return pass;
}

int main(int ac, char** av)
{
    struct flag pass;
    int no = 0;

    if (ac == 1) {
        my_ls(opendir("."));
    }
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'd' && my_strlen(av[1]) == 2)
        mini_printf("%c\n", '.');
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'r' && my_strlen(av[1]) == 2)
        flag_r();
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 't' && my_strlen(av[1]) == 2)
        flag_t();
    pass = find(ac, av);
    if (pass.error == 1)
        return 84;
    no = no_after(ac, av);
    if (no == 1)
        return current_dir(pass);
    return manage(ac, av, pass);
}
