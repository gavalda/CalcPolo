#ifndef COLLECTIONPILE_H
#define COLLECTIONPILE_H


#include <vector>
#include "Pile.h"
#include <QString>

//Design Pattern creation de piles pour le  undo redo et les onglets

class CollectionPile :public std::vector<Pile *>  //vector de Pile
{
    static CollectionPile * instance;
    int actif;
    CollectionPile (const CollectionPile& other);
    ~CollectionPile(){}
    CollectionPile():actif(0){}
    CollectionPile operator =(const CollectionPile);

public:
    static CollectionPile& getInstance();
    static void releaseInstance();
    void addPile (Pile * p);
    void setActif (int a){actif=a;}   //change la pile active
    int getActif (){return actif;}


};
#endif // COLLECTIONPILE_H

