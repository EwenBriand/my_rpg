
##
## EPITECH PROJECT, 2021
## makefile bsbsq
## File description:
## makefile
##

src		=	src/main.c		 \
			src/button.c		\
			src/clickable_btn.c		\

NAME	=	my_rpg

CPPFLAGS 	=	-I include/

LDFLAGS 	=	-L ./lib/ -lmy

LIB 		= 	libmy.a

all:	$(NAME)

$(NAME): 	$(LIB) $(OBJ)
	gcc $(src) -o $(NAME) $(CPPFLAGS) $(LDFLAGS) -l csfml-system -lcsfml-graphics -lcsfml-audio -lcsfml-window -g3

$(LIB):
		make -C lib/my/

clean:
		make -C lib/my/ clean
		rm -f *.o
		rm -f lib/my/*.o

fclean: clean
		rm -f $(NAME)
		rm -f ./lib/$(LIB)
		rm -f ./lib/my/$(LIB)
		rm -f *~

re:	fclean all

.PHONY : all clean flcean repasswd
