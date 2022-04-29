##
## EPITECH PROJECT, 2021
## makefile
## File description:
## task01
##

src	=	my_putstr.c		\
		my_printf.c		\
		my_strcmp.c		\
		my_strdup.c		\
		my_strcat.c		\
		my_strlen.c		\
		my_putchar.c	\
		my_revstr.c		\
		my_put_nbr.c	\
		my_array_len.c		\
		my_str_to_word_array.c		\

OBJ	=	$(src:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp my.h ../../include/
	cp defender.h ../../include/

clean:
	rm -f $(NAME)
	rm -f *.o
	rm -f lib/my/*.o

fclean: clean
	rm -f $(NAME)
	rm -f libmy.a
	rm -f ../libmy.a

re:	fclean all

auteur:
	echo $(USER) > auteur
