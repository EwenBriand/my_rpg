##
## EPITECH PROJECT, 2021
## Project Name
## File description:
## my Makefile
##

SRC	=	src/init_my_game.c	\

OBJ	=	$(SRC:.c=.o)

MAIN	=	main.c

PLACE	=	lib/

LDFLAGS	=	-L lib/ -lmy

CPPFLAGS	=	-I ./include

CFLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

NAME	=	my_rpg

all:	$(NAME)

$(NAME):	makelib $(OBJ)
	gcc $(MAIN) $(SRC) $(MY) -o $(NAME) $(LDFLAGS) $(CPPFLAGS) $(CFLAGS)

makelib:
	$(MAKE) -C $(PLACE)

clean:
	rm -rf *~
	rm -rf *.o

fclean: clean
	rm $(NAME)
	rm -rf *.a
	$(MAKE) -C $(PLACE) fclean

re: fclean makelib all

unitest: CFLAGS += -lcriterion
unitest:
	gcc -o $(NAME) $(CPPFLAGS) $(LDFLAGS) $(CFLAGS)

debug: CFLAGS += -g3 -Wall -Wextra
debug: all

.PHONY: all makelib clean fclean re unitest debug
