#ifndef MEMENTO_H
#define MEMENTO_H

#include <QVector>
#include <QStack>
#include "Donnee.h"


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
