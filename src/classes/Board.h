/**

Classe de gestion du plateau de jeu
Implémentée selon le pattern singleton
Pré-requis: installer la librairie ncurse
*/

#ifndef BOARD_H
#define BOARD_H

#include <ncurses.h>
#include "Point.h"
class Point;
class Board
{
public:
    static Board *getInstance ();
    static void kill ();
    void dessinerPoint(Point &p);
    void effacerPoint(Point &p);
    int getSizeX() const;
    int getSizeY() const;
private:
    static Board *_singleton;
    WINDOW *m_boite;
    Board();
    ~Board();
    void dessinerPlateau();
    int m_sizeX;
    int m_sizeY;

};



#endif // BOARD_H
