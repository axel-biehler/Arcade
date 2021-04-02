##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=	libSFML.cpp						\
			../utils/Text/Text.cpp			\

OBJ		=	$(SRC:.cpp=.o)

NAME	=	arcade_sfml.so

all:	$(NAME)

CFLAGS	=		-c -Wall -Werror -Wextra -fPIC

LFLAGS  =		-shared -lsfml-graphics -lsfml-window -lsfml-system -lstdc++fs

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