##
## EPITECH PROJECT, 2019
## C Pool EvalExpr
## File description:
## libmy Makefile
##

CC = gcc

SRC = 	./my_put_nbr.c \
	./my_putchar.c \
	./my_putstr.c \
	./my_strcmp.c \
	./my_strlen.c \
	./my_getnbr.c \
	./my_revstr.c \
	./my_str_to_word_array.c \
	./my_strcat.c \
	./my_strcpy.c \
	./my_strdup.c \
	./binary.c \
	./octal.c \
	./my_str_to_tab.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

HEADERS = my.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp $(HEADERS) ../../include/

clean:
	  rm -f $(OBJ)

fclean: clean
	  rm -f $(NAME)
	  rm -f ../$(NAME)

re: fclean all
