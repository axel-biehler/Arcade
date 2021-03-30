##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

graphicals:
	cd src/libNcurses && make
	cd src/libSDL && make
	cd src/libSFML && make

games:
	cd src/Pacman && make
	cd src/Snake && make

core:
	cd src/Core && make

all: games graphicals core

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