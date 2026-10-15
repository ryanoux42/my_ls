##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## task01
##

SRC = my_ls.c\
	no_after.c\
	manage.c\
	bonus/flag_r.c\
	bonus/flag_t.c\
	bonus/my_swap.c\
	bonus/basic_ls.c\

OBJ = $(SRC:.c=.o)

NAME = my_ls

all : $(NAME)

$(NAME) :	$(OBJ)
	make -C lib
	gcc -o $(NAME) $(OBJ) -L./lib -lmy

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

tests_run:
	gcc $(SRC) $(TSRC) --coverage -lcriterion -o unit_tests

.PHONY: re fclean clean all tests_run
