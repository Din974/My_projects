##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## pushswap
##

SRC =		main.c	\
			./src/init_tab.c	\
			./src/matchstick.c	\
			./src/useful.c	\
			./src/ask_player.c	\
			./src/players.c	\
			./src/random_int.c

LIB =		./lib/my_str_isnum.c	\
			./lib/my_printf			\
			./lib/my_getnbr.c

SRC_TESTS =

OBJ =		$(SRC:.c=.o)

NAME =		matchstick

NAME_TESTS =	unit_test

IFLAGS	=	-I include -g -g3 -ggdb

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
