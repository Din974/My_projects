##
## EPITECH PROJECT, 2019
## my_printf
## File description:
## libmy Makefile
##

CC = gcc

SRC = 	conv_base.c		\
		my_printf.c		\
		my_put_nbr.c	\
		my_putchar.c	\
		my_putstr.c		\
		my_revstr.c		\
		my_strlen.c		\
		my_putstr_oct.c	\
		my_put_adress.c		\
		print.c
OBJ = $(SRC:.c=.o)

NAME = libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
