##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## generator
##

SRC    =    $(wildcard *.c)	\
			$(wildcard ./src/*.c)

NAME    =    generator

INC    =    -I include/

CFLAGS    =    -g -ggdb -g3 $(INC)

all : $(OBJ)
		make -C ./lib/my
		gcc -o $(NAME) $(SRC) $(CFLAGS) -I ./include -L ./lib/my -lmy -lm

clean:
		rm -f $(OBJ)

fclean: clean
		make fclean -C ./lib/my
		rm -f $(NAME)

re:    fclean all