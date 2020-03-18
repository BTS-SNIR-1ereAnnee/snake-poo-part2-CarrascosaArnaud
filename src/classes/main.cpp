#include <iostream>
#include "Point.h"
#include "Board.h"
#include "snake.h"
#include <unistd.h>
using namespace std;

//Définis les touche de mouvement
#define  TOUCHE_KEY_UP 1 
#define  TOUCHE_KEY_DOWN 2
#define  TOUCHE_KEY_LEFT 3
#define  TOUCHE_KEY_RIGHT 4

//Retourne si une touche est appuyée par l'utilisateur
int kbhit(void)
{
	int ch, r;
	nodelay(stdscr, TRUE);
	ch = getch();
	if( ch == ERR)
		r = FALSE;
	else
	{
		r = TRUE;
		ungetch(ch);
	}
	echo();
	nodelay(stdscr, FALSE);
	return(r);
}


int main()
{

	int derniereDir=TOUCHE_KEY_DOWN;//Déplace le serpent vers le bas au lancement
    Board *fenetre;//Crée un pointeur de type board
    fenetre = Board::getInstance ();//Création de l'objet
    snake serpent(10,4);//Création d'un objet de la classe serpentt 
	keypad (stdscr,true);//Permet de faire bouger le snake

	//Boucle de déplacement
	while (true)
	{
		if(kbhit())//Si une touche du clavier est touchée
		{
			switch (getch()){//Prend l'input de l'utilisateur
				case 259:
				derniereDir = TOUCHE_KEY_UP;//Haut
				break;
				case 260:
				derniereDir = TOUCHE_KEY_LEFT;//Gauche
				break;
				case 258:
				derniereDir = TOUCHE_KEY_DOWN;//Bas
				break;
				case 261:
				derniereDir = TOUCHE_KEY_RIGHT;//Droite
				break;
			}
			serpent.move (derniereDir);

		}else{//Pour que le serpent bouge sans avoir à appuyer sur une touche
			serpent.move (derniereDir);
		}

		serpent.affichSerpent();//Affiche le serpent
		usleep (150000);//Temps de délai en micro secondes
	}
	
	fenetre->kill();
	return 0;
};
