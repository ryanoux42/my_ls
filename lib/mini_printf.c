/*
** EPITECH PROJECT, 2022
** mini_printf.c
** File description:
** projet
*/
#include "my.h"

int len_di(const char* format, int nb)
{
    int len = 0;
    if (nb < 0)
        nb = nb * -1;
    while (nb > 0) {
        nb = nb / 10;
        len += 1;
    }
    return len;
}

int display(const char* format, int i, va_list list)
{
    int count = 0;
    char *temp;
    int tempd;
    int tempi;
    switch (format[i]) {
    case 's': temp = va_arg(list,char*);
        my_putstr(temp);count = my_strlen(temp);break;
    case 'c': my_putchar(va_arg(list,int));
        count = 1;break;
    case 'd': tempd = va_arg(list,int);
        my_put_nbr(tempd);
        count = len_di(format,tempd);break;
    case 'i': tempi = va_arg(list,int);
        my_put_nbr(tempi);
        count = len_di(format,tempi);break;
    case '%': my_putchar('%');break;
    }
    return count;
}

int mini_printf(const char* format, ...)
{
    va_list list;
    int i = 0;
    int size = 0;
    va_start(list, format);
    while (format[i] != '\0') {
        if (format[i - 1] == '%') {
            size += display(format,i,list);
            i = i + 1;
        }
        if (format[i] != '%')
            my_putchar(format[i]);
        i = i + 1;
    }
    va_end(list);
    return size;
}
