##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

CC = gcc

SRC =	./main.c \
	./error.c \
	./antman.c \
	./my_put_in_list.c \
	./compress_lyrics.c \
	./compress_ppm.c \
	./compress_html.c

OBJ = $(SRC:.c=.o)

CFLAGS = -I../include/ -W -Wall -Wextra $(DBFLAGS)

LDFLAGS = -L../lib/my -lmy

DBFLAGS = -g -g3 -ggdb

NAME = antman

all: $(NAME)

$(NAME): libmy $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

libmy:
	make -C ../lib/my all

clean:
	rm -f $(OBJ)
	make -C ../lib/my/ clean

fclean: clean
	rm -f $(NAME)
	make -C ../lib/my/ fclean

re: fclean all
