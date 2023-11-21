##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## final_stumper
##

SRC =		main.c					\
			./src/search_square.c		\
		./src/fill_x_empty.c			\
		./src/int_array.c			\
		./src/print_greater_square.c		\
		./src/print_res.c

LIB =		./lib/my_putchar.c		\
		./lib/my_putstr.c		\
		./lib/my_getnbr.c		\
		./lib/my_strlen.c		\
		./lib/my_char_isalpha.c		\
		./lib/my_char_isnum.c		\
		./lib/my_str_to_word_array.c

SRC_TESTS =

OBJ =		$(SRC:.c=.o)

NAME =		bsq

NAME_TESTS =	unit_test

IFLAGS	=	-I include -g -g3 -ggdb

CRIFLAGS = -lcriterion --coverage

all:
		gcc -o $(NAME) $(SRC) $(IFLAGS) $(LIB)

tests_run:
		gcc -o $(NAME_TESTS) $(SRC_TESTS) $(IFLAGS) $(CRIFLAGS)
		./$(NAME_TESTS)
		gcovr
clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -f $(NAME)
		rm -f $(NAME_TESTS)

re:		fclean all
