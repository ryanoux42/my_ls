/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** projet cpe 1
*/

#ifndef MY_H_

    #define MY_H_
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <dirent.h>
    #include <stdlib.h>
    #include <stdarg.h>

int my_put_tab(char **tab);
char **bring_order(char **tab, int nb);
void my_swap(char **a, char **b);
int get_nbdir(DIR *dir);
void  my_putchar(char c);
int  my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int mini_printf(const char* format, ...);

#endif /* MY_H_ */
