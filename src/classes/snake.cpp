#include "Point.h"
#include "snake.h"
#include "Board.h"
#include <iostream>


using namespace std ;

//Constructeur par défaut
snake::snake()
{
    for(int i = 0; i < taille; i++)
    {
        serpent[i].setPoint(0,i);
    }
}

//Constructeur avec paramètres
snake::snake(int x,int y)
{
    for(int i = 0; i < taille; i++)
    {
        serpent[i].setPoint(x,i+y);
    }
}

//Affiche le serpent
void snake::afficheSerpent()
{
    for(int i = 0; i < taille; i++)//Boucle défilant la taille du serpent
    {
        serpent[i].drawPoint(); //Utilise la méthode drawPoint
    }
}

//Déplace le serpent
void snake::move(int direction)
{
    for(int i = taille; i > 0 ; i--)//Boucle défilant à l'envers la taille du serpent
    {
        serpent[i].erasePoint();
        serpent[i] = serpent[i-1];

    }

    if(direction == 1)
    {
        serpent[0].moveUp();
    }

    else if(direction == 2)
    {
        serpent[0].moveDown();
    }
    else if(direction == 3)
    {
        serpent[0].moveLeft();
    }
    else if(direction == 4)
    {
        serpent[0].moveRight();
    }

}

//Arrête le jeu quand le serpent touche un bord
bool snake::collisionBord(){
    Board *b;
    b = Board::getInstance(); 
    if(serpent[0].getX() == 0 || serpent[0].getY() == 0 || serpent[0].getX() == b->getSizeX()-1 || serpent[0].getY() == b->getSizeY()-1)
        return TRUE;

    return FALSE;
}

//Arrête le jeu quand le serpent se touche lui même
bool snake::collisionSerpent(){

    for(int i=1;i<taille;i++)
    {
        if(serpent[0].getX()==serpent[i].getX() && serpent[0].getY()==serpent[i].getY()){
            return TRUE;
        }
    }
    return FALSE;
}