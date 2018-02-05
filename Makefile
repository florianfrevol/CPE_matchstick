##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## 
##

SRC	=	sources/src.c	\
		sources/mathstick.c\
		sources/getnbr.c\
		sources/create_game.c\
		sources/play_game.c\
		sources/game.c\
		sources/ia_turn.c

CFLAGS	=	-W -Wextra -Wall -I lib -I sources

OBJ	=	$(SRC:.c=.o)

NAME	=	 matchstick

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all