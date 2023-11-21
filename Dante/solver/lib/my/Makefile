##
## EPITECH PROJECT, 2020
## B-CPE-200-RUN-2-1-dante-luidgi.parinet
## File description:
## Makefile
##

SRC    =    $(wildcard *.c)

OBJ     =     $(SRC:.c=.o)

NAME    =    libmy.a

CFLAGS    =    -g

LFLAGS     =     I-     -include/

LFLAGS    =    -L lib/ -lmy

all : $(OBJ)
		ar rc $(NAME) $(OBJ)
clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:    fclean all