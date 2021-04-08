##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=	libNcurses.cpp		\
			../utils/Text/Text.cpp			\
			../utils/Pixel/Pixel.cpp		\

OBJ		=	$(SRC:.cpp=.o)

NAME	=	arcade_ncurses.so

all:	$(NAME)

CFLAGS	=		-c -Wall -Werror -Wextra -fPIC -I../../includes/

LFLAGS  =		-shared -lncurses

$(NAME):	$(OBJ)
	g++ $(CFLAGS) $(SRC)
	g++ -o $(NAME) $(LFLAGS) *.o
	mv $(NAME) ../../lib

clean:
	rm -f $(OBJ)
	rm -f *.o

fclean:	clean
	rm -f ../../lib/$(NAME)

re:	fclean all