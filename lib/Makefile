##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## book strap
##

SRC = mini_printf.c\
	my_put_nbr.c\
	my_putstr.c\
	my_strlen.c\
	my_putchar.c\
	normal_ls.c\
	flag_a.c\
	flag_l.c\
	flag_upr.c\
	my_strcat.c\

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm *.o

fclean: clean
	rm $(NAME)

re: clean all

.PHONY: re fclean clean all
