/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** projet cpe 1
*/

#ifndef LS_H_

    #define LS_H_
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <dirent.h>
    #include <stdlib.h>

struct flag{
    int a;
    int l;
    int upr;
    int error;
};

int manage(int ac, char** av, struct flag pass);
int nothing(void);
int no_after(int ac, char **av);
int check_dir(char *str, struct flag pass);
int my_strlen(char const *str);
int current_dir(struct flag pass);
int flag_upr(char *str, int nb);
int flag_uprl(char *str, int nb);
int flag_a(DIR *dir);
int my_ls(DIR *dir);
int flag_l(char *str);
int flag_la(char *str);
int flag_r(void);
int flag_t(void);
int mini_printf(const char* format, ...);
int print_time(char *str);
int permission(struct stat total);
int manage_file(char *str, struct flag pass);

#endif /* LS_H_ */
