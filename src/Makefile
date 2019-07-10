##
## EPITECH PROJECT, 2019
## MUL_my_defender_2018
## File description:
## Makefile
##

SRC=	src/game/game.c \
	src/game/enemy.c \
	src/main.c \
	src/map/creat_map.c \
	src/map/draw_map.c \
	src/menu/main_menu.c \
	src/menu/options.c \
	src/menu/pause.c \
	src/my_lib/char_add_in_str.c \
	src/my_lib/my_realloc.c \
	src/my_lib/my_strlen.c \
	src/my_lib/str_to_word_array.c \
	src/sfx/buttons.c \
	src/sfx/rectangle.c \
	src/sfx/text.c

NAME =	my_defender

OBJ=	$(SRC:.c=.o)

$(NAME):	$(OBJ)
	cc $(OBJ) -o $(NAME) -l csfml-graphics -l csfml-system -l csfml-window -lm -w -g -I

all: 	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
