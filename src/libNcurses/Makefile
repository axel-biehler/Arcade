##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=	libNcurses.cpp		\

OBJ		=	$(SRC:.cpp=.o)

NAME	=	arcade_ncurses.so

all:	$(NAME)

CFLAGS	=		-c -Wall -Werror -Wextra -fpic -I../../includes/

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