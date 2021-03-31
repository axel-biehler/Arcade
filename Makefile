##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

all: core games graphicals

graphicals:
	#cd src/libNcurses && make
	#cd src/libSDL && make
	make -C src/libSFML

games:
	#cd src/Pacman && make
	#cd src/Snake && make

core:
	make -C src/Core

clean:
	cd src/libNcurses && make clean
	cd src/libSDL && make clean
	cd src/libSFML && make clean
	cd src/Pacman && make clean
	cd src/Snake && make clean
	cd src/Core && make clean

fclean:
	cd src/libNcurses && make fclean
	cd src/libSDL && make fclean
	cd src/libSFML && make fclean
	cd src/Pacman && make fclean
	cd src/Snake && make fclean
	cd src/Core && make fclean

re:	fclean all

.PHONY:	graphicals games core all clean fclean re