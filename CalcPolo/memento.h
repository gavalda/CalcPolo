#ifndef MEMENTO_H
#define MEMENTO_H

#include <QVector>
#include <QStack>
#include "Donnee.h"


/// \file Memento.h
/// \author Cl�mence BLOT, Beno�t GAVALDA
/// \brief Memento Comprend les m�thodes n�cessaire � la r�alisation de undo/redo.
///
/// \param currentStack Pile courante
/// \param tabPile tableau de pile de type QVector qui permet de garder en m�moire les pr�c�dentes piles.
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
