# snake
Jeu de snake en console POO

# pré-requis

installer la librairie libncurse5
```
sudo apt-get install libncurses5-dev libncursesw5-dev
```
# Compiler le programme 
```
g++ main.cpp snake.cpp Point.cpp Board.cpp -l ncurses -o bin/test-sanke
```
--------

# Développement
**Chaque question fera l'objet d'au mois un commit**

**Chaque methode devra être commentée dans le .h , sur le modèle des commentaires de la classe Point** 

## Q1: compiler et tester le comportement

## Q2: indenter et commenter le main.cpp

## Q3: gérer les collisions avec les bords

1. Q3.1    ajouter 2 variables membres privées à classe board: m_sizeX et m_sizeY
2. Q3.2    faire les getter de ces 2 attributs
3. Q3.3 initialiser les 2 attributs dans le constructeur de la classe Board
4. Q3.4 créer une methode "bool checkColisionWithBoard()" dans la classe snake. Cette methode devra renvoyer true en cas de collision
5. Q3.5 modifier le programme principal pour sortir de la boucle `while(true){}` en cas de collision avec le bord du plateau

## Q4 gérer les collisions avec le corps du serpent

1. Q4.1 créer une methode "bool checkColisionWithSnake()" dans la classe snake. Cette methode devra renvoyer true en cas de collision de la tête avec le corps. (inspirez vous de la methode d'affichage du serpent.
2. Q4.2 modifier le programme principal pour sortir de la boucle `while(true){}` en cas de collision avec le bord du plateau **ou** avec le serpent.

## Q5 Evolution de la classe Point

Pour le moment notre classe Point ne peut afficher que des * nous allons la faire évoluer pour pouvoir choisir le caractère à afficher.
1. Q5.1 Ajouter un attribut de type `char` nommé m_caractere.
2. Q5.2 Créez les accesseurs et mutateurs associés
3. Q5.3 Modifiez les constructeurs existants pour que `m_caractere` soit initialisé par défaut à *
4. Q5.4 Ajoutez un constructeur permetant d'initialiser `m_caractere` à une valeur choisie.
5. q5.5 Créez un fichier testPoint.cpp pour tester votre classe en affichant un @ par exemple.
6. Q5.6 Modifier la méthode `afficherPoint(Point &p)` de la classe Board pour afficher le carractère du point passé en paramètre.
