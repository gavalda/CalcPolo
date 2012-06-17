#ifndef COLLECTIONPILE_H
#define COLLECTIONPILE_H

///
/// \file CollectionPile.h
/// \author Clémence BLOT, Benoît GAVALDA
/// \brief CollectionPile contient la classe CollectionPile qui herite de vector et contient les piles pour ctrl + Z/ctrl + Y (undo/redo) et les onglets
///
///
///

#include <vector>
#include "Pile.h"
#include <QString>



/// \class CollectionPile CollextionPile.h
/// \param instance l'instance unique de notre Collection
/// \param actif rang de la pile active

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

