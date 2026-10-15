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

void  my_putchar(char c);
char *my_strcat(char *dest, char const *src);
int  my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int mini_printf(const char* format, ...);
int my_ls(DIR *dir);
int flag_l(char *str);

#endif /* MY_H_ */
