##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## pushswap
##

SRC =		main.c	\
			./src/usage.c	\
			./src/sokoban.c	\
			./src/key_management.c	\
			./src/useful.c	\
			./src/useful2.c	\
			./src/win_lose.c	\
			./src/move_over_wall.c

LIB =		./lib/my_printf	\
			./lib/my_strcmp.c	\
			./lib/my_str_to_word_array.c

SRC_TESTS =

OBJ =		$(SRC:.c=.o)

NAME =		my_sokoban

NAME_TESTS =	unit_test

IFLAGS	=	-I include -lncurses -g -g3 -ggdb

CRIFLAGS = -lcriterion --coverage

GFLAGS =		-l csfml-graphics -l csfml-system -l csfml-audio

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