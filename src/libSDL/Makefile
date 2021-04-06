##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=	libSDL.cpp						\
			../utils/Text/Text.cpp			\
			../utils/Pixel/Pixel.cpp		\

OBJ		=	$(SRC:.cpp=.o)

NAME	=	arcade_sdl2.so

all:	$(NAME)

CFLAGS	=		-c -Wall -Werror -Wextra -fPIC

LFLAGS  =		-shared -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lstdc++fs

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