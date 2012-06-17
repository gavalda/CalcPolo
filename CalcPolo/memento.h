#ifndef MEMENTO_H
#define MEMENTO_H

#include <QVector>
#include <QStack>
#include "Donnee.h"


/// \file Memento.h
/// \author Clémence BLOT, Benoît GAVALDA
/// \brief Memento Comprend les méthodes nécessaire à la réalisation de undo/redo.
///
/// \param currentStack Pile courante
/// \param tabPile tableau de pile de type QVector qui permet de garder en mémoire les précédentes piles.
///


class Pile;

class Memento
{
    int currentStack;
    QVector <Pile*> tabPile;

public:
    Memento();
    Pile* undo();
    ~Memento();
    Pile* redo();
    void addMemoire(Pile* pile);
};

#endif // MEMENTO_H
