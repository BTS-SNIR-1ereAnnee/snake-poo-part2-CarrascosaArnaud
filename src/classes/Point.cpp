#include "Point.h"
#include "Board.h"
#include <iostream>


using namespace std;

Point::Point()
{
    m_x = m_y = 10;
    m_char = '@';
}

Point::Point(int x, int y)
{
    this->m_x = x;
    this->m_y = y;
    m_char = '*';
}

Point::Point(int x, int y, char carac)
{
    this->m_x = x;
    this->m_y = y;
    m_char = carac;
}

Point::Point(char carac)
{
    m_char = carac;
}

void Point::setPoint(int x, int y)
{
    this->m_x = x;
    this->m_y = y;
}



void Point::moveDown()
{
    m_y++;
}


void Point::moveUp()
{
    m_y--;
}


void Point::moveRight()
{
    m_x++;
}


void Point::moveLeft()
{
    m_x--;
}


int Point::getX() const
{
    return m_x;
}


void Point::setX(int val)
{
    m_x = val;
}


int Point::getY() const
{
    return m_y;
}


void Point::setY(int val)
{
    m_y = val;
}

//Dessine les points
void Point::drawPoint()
{
    Board *b;
    b = Board::getInstance(); 
    b->dessinerPoint(*this);
}

//Efface les points 
void Point::erasePoint()  
{
    Board *b;
    b = Board::getInstance();
    b->effacerPoint(*this);
}

//Envois les coordonnées du point
void Point::debug()
{
    cout << "(" << this->m_x << "," << this->m_y << ")";
}

//Setter de char
void Point::setChar(char carac){
    m_char = carac;
}

//Getter de char
char Point::getChar(){
    return m_char;
}

Point::~Point()
{
    //dtor
}

