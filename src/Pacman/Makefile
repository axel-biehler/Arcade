##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=	src/Pacman.cpp				\
			src/Character.cpp			\
			src/Ghost.cpp				\
			../utils/Text/Text.cpp		\
			../utils/Pixel/Pixel.cpp	\

OBJ		=	$(SRC:.cpp=.o)

NAME	=	arcade_pacman.so

all:	$(NAME)

CFLAGS	=		-c -Wall -Wextra -fPIC

LFLAGS  =		-shared

$(NAME):	$(OBJ)
	g++ $(CFLAGS) $(SRC)
	g++ -o $(NAME) $(LFLAGS) *.o
	mv $(NAME) ../../lib

clean:
	rm -f $(OBJ)
	rm *.o

fclean:	clean
	rm -f ../../lib/$(NAME)

re:	fclean all