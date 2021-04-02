##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=	libSDL.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME	=	arcade_sdl2.so

all:	$(NAME)

CFLAGS	=		-c -Wall -Werror -Wextra -fpic sdl2-config --libs --cflags` -ggdb3 -O0 --std=c99 -Wall -lSDL2_image -lm

LFLAGS  =		-shared

$(NAME):	$(OBJ)
	g++ $(CFLAGS) $(SRC)
	g++ -o $(NAME) $(LFLAGS) $(OBJ)
	mv $(NAME) ../../lib

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f ../../lib/$(NAME)

re:	fclean all