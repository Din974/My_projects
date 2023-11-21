##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

CC = gcc

SRC =	./main.c \
	./error.c \
	./giantman.c \
	./decompress_ppm.c \
	./decompress_lyrics.c \
	./my_strcat_char.c \
	./decompress_html.c

OBJ = $(SRC:.c=.o)

CFLAGS = -I../include/ -W -Wall -Wextra -Werror $(DBFLAGS)

LDFLAGS = -L../lib/my -lmy

DBFLAGS = -g -g3 -ggdb

NAME = giantman

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
