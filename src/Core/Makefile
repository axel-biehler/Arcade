##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=	Core.cpp								\
			../main.cpp								\
			../utils/LibLoader/LibLoader.cpp		\
			../utils/Menu/menu.cpp					\
			../utils/Text/Text.cpp					\

OBJ		=	$(SRC:.cpp=.o)

NAME	=	arcade

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) -Wall -Wextra -Werror $(OBJ) -ldl -lstdc++fs
	mv $(NAME) ../../

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f ../../$(NAME)

re:	fclean all