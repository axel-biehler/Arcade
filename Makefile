##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=	src/main.cpp							\
			src/LibLoader/LibLoader.cpp				\
			src/menu.cpp							\
			src/Core/Core.cpp						\

OBJ		=	$(SRC:.cpp=.o)

NAME	=	arcade

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) -Wall -Wextra -Werror $(OBJ) -ldl -lstdc++fs

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all