##
## EPITECH PROJECT, 2021
## Myscreensaver
## File description:
## Makefile
##

SRC =	binary.c \
	min_hexa.c \
	my_printf.c \
	my_putchar.c \
	my_put_nbr.c \
	my_putstr.c \
	my_revstr.c \
	my_strdup.c \
	my_strlen.c \
	octal.c \
	my_getnbr.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

FLAG = -W -Werror -g3 -Wall -Wextra -I .

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
