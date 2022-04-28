##
## EPITECH PROJECT, 2021
## Myscreensaver
## File description:
## Makefile
##

SRC = 	main.c

OBJ = $(SRC:.c=.o)

NAME = my_rpg

LIB	= -L./lib/my -lmy
LIB	+= -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

FLAG	= -W -Werror -Wall -Wextra
FLAG	+= -I ./include
FLAG	+= -g3 -O3

all:	$(NAME)

$(NAME): $(OBJ)
	make -C lib/my
	gcc $(OBJ) -o $(NAME) $(FLAG) $(LIB)

clean:
	make -C lib/my clean
	rm -f $(OBJ);

fclean:	clean
	make -C lib/my fclean
	rm -f $(NAME)

re: fclean all
