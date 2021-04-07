# Projet Arcade 
Le projet Arcade à pour but de créer une borne d'arcade avec au moins deux jeux et un système de chargement dynamique de 3 différentes librairies graphique pendant le runtime.

## Libraries utilisé pour le projet:
- Ncurses
- SFML
- SDL

## Les jeux développés:
- Snake
- Pacman

## Utilisation:
```
>$ make
>$ ./arcade lib/dynamic_librairy.so
```

# Documentation
## IGraphic interface:
- ### void DrawPixel(Pixel *pixel)
  Cette fonction prend en paramètre une variable Pixel et permet de dessiner un carré de pixel d'une taille, une position et une couleur donnée.

- ### void drawText(Text *text)
  Cette fonction prend en paramètre une variable Text et permet d'afficher un texte en choisissant sa position et sa taille.

- ### void myClear();
  Cette fonction permet de clear l'écran entre chaque boucle de jeux.

- ### void myRefresh();
  Cette fonction permet de rafraîchir les données et les mettre à jour sur l'écran.

- ### Arcade::CommandType getInput()
  Cette fonction permet de récupérer les données saisies sur le clavier par l'utilisateur et retourne un Arcade::CommandeType.

## IGame interface:
- ### void draw()
  Permet de dessiner les changement effectué durant la boucle de jeu.
- ### void getInput()
  Permet de recevoir les input clavier du joueur.

- ### void update(double timeElapsed)
  Permet de faire la mise à jour des valeurs entre chaque boucle de jeux et prend en paramètre un double indiquant le temps écoulé en un tour de boucle.

- ### void remake()
  Permet de relancer le jeux en commencant une nouvelle partie.

## Contact:
  nicolas.schneider@epitech.eu
