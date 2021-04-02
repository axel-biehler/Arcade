##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=	libSFML.cpp		\

OBJ		=	$(SRC:.cpp=.o)

NAME	=	arcade_sfml.so

all:	$(NAME)

CFLAGS	=		-c -Wall -Werror -Wextra -fpic

LFLAGS  =		-shared

$(NAME):	$(OBJ)
	g++ $(CFLAGS) $(SRC)
	g++ -o $(NAME) $(LFLAGS) $(OBJ) -lsfml-graphics -lsfml-window -lsfml-system
	mv $(NAME) ../../lib

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f ../../lib/$(NAME)

re:	fclean all