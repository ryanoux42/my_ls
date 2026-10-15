/*
** EPITECH PROJECT, 2022
** no_after
** File description:
** ls
*/
#include "ls.h"

int no_after(int ac, char **av)
{
    int i = 1;

    while (i < ac) {
        if (av[i][0] == '-') {
            i += 1;
        } else {
            return 0;
        }
    }
    return 1;

}

int current_dir(struct flag pass)
{
    if (pass.a == 0 && pass.l == 0 && pass.upr == 0)
        my_ls(opendir("."));
    if (pass.a == 1 && pass.l == 0 && pass.upr == 0)
        flag_a(opendir("."));
    if (pass.a == 0 && pass.l == 1 && pass.upr == 0)
        flag_l(".");
    if (pass.a == 1 && pass.l == 1 && pass.upr == 0)
        flag_la(".");
    if (pass.a == 0 && pass.l == 0 && pass.upr == 1)
        flag_upr(".", 0);
    if (pass.a == 0 && pass.l == 1 && pass.upr == 1)
        flag_uprl(".", 0);
    return 0;
}
