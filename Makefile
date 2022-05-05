##
## EPITECH PROJECT, 2021
## Project Name
## File description:
## my Makefile
##

SRC	=	src/init_all/init_game.c	\
		src/init_all/init_map.c	\
		src/init_all/init_charter.c	\
		src/init_all/init_rect.c	\
		src/init_all/init_sprite.c	\
		src/init_all/init_pnjs.c	\
		src/init_all/init_pnj2.c	\
		src/init_all/init_perso.c	\
		src/init_all/init_object.c	\
		src/init_all/init_pnj_scene.c	\
		src/init_all/init_all_particule.c \
		src/init_all/create_stat.c \
		src/event/event.c	\
		src/event/event_pnj.c	\
		src/move/move_charter.c		\
		src/move/move_cam.c		\
		src/move/update.c		\
		src/interaction/interaction.c	\
		src/interaction/all_interaction.c	\
		src/interaction/pnj1.c	\
		src/interaction/pnj2.c	\
		src/interaction/pnj3.c	\
		src/interaction/pnj4.c	\
		src/interaction/pnj5.c	\
		src/inventaire/add.c	\
		src/inventaire/del.c	\
		src/inventaire/is_in.c	\
		src/draw/draw_map.c	\
		src/level_up.c	\
		src/change_map/change_map.c	\
		src/destructor/destroy_sprite.c	\
		src/destructor/destroy_map.c	\
		src/destructor/destroy_pnj.c	\
		src/destructor/destroy_pnj_scene.c	\
		src/destructor/destroy_perso.c	\
		src/destructor/destroy_objet.c	\
		src/destructor/destroy_particule.c	\
		src/destructor/destroy_game.c	\
		src/destructor/destroy_charter.c	\
		src/shop/open_shop.c \
		src/shop/init_shop.c \
		src/shop/create_spritebis.c \
		src/shop/display.c \
		src/start_game.c \
		src/menu/button.c \
		src/menu/clickable_btn.c \
		src/pause_menu/pause_menu.c \
		src/my_big_effect.c \
		src/fight/my_fight.c \
		src/fight/draw_fight.c \
		src/fight/mob_turn.c \
		src/fight/player_turn.c \
		src/fight/player_event.c \
		src/fight/print_turn_result.c \
		src/init_all/init_fight.c \
		src/fight/event_result.c \
		src/fight/fight_slash.c \
		src/init_all/create_slash.c \
		src/fight/fight_smoke.c \
		src/fight/dmg_deal.c \
		src/destructor/destroy_fight.c \
		src/destructor/destroy_shop.c \

OBJ	=	$(SRC:.c=.o)

MAIN	=	main.c

PLACE	=	lib/

LDFLAGS	=	-L lib/ -lmy

CPPFLAGS	=	-I ./include

CFLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -lm

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
	rm $(OBJ)
	$(MAKE) -C $(PLACE) fclean

re: fclean makelib all

unitest: CFLAGS += -lcriterion
unitest:
	gcc -o $(NAME) $(CPPFLAGS) $(LDFLAGS) $(CFLAGS)

debug: CFLAGS += -g3 -Wall -Wextra
debug: all

.PHONY: all makelib clean fclean re unitest debug
